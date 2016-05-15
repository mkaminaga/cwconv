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
		case 'a':
		case 'A': *cw = _T(". - "); break;
		case 'b':
		case 'B': *cw = _T("- . . . "); break;
		case 'c':
		case 'C': *cw = _T("- . - . "); break;
		case 'd':
		case 'D': *cw = _T("- . . "); break;
		case 'e':
		case 'E': *cw = _T(". "); break;
		case 'f':
		case 'F': *cw = _T(". . - . "); break;
		case 'g':
		case 'G': *cw = _T("- - . "); break;
		case 'h':
		case 'H': *cw = _T(". . . . "); break;
		case 'i':
		case 'I': *cw = _T(". . "); break;
		case 'j':
		case 'J': *cw = _T(". - - - "); break;
		case 'k':
		case 'K': *cw = _T("- . - "); break;
		case 'l':
		case 'L': *cw = _T(". - . . "); break;
		case 'm':
		case 'M': *cw = _T("- - "); break;
		case 'n':
		case 'N': *cw = _T("- . "); break;
		case 'o':
		case 'O': *cw = _T("- - - "); break;
		case 'p':
		case 'P': *cw = _T(". - - . "); break;
		case 'q':
		case 'Q': *cw = _T("- - . - "); break;
		case 'r':
		case 'R': *cw = _T(". - . "); break;
		case 's':
		case 'S': *cw = _T(". . . "); break;
		case 't':
		case 'T': *cw = _T("- "); break;
		case 'u':
		case 'U': *cw = _T(". . - "); break;
		case 'v':
		case 'V': *cw = _T(". . . - "); break;
		case 'w':
		case 'W': *cw = _T(". - - "); break;
		case 'x':
		case 'X': *cw = _T("- . . - "); break;
		case 'y':
		case 'Y': *cw = _T("- . - - "); break;
		case 'z':
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
