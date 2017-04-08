////////////////////////////////////
// @file sound_device.cc
// @brief Sound device class
// @author Mamoru Kaminaga
// @date 2017-04-08 20:22:10
// Copyright 2017 Mamoru Kaminaga
////////////////////////////////////
#include "sound_device.h"
#include <wchar.h>
#include <windows.h>
#include <mmsystem.h>
#include <dsound.h>
#include <memory>
namespace mk {
bool SoundDevice::Initialize() {
  if (FAILED(DirectSoundCreate8(NULL, &direct_sound8_, NULL))) return false;
  if (FAILED(direct_sound8_->SetCooperativeLevel(window_handle_,
                                                 DSSCL_PRIORITY))) {
    return false;
  }
  return true;
}
void SoundDevice::Finalize() {
  if (direct_sound8_) direct_sound8_->Release();
}
bool SoundDevice::CreateWaveDataFromFile(int wave_data_id,
                                         const wchar_t* file_name) {
  if (!SOUND_DEVICE_CHECK_ID(wave_data_id)) return false;
  //
  HMMIO mmio_handle = NULL;
  if ((mmio_handle = mmioOpen((LPWSTR) file_name,  // NOLINT
                              NULL, MMIO_READ)) == NULL) {
    return false;
  }
  //
  MMCKINFO riff_chunk = {0};
  memset(&riff_chunk, 0, sizeof(MMCKINFO));
  riff_chunk.fccType = mmioFOURCC('W', 'A', 'V', 'E');
  if (mmioDescend(mmio_handle, &riff_chunk, NULL, MMIO_FINDRIFF) !=
      MMSYSERR_NOERROR) {
    mmioClose(mmio_handle, 0);
    return false;
  }
  //
  MMCKINFO format_chunk = {0};
  memset(&format_chunk, 0, sizeof(MMCKINFO));
  format_chunk.ckid = mmioFOURCC('f', 'm', 't', ' ');
  if (mmioDescend(mmio_handle, &format_chunk, &riff_chunk, MMIO_FINDCHUNK) !=
      MMSYSERR_NOERROR) {
    mmioClose(mmio_handle, 0);
    return false;
  }
  //
  WAVEFORMATEX wave_fmt_ex = {0};
  memset(&wave_fmt_ex, 0, sizeof(WAVEFORMATEX));
  if (mmioRead(mmio_handle, (HPSTR) &wave_fmt_ex,  // NOLINT
               format_chunk.cksize) !=
      static_cast<LONG>(format_chunk.cksize)) {
    mmioClose(mmio_handle, 0);
    return false;
  }
  //
  mmioAscend(mmio_handle, &format_chunk, 0);
  //
  MMCKINFO data_chunk;
  memset(&data_chunk, 0, sizeof(MMCKINFO));
  data_chunk.ckid = mmioFOURCC('d', 'a', 't', 'a');
  if (mmioDescend(mmio_handle, &data_chunk, &riff_chunk, MMIO_FINDCHUNK) !=
      MMSYSERR_NOERROR) {
    mmioClose(mmio_handle, 0);
    return false;
  }
  //
  std::unique_ptr<char[]> wave_data(new char[data_chunk.cksize]);
  if (mmioRead(mmio_handle, wave_data.get(), data_chunk.cksize) !=
      static_cast<LONG>(data_chunk.cksize)) {
    mmioClose(mmio_handle, 0);
    return false;
  }
  mmioClose(mmio_handle, 0);
  //
  DSBUFFERDESC ds_buf_desc;
  memset(&ds_buf_desc, 0, sizeof(ds_buf_desc));
  ds_buf_desc.dwSize = sizeof(ds_buf_desc);
  ds_buf_desc.dwFlags = DSBCAPS_GLOBALFOCUS;
  ds_buf_desc.dwBufferBytes = data_chunk.cksize;
  ds_buf_desc.lpwfxFormat = static_cast<LPWAVEFORMATEX>(&wave_fmt_ex);
  ds_buf_desc.guid3DAlgorithm = GUID_NULL;
  IDirectSoundBuffer* sound_buffer;
  if (FAILED(direct_sound8_->CreateSoundBuffer(&ds_buf_desc, &sound_buffer,
                                               NULL))) {
    return false;
  }
  sound_buffer->QueryInterface(
      IID_IDirectSoundBuffer8,
      reinterpret_cast<void**>(&(wave_data_buf_[wave_data_id])));
  sound_buffer->Release();
  //
  void* write_ptr = NULL;
  DWORD length = NULL;
  if (FAILED(wave_data_buf_[wave_data_id]->Lock(0, 0, &write_ptr, &length,
                                                NULL, NULL,
                                                DSBLOCK_ENTIREBUFFER))) {
    return false;
  }
  memcpy(write_ptr, wave_data.get(), length);
  wave_data_buf_[wave_data_id]->Unlock(write_ptr, length, NULL, 0);
  return true;
}
void SoundDevice::ReleaseWaveData(int wave_data_id) {
  if (!SOUND_DEVICE_CHECK_ID(wave_data_id)) return;
  if (!wave_data_buf_[wave_data_id]) return;
  wave_data_buf_[wave_data_id]->Stop();
  wave_data_buf_[wave_data_id]->Release();
  wave_data_buf_[wave_data_id] = nullptr;
}
bool SoundDevice::PlayWaveData(int wave_data_id) {
  if (!SOUND_DEVICE_CHECK_ID(wave_data_id)) return false;
  if (!wave_data_buf_[wave_data_id]) return false;
  wave_data_buf_[wave_data_id]->Play(0, 0, 0);
  return true;
}
bool SoundDevice::StopWaveData(int wave_data_id) {
  if (!SOUND_DEVICE_CHECK_ID(wave_data_id)) return false;
  if (!wave_data_buf_[wave_data_id]) return false;
  wave_data_buf_[wave_data_id]->Stop();
  wave_data_buf_[wave_data_id]->SetCurrentPosition(0);
  return true;
}
}  // namespace mk
