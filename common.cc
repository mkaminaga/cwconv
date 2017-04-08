////////////////////////////////////
// @file common.cpp
// @brief Common function
// @author Mamoru Kaminaga
// @date 2016-05-15 12:08:31
// Copyright 2016 Mamoru Kaminaga
////////////////////////////////////
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
