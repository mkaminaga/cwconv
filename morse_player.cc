////////////////////////////////////
// @file morse_player.cpp
// @brief MorsePlayer output
// @author Mamoru Kaminaga
// @date 2016-05-20 19:47:12
////////////////////////////////////
// Copyright 2016 Mamoru Kaminaga
#include "common.h"
#include "morse_player.h"
void MorsePlayer::Initialize() {
  midiOutOpen(&midi_handle_, MIDI_MAPPER, 0, 0, 0);
  midiOutShortMsg(midi_handle_, MIDIMSG(0x0c, 0x00, 0x1f, 0x00));
}
void MorsePlayer::Finalize() {
  midiOutReset(midi_handle_);
  midiOutClose(midi_handle_);
}
void MorsePlayer::ShowSimbol(int morse_code) {
  constexpr int kStrLen = 64;
  wchar_t str_buf[kStrLen] = {0};
  // Exception.
  switch (morse_code) {
    case MORSE_SPACE:
      wcscpy_s(str_buf, kStrLen, L" ");
      return;
    case MORSE_UNKNOWN:
      wcscpy_s(str_buf, kStrLen, L"<?>");
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
      case SHORT_VOWEL: str_buf[i << 1] = '|'; break;
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
    case MORSE_UNKNOWN:
      Sleep(dot_len_ * 6);  // Time adjustment
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
    midiOutShortMsg(midi_handle_, MIDIMSG(0x09, 0x00, 0x2a, 0x7f));  // Start
    switch (simbol) {
      case SHORT_VOWEL: Sleep(dot_len_); break;
      case LONG_VOWEL: Sleep(dot_len_ * 3); break;
      default: break;
    }
    midiOutShortMsg(midi_handle_, MIDIMSG(0x09, 0x00, 0x2a, 0x00));  // Stop
    Sleep(dot_len_);  // dot separator
  }
  Sleep(dot_len_ * 3);  // charctor separator
}
