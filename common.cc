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
#include "common.h"
namespace mk {
void PrintError(const wchar_t* msg) {
  wprintf(L"ERROR: %s\n", msg);
}
void DialogError(const wchar_t* msg) {
  wchar_t buf[64] = {0};
  wsprintf(buf, L"ERROR: %s", msg);
  MessageBox(NULL, buf, APP_NAME, NULL);
}
}  // namespace mk
