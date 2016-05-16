/**
 * @file main.cpp
 * @brief Morse code generator
 * @author Mamoru Kaminaga
 * @date 2016-05-15 12:08:31
 * */
#include "common.h"
#include "morse.h"

void OutputMorse(TCHAR c);
void OutputTextAndSound(int code, TCHAR c);

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	   	LPTSTR lpCmdLine, int nCmdShow) {

	UNREFERENCED_PARAMETER(hInstance);
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	UNREFERENCED_PARAMETER(nCmdShow);

	/* Get command line arguments */
	int argc = 0;
	LPTSTR* argv = CommandLineToArgvW(GetCommandLine(), &argc);

	/* Get debug cnsole */
	if (!AttachConsole(ATTACH_PARENT_PROCESS)) {
		AllocConsole();
	}
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
	_tprintf(_T("\n"));

	/* Error message */
	if (argc <= 1) {
		_tprintf(_T("No arguments\n"));
		system("PAUSE");
		return -1;
	}

	/* string to morse code */
	int i = 0;
	int j = 0;
	int length = 0;
	for (i = 1; i < argc; i++) {
		length = (int) _tcslen(argv[i]);
		for (j = 0; j < length; j++) {
			OutputMorse(argv[i][j]);
		}
	}

#if 0
	const int dotLen = 200;
	TCHAR morse[32] = {0};

	morseCodeToString(CW_CODE_A, morse, ARRAYSIZE(morse));
	_tprintf(_T("%c: %s\n"), 'A', morse);
	morseCodeToSound(CW_CODE_A, dotLen);
	Sleep(dotLen);

	morseCodeToString(CW_CODE_B, morse, ARRAYSIZE(morse));
	_tprintf(_T("%c: %s\n"), 'B', morse);
	morseCodeToSound(CW_CODE_B, dotLen);
	Sleep(dotLen);
#endif

	/* End */
	system("PAUSE");
	FreeConsole();

	return 0;
}

void OutputMorse(TCHAR c) {
	switch (c) {
		case _T('a'): case _T('A'): OutputTextAndSound(CW_CODE_A, c); break;
		case _T('b'): case _T('B'): OutputTextAndSound(CW_CODE_B, c); break;
		case _T('c'): case _T('C'): OutputTextAndSound(CW_CODE_C, c); break;
		case _T('d'): case _T('D'): OutputTextAndSound(CW_CODE_D, c); break;
		case _T('e'): case _T('E'): OutputTextAndSound(CW_CODE_E, c); break;
		case _T('f'): case _T('F'): OutputTextAndSound(CW_CODE_F, c); break;
		case _T('g'): case _T('G'): OutputTextAndSound(CW_CODE_G, c); break;
		case _T('h'): case _T('H'): OutputTextAndSound(CW_CODE_H, c); break;
		case _T('i'): case _T('I'): OutputTextAndSound(CW_CODE_I, c); break;
		case _T('j'): case _T('J'): OutputTextAndSound(CW_CODE_J, c); break;
		case _T('k'): case _T('K'): OutputTextAndSound(CW_CODE_K, c); break;
		case _T('l'): case _T('L'): OutputTextAndSound(CW_CODE_L, c); break;
		case _T('m'): case _T('M'): OutputTextAndSound(CW_CODE_M, c); break;
		case _T('n'): case _T('N'): OutputTextAndSound(CW_CODE_N, c); break;
		case _T('o'): case _T('O'): OutputTextAndSound(CW_CODE_O, c); break;
		case _T('p'): case _T('P'): OutputTextAndSound(CW_CODE_P, c); break;
		case _T('q'): case _T('Q'): OutputTextAndSound(CW_CODE_Q, c); break;
		case _T('r'): case _T('R'): OutputTextAndSound(CW_CODE_R, c); break;
		case _T('s'): case _T('S'): OutputTextAndSound(CW_CODE_S, c); break;
		case _T('t'): case _T('T'): OutputTextAndSound(CW_CODE_T, c); break;
		case _T('u'): case _T('U'): OutputTextAndSound(CW_CODE_U, c); break;
		case _T('v'): case _T('V'): OutputTextAndSound(CW_CODE_V, c); break;
		case _T('w'): case _T('W'): OutputTextAndSound(CW_CODE_W, c); break;
		case _T('x'): case _T('X'): OutputTextAndSound(CW_CODE_X, c); break;
		case _T('y'): case _T('Y'): OutputTextAndSound(CW_CODE_Y, c); break;
		case _T('z'): case _T('Z'): OutputTextAndSound(CW_CODE_Z, c); break;

		case _T('1'): OutputTextAndSound(CW_CODE_1, c); break;
		case _T('2'): OutputTextAndSound(CW_CODE_2, c); break;
		case _T('3'): OutputTextAndSound(CW_CODE_3, c); break;
		case _T('4'): OutputTextAndSound(CW_CODE_4, c); break;
		case _T('5'): OutputTextAndSound(CW_CODE_5, c); break;
		case _T('6'): OutputTextAndSound(CW_CODE_6, c); break;
		case _T('7'): OutputTextAndSound(CW_CODE_7, c); break;
		case _T('8'): OutputTextAndSound(CW_CODE_8, c); break;
		case _T('9'): OutputTextAndSound(CW_CODE_9, c); break;
		case _T('0'): OutputTextAndSound(CW_CODE_0, c); break;

		case _T('.'): OutputTextAndSound(CW_CODE_PER, c); break;
		case _T(','): OutputTextAndSound(CW_CODE_COM, c); break;
		case _T('?'): OutputTextAndSound(CW_CODE_QUE, c); break;
		case _T('-'): OutputTextAndSound(CW_CODE_HIF, c); break;
		case _T('/'): OutputTextAndSound(CW_CODE_SLA, c); break;
		case _T('@'): OutputTextAndSound(CW_CODE_ATM, c); break;
		case _T(' '): OutputTextAndSound(CW_CODE_SPACE, c); break;

		default: OutputTextAndSound(CW_CODE_UNKNOWN, c); break;
	}
}

void OutputTextAndSound(int code, TCHAR c) {
	const int dotLen = 200;
	TCHAR morse[32] = {0};

	morseCodeToString(code, morse, ARRAYSIZE(morse));
	_tprintf(_T("%c: %s\n"), c, morse);
	morseCodeToSound(code, dotLen);
	Sleep(dotLen);
}
