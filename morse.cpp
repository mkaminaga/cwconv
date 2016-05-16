#include "common.h"
#include "morse.h"

void morseCodeToString(int code, LPTSTR morse, int count) {
	int i = 0;
	int temp = 0;

	/* Exception */
	switch (code) {
		case CW_CODE_SPACE:
			// _tcscpy_s(morse, count, _T(" "));
			return;
		case CW_CODE_UNKNOWN:
			// _tcscpy_s(morse, count, _T("???"));
			return;
		default:
			break;
	}

	/* Adjust to left */
	while (!(code & 0xf0000000)) {
		code <<= 4;
		i++;
		if (i > 8)
			break; //infint loop escape
	}

	/* Conversion */
	for (i = 0; i < 8; i++) {
		if (i * 2 > count)
			break; //out of array
		temp = code >> (4 * (7 - i));
		temp &= 0xf;
		switch (temp) {
			case 1:
				morse[i * 2] = '.';
				break;
			case 3:
				morse[i * 2] = '-';
				break;
			default: return;
		}
		morse[(i * 2) + 1] = ' ';
	}
}

void morseCodeToSound(int code, int dotLen) {
	int i = 0;
	int temp = 0;

	/* Exception */
	switch (code) {
		case CW_CODE_SPACE:
			Sleep(dotLen * 3);
			return;
		case CW_CODE_UNKNOWN:
			Sleep(dotLen * 3);
			return;
		default:
			break;
	}

	/* Adjust to left */
	while (!(code & 0xf0000000)) {
		code <<= 4;
		i++;
		if (i > 8)
			break; //infint loop escape
	}

	/* Conversion */
	for (i = 0; i < 8; i++) {
		temp = code >> (4 * (7 - i));
		temp &= 0xf;
		switch (temp) {
			case 1:
				Beep(CW_BEEP_FREQ, dotLen);
				Sleep(dotLen);
				break;
			case 3:
				Beep(CW_BEEP_FREQ, dotLen * 3);
				Sleep(dotLen * 3);
				break;
			default: return;
		}
	}
}
