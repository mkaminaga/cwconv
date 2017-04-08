// @file morse_player.cpp
// @brief MorsePlayer output
// @author Mamoru Kaminaga
// @date 2016-05-20 19:47:12
// Copyright 2016 Mamoru Kaminaga
#include "morse_player.h"
#include <wchar.h>
#include <windows.h>
#include <stdio.h>
#include "common.h"
#include "sound_device.h"
#define WAVE_FILE L"sin_wave.wav"
namespace mk {
bool MorsePlayer::Initialize() {
  return sound_device_->CreateWaveDataFromFile(wave_data_id_, WAVE_FILE);
}
void MorsePlayer::Finalize() {
  sound_device_->ReleaseWaveData(wave_data_id_);
}
void MorsePlayer::ShowSimbol(int morse_code) {
  constexpr int kStrLen = 64;
  wchar_t str_buf[kStrLen] = {0};
  // Exception.
  switch (morse_code) {
    case MORSE_SPACE:
      wprintf(L" ");
      return;
    case MORSE_UNKNOWN:
      wprintf(L"<?>");
      return;
    default:
      break;
  }
  // Adjust to left.
  int i = 0;
  int simbol = 0;
  while (!(morse_code & 0xf0000000)) {
    morse_code <<= 4;
    ++i;
    if (i > 8) break;  // infint loop escape
  }
  // Convert string to morse simbol.
  for (i = 0; i < 8 && (i << 1) <= kStrLen; ++i) {
    simbol = (morse_code >> (4 * (7 - i))) & 0xf;
    if ((simbol & 0xf) == 0) break;
    switch (simbol) {
      case SHORT_VOWEL: str_buf[i << 1] = '.'; break;
      case LONG_VOWEL: str_buf[i << 1] = '_'; break;
      default: return;
    }
    str_buf[(i << 1) + 1] = ' ';
  }
  wprintf(L"%s", str_buf);
}
void MorsePlayer::PlaySound(int morse_code) {
  // Exception.
  switch (morse_code) {
    case MORSE_SPACE:
      Sleep(dot_ms_);  // Blank time
      return;
    case MORSE_UNKNOWN:  // No sound
      return;
    default:
      break;
  }
  // Adjust to left.
  int i = 0;
  int simbol = 0;
  while (!(morse_code & 0xf0000000)) {
    morse_code <<= 4;
    ++i;
    if (i > 8) break;  // infint loop escape
  }
  // Convert string to morse sound.
  for (i = 0; i < 8; i++) {
    simbol = (morse_code >> (4 * (7 - i))) & 0xf;
    if ((simbol & 0xf) == 0) break;
    sound_device_->PlayWaveData(wave_data_id_);
    switch (simbol) {
      case SHORT_VOWEL: Sleep(dot_ms_); break;
      case LONG_VOWEL: Sleep(dot_ms_ * 3); break;
      default: break;
    }
    sound_device_->StopWaveData(wave_data_id_);
    Sleep(dot_ms_);  // dot separator
  }
  Sleep(dot_ms_ * 3);  // charctor separator
}
}  // namespace mk
