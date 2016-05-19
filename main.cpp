/**
 * @file main.cpp
 * @brief Morse code generator
 * @author Mamoru Kaminaga
 * @date 2016-05-15 12:08:31
 * */
#include "common.h"
#include "morse.h"

void OutputMorse(TCHAR c);
void OutputTerminalStringAndSound(int code, TCHAR c);

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	   	LPTSTR lpCmdLine, int nCmdShow) {

	UNREFERENCED_PARAMETER(hInstance);
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	UNREFERENCED_PARAMETER(nCmdShow);

	/* Get debug cnsole */
	if (!AttachConsole(ATTACH_PARENT_PROCESS)) {
		AllocConsole();
	}
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
	_tprintf(_T("\n"));

	/* Morse out */
	Morse& morse = Morse::GetInstance();
	morse.dotLen = 150;
	int i = 0;
	int length = (int) _tcslen(lpCmdLine);
	for (i = 0; i < length; i++) {
		OutputMorse(lpCmdLine[i]);
	}

	/* End */
	system("PAUSE");
	FreeConsole();

	return 0;
}

void OutputMorse(TCHAR c) {
	switch (c) {
		case _T('a'): case _T('A'): OutputTerminalStringAndSound(CW_CODE_A, c); break;
		case _T('b'): case _T('B'): OutputTerminalStringAndSound(CW_CODE_B, c); break;
		case _T('c'): case _T('C'): OutputTerminalStringAndSound(CW_CODE_C, c); break;
		case _T('d'): case _T('D'): OutputTerminalStringAndSound(CW_CODE_D, c); break;
		case _T('e'): case _T('E'): OutputTerminalStringAndSound(CW_CODE_E, c); break;
		case _T('f'): case _T('F'): OutputTerminalStringAndSound(CW_CODE_F, c); break;
		case _T('g'): case _T('G'): OutputTerminalStringAndSound(CW_CODE_G, c); break;
		case _T('h'): case _T('H'): OutputTerminalStringAndSound(CW_CODE_H, c); break;
		case _T('i'): case _T('I'): OutputTerminalStringAndSound(CW_CODE_I, c); break;
		case _T('j'): case _T('J'): OutputTerminalStringAndSound(CW_CODE_J, c); break;
		case _T('k'): case _T('K'): OutputTerminalStringAndSound(CW_CODE_K, c); break;
		case _T('l'): case _T('L'): OutputTerminalStringAndSound(CW_CODE_L, c); break;
		case _T('m'): case _T('M'): OutputTerminalStringAndSound(CW_CODE_M, c); break;
		case _T('n'): case _T('N'): OutputTerminalStringAndSound(CW_CODE_N, c); break;
		case _T('o'): case _T('O'): OutputTerminalStringAndSound(CW_CODE_O, c); break;
		case _T('p'): case _T('P'): OutputTerminalStringAndSound(CW_CODE_P, c); break;
		case _T('q'): case _T('Q'): OutputTerminalStringAndSound(CW_CODE_Q, c); break;
		case _T('r'): case _T('R'): OutputTerminalStringAndSound(CW_CODE_R, c); break;
		case _T('s'): case _T('S'): OutputTerminalStringAndSound(CW_CODE_S, c); break;
		case _T('t'): case _T('T'): OutputTerminalStringAndSound(CW_CODE_T, c); break;
		case _T('u'): case _T('U'): OutputTerminalStringAndSound(CW_CODE_U, c); break;
		case _T('v'): case _T('V'): OutputTerminalStringAndSound(CW_CODE_V, c); break;
		case _T('w'): case _T('W'): OutputTerminalStringAndSound(CW_CODE_W, c); break;
		case _T('x'): case _T('X'): OutputTerminalStringAndSound(CW_CODE_X, c); break;
		case _T('y'): case _T('Y'): OutputTerminalStringAndSound(CW_CODE_Y, c); break;
		case _T('z'): case _T('Z'): OutputTerminalStringAndSound(CW_CODE_Z, c); break;

		case _T('1'): OutputTerminalStringAndSound(CW_CODE_1, c); break;
		case _T('2'): OutputTerminalStringAndSound(CW_CODE_2, c); break;
		case _T('3'): OutputTerminalStringAndSound(CW_CODE_3, c); break;
		case _T('4'): OutputTerminalStringAndSound(CW_CODE_4, c); break;
		case _T('5'): OutputTerminalStringAndSound(CW_CODE_5, c); break;
		case _T('6'): OutputTerminalStringAndSound(CW_CODE_6, c); break;
		case _T('7'): OutputTerminalStringAndSound(CW_CODE_7, c); break;
		case _T('8'): OutputTerminalStringAndSound(CW_CODE_8, c); break;
		case _T('9'): OutputTerminalStringAndSound(CW_CODE_9, c); break;
		case _T('0'): OutputTerminalStringAndSound(CW_CODE_0, c); break;

		case _T('.'): OutputTerminalStringAndSound(CW_CODE_PER, c); break;
		case _T(','): OutputTerminalStringAndSound(CW_CODE_COM, c); break;
		case _T('?'): OutputTerminalStringAndSound(CW_CODE_QUE, c); break;
		case _T('-'): OutputTerminalStringAndSound(CW_CODE_HIF, c); break;
		case _T('/'): OutputTerminalStringAndSound(CW_CODE_SLA, c); break;
		case _T('@'): OutputTerminalStringAndSound(CW_CODE_ATM, c); break;
		case _T(' '): OutputTerminalStringAndSound(CW_CODE_SPACE, c); break;

		default: OutputTerminalStringAndSound(CW_CODE_UNKNOWN, c); break;
	}
}

void OutputTerminalStringAndSound(int code, TCHAR c) {
	Morse& morse = Morse::GetInstance();
	TCHAR strBuf[32] = {0};

	morse.ToString(code, strBuf, ARRAYSIZE(strBuf));
	_tprintf(_T("%c: %s\n"), c, strBuf);
	morse.ToSound(code);
}
