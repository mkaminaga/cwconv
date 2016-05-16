/**
 * @file main.cpp
 * @brief Morse code generator
 * @author Mamoru Kaminaga
 * @date 2016-05-15 12:08:31
 * */
#include "common.h"
#include "morse.h"

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
	_tprintf(_T("\n"));

#if 0
	_tprintf(_T("AllocConsole\n"));
#endif

	const int dotLen = 400;
	TCHAR morse[32] = {0};

	morseCodeToString(CW_CODE_A, morse, ARRAYSIZE(morse));
	_tprintf(_T("%c: %s\n"), 'A', morse);
	morseCodeToSound(CW_CODE_A, dotLen);
	Sleep(dotLen);

	morseCodeToString(CW_CODE_B, morse, ARRAYSIZE(morse));
	_tprintf(_T("%c: %s\n"), 'B', morse);
	morseCodeToSound(CW_CODE_B, dotLen);
	Sleep(dotLen);

	morseCodeToString(CW_CODE_C, morse, ARRAYSIZE(morse));
	_tprintf(_T("%c: %s\n"), 'C', morse);
	morseCodeToSound(CW_CODE_C, dotLen);
	Sleep(dotLen);

	/* End */
	system("PAUSE");
	FreeConsole();

	return 0;
}
