////////////////////////////////////
// @file main.cc
// @brief Morse code generator
// @author Mamoru Kaminaga
// @date 2016-05-15 12:08:31
// Copyright 2016 Mamoru Kaminaga
////////////////////////////////////
#include <wchar.h>
#include <windows.h>
#include <stdio.h>
#include "common.h"
#include "morse_player.h"
#include "resource.h"
#include "sound_device.h"
#define WINDOW_STYLE    (WS_POPUP|WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX)
enum OPTIONS {
  OPTION_HELP = 0,
  OPTION_STRING,
  OPTION_NOWINDOW,
  OPTION_NOSOUND,
  OPTION_WPM,
  OPTION_PARIS,
  ELEMNUM_OPTIONS, // Array size.
};
const wchar_t kOptions[ELEMNUM_OPTIONS][16] = {
  L"-help",        // OPTION_HELP
  L"-s",           // OPTION_STRING
  L"-nowindow",    // OPTION_NOWINDOW
  L"-nosound",     // OPTION_NOSOUND
  L"-wpm",         // OPTION_WPM
  L"-paris",       // OPTION_PARIS
};
const wchar_t kHelp[ELEMNUM_OPTIONS][64] = {
  L"Show help",                        // OPTION_HELP
  L"Input string to be morse signal",  // OPTION_STRING
  L"Not show output console",          // OPTION_NOWINDOW
  L"Not play midi sound",              // OPTION_NOSOUND
  L"Set WPM, default is 20",           // OPTION_WPM
  L"Set PARIS, default is 20",         // OPTION_PARIS
};
bool help_required = false;
bool no_console = false;
bool no_sound = false;
bool play_command_line_string = false;
int string_argc_offset = 0;
namespace mk {
void ShowAndPlay(MorsePlayer* morse_player, wchar_t charactor) {
  int morse_code = 0;
  switch (charactor) {
    case L'a': case L'A': morse_code = MORSE_A; break;
    case L'b': case L'B': morse_code = MORSE_B; break;
    case L'c': case L'C': morse_code = MORSE_C; break;
    case L'd': case L'D': morse_code = MORSE_D; break;
    case L'e': case L'E': morse_code = MORSE_E; break;
    case L'f': case L'F': morse_code = MORSE_F; break;
    case L'g': case L'G': morse_code = MORSE_G; break;
    case L'h': case L'H': morse_code = MORSE_H; break;
    case L'i': case L'I': morse_code = MORSE_I; break;
    case L'j': case L'J': morse_code = MORSE_J; break;
    case L'k': case L'K': morse_code = MORSE_K; break;
    case L'l': case L'L': morse_code = MORSE_L; break;
    case L'm': case L'M': morse_code = MORSE_M; break;
    case L'n': case L'N': morse_code = MORSE_N; break;
    case L'o': case L'O': morse_code = MORSE_O; break;
    case L'p': case L'P': morse_code = MORSE_P; break;
    case L'q': case L'Q': morse_code = MORSE_Q; break;
    case L'r': case L'R': morse_code = MORSE_R; break;
    case L's': case L'S': morse_code = MORSE_S; break;
    case L't': case L'T': morse_code = MORSE_T; break;
    case L'u': case L'U': morse_code = MORSE_U; break;
    case L'v': case L'V': morse_code = MORSE_V; break;
    case L'w': case L'W': morse_code = MORSE_W; break;
    case L'x': case L'X': morse_code = MORSE_X; break;
    case L'y': case L'Y': morse_code = MORSE_Y; break;
    case L'z': case L'Z': morse_code = MORSE_Z; break;
    case L'1': morse_code = MORSE_1; break;
    case L'2': morse_code = MORSE_2; break;
    case L'3': morse_code = MORSE_3; break;
    case L'4': morse_code = MORSE_4; break;
    case L'5': morse_code = MORSE_5; break;
    case L'6': morse_code = MORSE_6; break;
    case L'7': morse_code = MORSE_7; break;
    case L'8': morse_code = MORSE_8; break;
    case L'9': morse_code = MORSE_9; break;
    case L'0': morse_code = MORSE_0; break;
    case L'.': morse_code = MORSE_PER; break;
    case L',': morse_code = MORSE_COM; break;
    case L'?': morse_code = MORSE_QUE; break;
    case L'-': morse_code = MORSE_HIF; break;
    case L'/': morse_code = MORSE_SLA; break;
    case L'@': morse_code = MORSE_ATM; break;
    case L' ': morse_code = MORSE_SPACE; break;
    default: morse_code = MORSE_UNKNOWN; break;
  }
  // Morse shown to console.
  if (!no_console) morse_player->ShowSimbol(morse_code);
  // Sound played by device.
  if (!no_sound) morse_player->PlaySound(morse_code);
}
// Void callback function.
LRESULT CALLBACK WndProc(HWND wnd, UINT msg, WPARAM wp, LPARAM lp) {
  // Prevent warnings for unreferenced parameters.
  UNREFERENCED_PARAMETER(wnd);
  UNREFERENCED_PARAMETER(wp);
  UNREFERENCED_PARAMETER(lp);
  switch (msg) {
    case WM_DESTROY:
      PostQuitMessage(0);
      break;
    default:
      break;
  }
  return DefWindowProc(wnd, msg, wp, lp);
}
// Window is required to set icom on win32 application.
HWND CreateInvisibleWindow(HINSTANCE instance_handle) {
  WNDCLASSEX wcex;
  // Window class registered.
  memset(&wcex, 0, sizeof(wcex));
  wcex.cbSize = sizeof(wcex);
  wcex.style = CS_HREDRAW | CS_VREDRAW;
  wcex.lpfnWndProc = WndProc;
  wcex.cbClsExtra = 0;
  wcex.cbWndExtra = 0;
  wcex.hInstance = instance_handle;
  wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
  wcex.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);
  wcex.lpszMenuName = NULL;
  wcex.lpszClassName = APP_NAME;
  wcex.hIcon = LoadIcon(instance_handle, MAKEINTRESOURCE(IDI_ICON1));
  wcex.hIconSm = LoadIcon(instance_handle, MAKEINTRESOURCE(IDI_ICON1));
  if (RegisterClassEx(&wcex) == 0) return false;
  // Invisible window created.
  return CreateWindow(APP_NAME, APP_NAME, WINDOW_STYLE, CW_USEDEFAULT,
                      CW_USEDEFAULT, 256, 256, NULL, NULL, instance_handle,
                      NULL);
}
}  // namespace mk
int WINAPI wWinMain(HINSTANCE instance_handle, HINSTANCE not_used,
                    LPTSTR cmd_lind, int cmd_show) {
  // Prevent warnings for unreferenced parameters.
  UNREFERENCED_PARAMETER(instance_handle);
  UNREFERENCED_PARAMETER(not_used);
  UNREFERENCED_PARAMETER(cmd_lind);
  UNREFERENCED_PARAMETER(cmd_show);
  //
  HWND window_handle = mk::CreateInvisibleWindow(instance_handle);
  mk::SoundDevice device(window_handle);
  device.Initialize();
  mk::MorsePlayer morse_player(&device);
  morse_player.Initialize();
  morse_player.dot_ms_ = 60;
  // Command line args proc.
  for (int i = 1; i < __argc; ++i) {
    for (int j = 0; j < ELEMNUM_OPTIONS; ++j) {
      if (wcscmp(__wargv[i], kOptions[j]) == 0) {
        switch (j) {
          case OPTION_HELP:
            help_required = true;
            break;
          case OPTION_NOWINDOW:
            no_console = true;
            break;
          case OPTION_NOSOUND:
            no_sound = true;
            break;
          case OPTION_WPM:  // Same as OPTION_PARIS
          case OPTION_PARIS:
            // wpm (paris) -> dot millis
            morse_player.dot_ms_ = 60000 / (_wtoi(__wargv[i + 1]) * 50);
            break;
          case OPTION_STRING:
            play_command_line_string = true;
            string_argc_offset = i + 1;
          default:
            break;
        }
      }
    }
  }
  // Console proc.
  if (!no_console) {
    if (!AttachConsole(ATTACH_PARENT_PROCESS)) AllocConsole();
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
  }
  // Argument num error check proc.
  if (__argc <= 1) {
    if (no_console) {
      mk::DialogError(L"No arguments specified");
      return -1;
    } else {
      mk::PrintError(L"No arguments specified");
      goto ERROR_EXIT;
    }
  }
  // Help option proc.
  if (help_required) {
    if (no_console) {
      mk::DialogError(L"You must not set -nowindow option to show help");
      return 0;
    } else {
      wprintf(APP_NAME);
      wprintf(L"\n");
      wprintf(L"options:\n");
      for (int i = 0; i < ELEMNUM_OPTIONS; ++i) {
        wprintf(L"%s:\t%s\n", kOptions[i], kHelp[i]);
      }
      goto ERROR_EXIT;
    }
  }
  // String error proc.
  if (play_command_line_string == false) {
    if (no_console) {
      mk::DialogError(L"No input string");
      return -1;
    } else {
      mk::PrintError(L"No input string");
      goto ERROR_EXIT;
    }
  }
  // Morse generation proc.
  int length = 0;
  for (int i = string_argc_offset; i < __argc; ++i) {
    length = wcslen(__wargv[i]);
    for (int j = 0; j < length; ++j) {
      mk::ShowAndPlay(&morse_player, __wargv[i][j]);
      mk::ShowAndPlay(&morse_player, L' ');
    }
    if (i != (__argc - 1)) {  // Word separator.
      mk::ShowAndPlay(&morse_player, L' ');
      mk::ShowAndPlay(&morse_player, L' ');
      mk::ShowAndPlay(&morse_player, L' ');
    }
  }
  // Normal exit proc.
  if (!no_console) {
    system("PAUSE");
    FreeConsole();
  }
  morse_player.Finalize();
  device.Finalize();
  return 0;

ERROR_EXIT:
  // Error exit proc.
  if (!no_console) {
    system("PAUSE");
    FreeConsole();
  }
  morse_player.Finalize();
  device.Finalize();
  return -1;
}
