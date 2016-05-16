/**
 * @file main.cpp
 * @brief Morse code generator
 * @author Mamoru Kaminaga
 * @date 2016-05-15 12:08:31
 * */
#include <windows.h>
#include "tchar.h"
#include "stdio.h"
#include "morse.h"

void morseCodeToString(int element, LPTSTR morse, int count);
void morseCodeToSound(int element, int dot);

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	   	LPTSTR lpCmdLine, int nCmdShow) {

	UNREFERENCED_PARAMETER(hInstance);
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	UNREFERENCED_PARAMETER(nCmdShow);

#if 0
	/* Error message */
	if (argc <= 1) {
		MessageBox(NULL, _T("No arguments"), _T("error"), MB_OK);
		return -1;
	}

	/* string to morse code */
	int i = 0;
	int length = (int) ::_tcslen(argv[1]); //size_t -> int
	LPTSTR morse = 0;
	for (i = 0; i < length; i++) {
		tchar2morse(argv[1][i], &morse);
		_tprintf(_T("%c: %s\n"), argv[1][i], morse);
	}
#endif
	/* Get debug cnsole */
	if (!AttachConsole(ATTACH_PARENT_PROCESS)) {
		AllocConsole();
	}
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);

#if 0
	_tprintf(_T("AllocConsole\n"));
#endif

	TCHAR morse[32] = {0};

	morseCodeToString(CW_CODE_A, morse, ARRAYSIZE(morse));
	_tprintf(_T("%c: %s\n"), 'A', morse);
	morseCodeToSound(CW_CODE_A, 120);

	/* End */
	system("PAUSE");

	return 0;
}

void morseCodeToString(int element, LPTSTR morse, int count) {
	int i = 0;
	int temp = 0;

	/* Adjust to left */
	while (!(element & 0xf0000000)) {
		element <<= 4;
		i++;
		if (i > 8)
			break; //infint loop escape
	}

	/* Conversion */
	for (i = 0; i < 8; i++) {
		if (i * 2 > count)
			break; //out of array
		temp = element >> (4 * (7 - i));
		switch (temp) {
			case 1: morse[i * 2] = '.'; break;
			case 3: morse[i * 2] = '-'; break;
			default: return;
		}
		morse[(i * 2) + 1] = ' ';
	}
}

void morseCodeToSound(int element, int dot) {
	int i = 0;
	int temp = 0;

	/* Adjust to left */
	while (!(element & 0xf0000000)) {
		element <<= 4;
		i++;
		if (i > 8)
			break; //infint loop escape
	}

	/* Conversion */
	for (i = 0; i < 8; i++) {
		temp = element >> (4 * (7 - i));
		switch (temp) {
			case 1: Beep(CW_BEEP_FREQ, dot); break;
			case 3: Beep(CW_BEEP_FREQ, dot * 3); break;
			default: return;
		}
		Sleep(dot);
	}
}
