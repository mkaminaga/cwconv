////////////////////////////////////
// @file common.h
// @brief Common included header files
// @author Mamoru Kaminaga
// @date 2016-05-20 19:47:28
// Copyright 2016 Mamoru Kaminaga
////////////////////////////////////
#ifndef COMMON_H_
#define COMMON_H_
#include <wchar.h>
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#define APP_NAME L"cwconv"
void PrintError(const wchar_t* msg);
void DialogError(const wchar_t* msg);
#endif  // COMMON_H_
