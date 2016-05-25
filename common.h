/**
 * @file common.h
 * @brief Common included header files
 * @author Mamoru Kaminaga
 * @date 2016-05-20 19:47:28
 * */
#pragma once

#include <windows.h>
#include <tchar.h>
#include <mmsystem.h>
#include <stdio.h>

#define PROGRAM "cwconv"

void error_console(LPTSTR msg);
void error_wondow(LPTSTR msg);
