#include <windows.h>
#include "tchar.h"
#include "stdio.h"

LPTSTR tchar2cw(TCHAR c, LPTSTR* cw);

int _tmain(int argc, TCHAR* argv[]) {

	/* Error message */
	if (argc <= 1) {
		MessageBox(NULL, _T("No arguments"), _T("error"), MB_OK);
		return -1;
	}

	/* string to cw code */
	int i = 0;
	int length = (int) ::_tcslen(argv[1]); //size_t -> int
	LPTSTR cw = 0;
	for (i = 0; i < length; i++) {
		tchar2cw(argv[1][i], &cw);
		_tprintf(_T("%c: %s\n"), argv[1][i], cw);
	}

	return 0;
}

LPTSTR tchar2cw(TCHAR c, LPTSTR* cw) {
	switch(c) {
		/* Alphabets */
		case 'A': *cw = _T(". - "); break;
		case 'B': *cw = _T("- . . . "); break;
		case 'C': *cw = _T("- . - . "); break;
		case 'D': *cw = _T("- . . "); break;
		case 'E': *cw = _T(". "); break;
		case 'F': *cw = _T(". . - . "); break;
		case 'G': *cw = _T("- - . "); break;
		case 'H': *cw = _T(". . . . "); break;
		case 'I': *cw = _T(". . "); break;
		case 'J': *cw = _T(". - - - "); break;
		case 'K': *cw = _T("- . - "); break;
		case 'L': *cw = _T(". - . . "); break;
		case 'M': *cw = _T("- - "); break;
		case 'N': *cw = _T("- . "); break;
		case 'O': *cw = _T("- - - "); break;
		case 'P': *cw = _T(". - - . "); break;
		case 'Q': *cw = _T("- - . - "); break;
		case 'R': *cw = _T(". - . "); break;
		case 'S': *cw = _T(". . . "); break;
		case 'T': *cw = _T("- "); break;
		case 'U': *cw = _T(". . - "); break;
		case 'V': *cw = _T(". . . - "); break;
		case 'W': *cw = _T(". - - "); break;
		case 'X': *cw = _T("- . . - "); break;
		case 'Y': *cw = _T("- . - - "); break;
		case 'Z': *cw = _T("- - . . "); break;

		/* Numbers */
		case '1': *cw = _T(". - - - - "); break;
		case '2': *cw = _T(". . - - - "); break;
		case '3': *cw = _T(". . . - - "); break;
		case '4': *cw = _T(". . . . - "); break;
		case '5': *cw = _T(". . . . . "); break;
		case '6': *cw = _T("- . . . . "); break;
		case '7': *cw = _T("- - . . . "); break;
		case '8': *cw = _T("- - - . . "); break;
		case '9': *cw = _T("- - - - . "); break;
		case '0': *cw = _T("- - - - - "); break;

		/* Simbols */
		case '.': *cw = _T(". - . - . - ");
		case ',': *cw = _T("- - . . - - ");
		case '?': *cw = _T(". . - - . . ");
		case '-': *cw = _T("- . . . . - ");
		case '/': *cw = _T("- . . - . ");
		case '@': *cw = _T(". - - . - . ");
		case ' ': *cw = _T("   ");

		/* Nothing */
		default: *cw = _T("?????"); break;
	}
	return *cw;
}
