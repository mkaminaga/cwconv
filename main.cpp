#include <windows.h>
#include "tchar.h"
#include "stdlib.h"

LPSTR tchar2cw(TCHAR c, LPSTR cw);

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,
		LPSTR lpCmdLine, int nCmdShow) {

	UNREFERENCED_PARAMETER(hInstance);
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	UNREFERENCED_PARAMETER(nCmdShow);

	INT argc = 0;
	LPTSTR* arg = 0;
	arg = CommandLineToArgvW(GetCommandLine(), &argc);

	/* Error message */
	if (argc <= 1) {
		MessageBox(NULL, TEXT("No arguments"), TEXT("error"), MB_OK);
		return -1;
	}

	int i = 0;
	int length = strlen(arg[1]);
	LPCSTR cw = 0;
	for (i = 0; i < length; i++) {
		tchar2cw(arg[1][i], cw);
		printf("%c: %s\n", arg[1][c], cw);
	}

	return 0;
}

LPSTR tchar2cw(TCHAR c, LPSTR cw) {
	switch(c) {
		/* Alphabets */
		case 'A': cw = TEXT("・－"); break;
		case 'B': cw = TEXT("－・・・"); break;
		case 'C': cw = TEXT("－・－・"); break;
		case 'D': cw = TEXT("－・・"); break;
		case 'E': cw = TEXT("・"); break;
		case 'F': cw = TEXT("・・－・"); break;
		case 'G': cw = TEXT("－－・"); break;
		case 'H': cw = TEXT("・・・・"); break;
		case 'I': cw = TEXT("・・"); break;
		case 'J': cw = TEXT("・－－－"); break;
		case 'K': cw = TEXT("－・－"); break;
		case 'L': cw = TEXT("・－・・"); break;
		case 'M': cw = TEXT("－－"); break;
		case 'N': cw = TEXT("－・"); break;
		case 'O': cw = TEXT("－－－"); break;
		case 'P': cw = TEXT("・－－・"); break;
		case 'Q': cw = TEXT("－－・－"); break;
		case 'R': cw = TEXT("・－・"); break;
		case 'S': cw = TEXT("・・・"); break;
		case 'T': cw = TEXT("－"); break;
		case 'U': cw = TEXT("・・－"); break;
		case 'V': cw = TEXT("・・・－"); break;
		case 'W': cw = TEXT("・－－"); break;
		case 'X': cw = TEXT("－・・－"); break;
		case 'Y': cw = TEXT("－・－－"); break;
		case 'Z': cw = TEXT("－－・・"); break;

		/* Numbers */
		case '1': cw = TEXT("・－－－－"); break;
		case '2': cw = TEXT("・・－－－"); break;
		case '3': cw = TEXT("・・・－－"); break;
		case '4': cw = TEXT("・・・・－"); break;
		case '5': cw = TEXT("・・・・・"); break;
		case '6': cw = TEXT("－・・・・"); break;
		case '7': cw = TEXT("－－・・・"); break;
		case '8': cw = TEXT("－－－・・"); break;
		case '9': cw = TEXT("－－－－・"); break;
		case '0': cw = TEXT("－－－－－"); break;

		/* Simbols */
		case '.': cw = TEXT("・－・－・－");
		case ',': cw = TEXT("－－・・－－");
		case '?': cw = TEXT("・・－－・・");
		case '-': cw = TEXT("－・・・・－");
		case '/': cw = TEXT("－・・－・");
		case '@': cw = TEXT("・－－・－・");
		case ' ': cw = TEXT("　　　");

		/* Nothing */
		default: break;
	}
	return cw;
}
