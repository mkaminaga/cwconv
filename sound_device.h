// @file sound_device.h
// @brief Sound device class
// @author Mamoru Kaminaga
// @date 2016-05-15 12:08:31
//
// Copyright (c) 2016 Mamoru Kaminaga
//
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php
#ifndef SOUND_DEVICE_H_
#define SOUND_DEVICE_H_
#include <wchar.h>
#include <windows.h>
#include <mmsystem.h>
#include <dsound.h>
#define SOUND_DEVICE_WAVE_NUM    (1024)
#define SOUND_DEVICE_CHECK_ID(x) ((x >= 0) && (x < SOUND_DEVICE_WAVE_NUM))
namespace mk {
class SoundDevice {
 public:
  explicit SoundDevice(HWND window_handle) : window_handle_(window_handle) {}
  ~SoundDevice() {}
  bool Initialize();
  void Finalize();
  bool CreateWaveDataFromFile(int wave_data_id, const wchar_t* file_name);
  void ReleaseWaveData(int wave_data_id);
  bool PlayWaveData(int wave_data_id);
  bool StopWaveData(int wave_data_id);
 private:
  HWND window_handle_;
  IDirectSound8* direct_sound8_;
  IDirectSoundBuffer* wave_data_buf_[SOUND_DEVICE_WAVE_NUM];
};
}  // namespace mk
#endif  // SOUND_DEVICE_H_
