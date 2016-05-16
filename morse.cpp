#include "common.h"
#include "morse.h"

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
		temp &= 0xf;
		switch (temp) {
			case 1:
				Beep(CW_BEEP_FREQ, dot);
				break;
			case 3:
				Beep(CW_BEEP_FREQ, dot * 3);
				break;
			default: return;
		}
	}
}
