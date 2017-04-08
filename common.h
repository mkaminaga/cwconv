////////////////////////////////////
// @file common.h
// @brief Common data and functions
// @author Mamoru Kaminaga
// @date 2016-05-20 19:47:28
// Copyright 2016 Mamoru Kaminaga
////////////////////////////////////
#ifndef COMMON_H_
#define COMMON_H_
#define APP_NAME L"cwconv"
namespace mk {
void PrintError(const wchar_t* msg);
void DialogError(const wchar_t* msg);
}  // namespace mk
#endif  // COMMON_H_
