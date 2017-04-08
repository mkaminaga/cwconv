////////////////////////////////////
// @file morse_player.h
// @brief Midi related information
// @author Mamoru Kaminaga
// @date 2016-05-20 19:47:50
// Copyright 2016 Mamoru Kaminaga
////////////////////////////////////
#ifndef MORSE_PLAYER_H_
#define MORSE_PLAYER_H_
#include <wchar.h>
#include <windows.h>
#include <mmsystem.h>
#define MIDIMSG(status, channel, data1, data2) \
  (static_cast<DWORD>((status << 4)|channel|(data1 << 8)|(data2 << 16)))
// Morse data table, 1 stands for short sound, 3 stands for long sound.
#define SHORT_VOWEL     (1)
#define LONG_VOWEL      (3)
#define MORSE_A         (0x13)
#define MORSE_B         (0x311)
#define MORSE_C         (0x3131)
#define MORSE_D         (0x311)
#define MORSE_E         (0x1)
#define MORSE_F         (0x1131)
#define MORSE_G         (0x331)
#define MORSE_H         (0x1111)
#define MORSE_I         (0x11)
#define MORSE_J         (0x1333)
#define MORSE_K         (0x313)
#define MORSE_L         (0x1311)
#define MORSE_M         (0x33)
#define MORSE_N         (0x31)
#define MORSE_O         (0x333)
#define MORSE_P         (0x1331)
#define MORSE_Q         (0x3313)
#define MORSE_R         (0x131)
#define MORSE_S         (0x111)
#define MORSE_T         (0x3)
#define MORSE_U         (0x113)
#define MORSE_V         (0x1113)
#define MORSE_W         (0x133)
#define MORSE_X         (0x3113)
#define MORSE_Y         (0x3133)
#define MORSE_Z         (0x3311)
#define MORSE_1         (0x13333)
#define MORSE_2         (0x11333)
#define MORSE_3         (0x11133)
#define MORSE_4         (0x11113)
#define MORSE_5         (0x11111)
#define MORSE_6         (0x31111)
#define MORSE_7         (0x33111)
#define MORSE_8         (0x33311)
#define MORSE_9         (0x33331)
#define MORSE_0         (0x33333)
#define MORSE_PER       (0x131313)
#define MORSE_COM       (0x331133)
#define MORSE_QUE       (0x113311)
#define MORSE_SEP       (0x31113)
#define MORSE_HIF       (0x311113)
#define MORSE_SLA       (0x31131)
#define MORSE_ATM       (0x133131)
#define MORSE_FIX       (0x11111111)
#define MORSE_SPACE     (0xaaaaaaaa)
#define MORSE_UNKNOWN   (0xbbbbbbbb)
namespace mk {
class MorsePlayer {
 public:
  int dot_len_;
  MorsePlayer() : dot_len_(60) {}
  ~MorsePlayer() {}
  void Initialize();
  void Finalize();
  void ShowSimbol(int code);
  void PlaySound(int code);
 private:
  HMIDIOUT midi_handle_;
};
}  // namespace mk
#endif  // MORSE_PLAYER_H_
