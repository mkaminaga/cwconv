#include "common.h"
#include "morse.h"

void Morse::__InitMidiDevice__() {
	midiOutOpen(&hMidiOut, MIDI_MAPPER, 0, 0, 0);
}

void Morse::__ReleaseMidiDevice__() {
	midiOutReset(hMidiOut);
	midiOutClose(hMidiOut);
}

void Morse::ToString(int code, LPTSTR strOut, int strLen) {
	int i = 0;
	int temp = 0;

	/* Exception */
	switch (code) {
		case CW_CODE_SPACE:
			_tcscpy_s(strOut, strLen, _T(" "));
			return;
		case CW_CODE_UNKNOWN:
			_tcscpy_s(strOut, strLen, _T("<?>"));
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
		if (i * 2 > strLen)
			break; //out of array
		temp = code >> (4 * (7 - i));
		temp &= 0xf;
		switch (temp) {
			case 1:
				strOut[i * 2] = '.';
				break;
			case 3:
				strOut[i * 2] = '-';
				break;
			default: return;
		}
		strOut[(i * 2) + 1] = ' ';
	}
}

void Morse::ToSound(int code) {
	int i = 0;
	int temp = 0;

	/* Exception */
	switch (code) {
		case CW_CODE_SPACE:
		case CW_CODE_UNKNOWN:
			Sleep(this->dotLen * 6); //word separator
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
				midiOutShortMsg(hMidiOut, 0x007f6190); /* Start */
				Sleep(this->dotLen);
				midiOutShortMsg(hMidiOut, 0x007f6180); /* Stop */
				break;
			case 3:
				midiOutShortMsg(hMidiOut, 0x007f6190); /* Start */
				Sleep(this->dotLen * 3);
				midiOutShortMsg(hMidiOut, 0x007f6180); /* Stop */
				break;
			default: break;
		}
		Sleep(this->dotLen); //dot separator
	}
	Sleep(this->dotLen * 3); //charctor separator
}

void Morse::OutputTerminalStringAndSound(int code, TCHAR c) {
	TCHAR strBuf[32] = {0};

	this->ToString(code, strBuf, ARRAYSIZE(strBuf));
	_tprintf(_T("%c: %s\n"), c, strBuf);
	this->ToSound(code);
	Sleep(this->dotLen);
}
