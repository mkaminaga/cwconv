// @file common.cpp
// @brief Common function
// @author Mamoru Kaminaga
// @date 2016-05-15 12:08:31
//
// Copyright (c) 2016 Mamoru Kaminaga
//
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php
#include <wchar.h>
#include <windows.h>
#include <stdarg.h>
#include <stdio.h>
#include "common.h"
namespace mk {
void PrintError(const wchar_t* format, ...) {
  wchar_t buffer[256] = {0};
  va_list args;
  va_start(args, format);
  vswprintf_s(buffer, 256, format, args);
  wprintf(L"ERROR: %s\n", buffer);
}
void DialogError(const wchar_t* format, ...) {
  wchar_t buffer[256] = {0};
  va_list args;
  va_start(args, format);
  vswprintf_s(buffer, 256, format, args);
  wsprintf(buffer, L"ERROR: %s", buffer);
  MessageBox(NULL, buffer, APP_NAME, NULL);
}
}  // namespace mk
