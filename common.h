// @file common.h
// @brief Common data and functions
// @author Mamoru Kaminaga
// @date 2016-05-15 12:08:31
//
// Copyright (c) 2016 Mamoru Kaminaga
//
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php
#ifndef COMMON_H_
#define COMMON_H_
#define APP_NAME                  L"cwconv"
#define MORSE_PLAYER_WAV_DATA_ID  (0)
namespace mk {
void PrintError(const wchar_t* msg);
void DialogError(const wchar_t* msg);
}  // namespace mk
#endif  // COMMON_H_
