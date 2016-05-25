/**
 * @file main.cpp
 * @brief Morse code generator
 * @author Mamoru Kaminaga
 * @date 2016-05-15 12:08:31
 * */
#include "common.h"
#include "morse.h"

void OutputMorseConsoleAndSound(TCHAR c);

/* Command line option related data */
const TCHAR options[][16] = {
	_T("-help"),
	_T("-s"),
	_T("-nowindow"),
	_T("-nosound"),
	_T("-wpm"),
	_T("-paris"),
};

const TCHAR helpMsg[][32] = {
	_T("Show help."),
	_T("Input string tobe morse signal"),
	_T("Not show output console."),
	_T("Not play midi sound."),
	_T("Set WPM, default is 20."),
	_T("Set PARIS, default is 20."),
};

enum options {
	HELP = 0,
	STRING,
	NOWINDOW,
	NOSOUND,
	WPM,
	PARIS,
};

int gHelpFlag = FALSE;
int gNoConsoleFlag = FALSE;
int gNoSoundFlag = FALSE;
int gStringFlag = FALSE;
int gStringArg = 0;

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	   	LPTSTR lpCmdLine, int nCmdShow) {
	UNREFERENCED_PARAMETER(hInstance);
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	UNREFERENCED_PARAMETER(nCmdShow);

	Morse& morse = Morse::GetInstance();
	morse.dotLen = 60;

	/* Process command line */
	for (int i = 1; i < __argc; i++) {
		for (int j = 0; j < ARRAYSIZE(options); j++) {
			if (_tcscmp(__targv[i], options[j]) == 0) {
				switch (j) {
					case HELP:
						gHelpFlag = TRUE;
						break;
					case NOWINDOW:
						gNoConsoleFlag = TRUE;
						break;
					case NOSOUND:
						gNoSoundFlag = TRUE;
						break;
					case WPM: case PARIS:
						morse.dotLen = 60000 / (_wtoi(__targv[i + 1]) * 50);
						break;
					case STRING:
						gStringFlag = TRUE;
						gStringArg = i;
					default: break;
				}
			}
		}
	}

	/* Initialize console */
	if (gNoConsoleFlag == FALSE) {
		if (!AttachConsole(ATTACH_PARENT_PROCESS)) {
			AllocConsole();
		}
		freopen("CON", "r", stdin);
		freopen("CON", "w", stdout);
	}

	/* Get command line options */
	if (__argc <= 1) {
		if (gNoConsoleFlag == TRUE) {
			error_wondow(_T("No arguments specified"));
			return 0;
		} else {
			error_console(_T("No arguments specified"));
			goto CONSOLE_FINALIZE;
		}
	}

	/* Show help to console */
	if (gHelpFlag == TRUE) {
		if (gNoConsoleFlag == TRUE) {
			error_wondow(_T("You must remove -nowindow option to show help"));
			return 0;
		} else {
			_tprintf(_T(PROGRAM));
			_tprintf(_T("\n"));
			_tprintf(_T("options:\n"));
			for (int i = 0; i < ARRAYSIZE(options); i++) {
				_tprintf(_T("%s:\t%s\n"), options[i], helpMsg[i]);
			}
			goto CONSOLE_FINALIZE;
		}
	}

	/* No string error */
	if (gStringFlag == FALSE) {
		if (gNoConsoleFlag == TRUE) {
			error_wondow(_T("No input string"));
			return 0;
		} else {
			error_console(_T("No input string"));
			goto CONSOLE_FINALIZE;
		}
	}

	/* Output morse */
	int length = (int) _tcslen(__targv[__argc - 1]);
	for (int i = 0; i < length; i++) {
		OutputMorseConsoleAndSound((TCHAR) __targv[__argc - 1][i]);
	}

	/* Finalize console */
	CONSOLE_FINALIZE:
	if (gNoConsoleFlag == FALSE) {
		system("PAUSE");
		FreeConsole();
	}

	return 0;
}

void OutputMorseConsoleAndSound(TCHAR tc) {
	Morse& morse = Morse::GetInstance();
	int code = 0;

	switch (tc) {
		case _T('a'): case _T('A'): code = CW_CODE_A; break;
		case _T('b'): case _T('B'): code = CW_CODE_B; break;
		case _T('c'): case _T('C'): code = CW_CODE_C; break;
		case _T('d'): case _T('D'): code = CW_CODE_D; break;
		case _T('e'): case _T('E'): code = CW_CODE_E; break;
		case _T('f'): case _T('F'): code = CW_CODE_F; break;
		case _T('g'): case _T('G'): code = CW_CODE_G; break;
		case _T('h'): case _T('H'): code = CW_CODE_H; break;
		case _T('i'): case _T('I'): code = CW_CODE_I; break;
		case _T('j'): case _T('J'): code = CW_CODE_J; break;
		case _T('k'): case _T('K'): code = CW_CODE_K; break;
		case _T('l'): case _T('L'): code = CW_CODE_L; break;
		case _T('m'): case _T('M'): code = CW_CODE_M; break;
		case _T('n'): case _T('N'): code = CW_CODE_N; break;
		case _T('o'): case _T('O'): code = CW_CODE_O; break;
		case _T('p'): case _T('P'): code = CW_CODE_P; break;
		case _T('q'): case _T('Q'): code = CW_CODE_Q; break;
		case _T('r'): case _T('R'): code = CW_CODE_R; break;
		case _T('s'): case _T('S'): code = CW_CODE_S; break;
		case _T('t'): case _T('T'): code = CW_CODE_T; break;
		case _T('u'): case _T('U'): code = CW_CODE_U; break;
		case _T('v'): case _T('V'): code = CW_CODE_V; break;
		case _T('w'): case _T('W'): code = CW_CODE_W; break;
		case _T('x'): case _T('X'): code = CW_CODE_X; break;
		case _T('y'): case _T('Y'): code = CW_CODE_Y; break;
		case _T('z'): case _T('Z'): code = CW_CODE_Z; break;

		case _T('1'): code = CW_CODE_1; break;
		case _T('2'): code = CW_CODE_2; break;
		case _T('3'): code = CW_CODE_3; break;
		case _T('4'): code = CW_CODE_4; break;
		case _T('5'): code = CW_CODE_5; break;
		case _T('6'): code = CW_CODE_6; break;
		case _T('7'): code = CW_CODE_7; break;
		case _T('8'): code = CW_CODE_8; break;
		case _T('9'): code = CW_CODE_9; break;
		case _T('0'): code = CW_CODE_0; break;

		case _T('.'): code = CW_CODE_PER; break;
		case _T(','): code = CW_CODE_COM; break;
		case _T('?'): code = CW_CODE_QUE; break;
		case _T('-'): code = CW_CODE_HIF; break;
		case _T('/'): code = CW_CODE_SLA; break;
		case _T('@'): code = CW_CODE_ATM; break;
		case _T(' '): code = CW_CODE_SPACE; break;

		default: code = CW_CODE_UNKNOWN; break;
	}

	/* Output console */
	if (gNoConsoleFlag == FALSE) {
		TCHAR strBuf[32] = {0};
		morse.ToString(code, strBuf, ARRAYSIZE(strBuf));
		_tprintf(_T("%c: %s\n"), tc, strBuf);
	}

	/* Output sound */
	if (gNoSoundFlag == FALSE) {
		morse.ToSound(code);
	}
}
