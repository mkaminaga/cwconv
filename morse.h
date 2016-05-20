/**
 * @file morse.h
 * @brief Midi related information
 * @author Mamoru Kaminaga
 * @date 2016-05-20 19:47:50
 * */
#pragma once
#include "common.h"

#define MIDIMSG(status,channel,data1,data2) ((DWORD)((status<<4)|channel|(data1<<8)|(data2<<16)))

#define CW_CODE_A	0x13
#define CW_CODE_B	0x311
#define CW_CODE_C	0x3131
#define CW_CODE_D	0x311
#define CW_CODE_E	0x1
#define CW_CODE_F	0x1131
#define CW_CODE_G	0x331
#define CW_CODE_H	0x1111
#define CW_CODE_I	0x11
#define CW_CODE_J	0x1333
#define CW_CODE_K	0x313
#define CW_CODE_L	0x1311
#define CW_CODE_M	0x33
#define CW_CODE_N	0x31
#define CW_CODE_O	0x333
#define CW_CODE_P	0x1331
#define CW_CODE_Q	0x3313
#define CW_CODE_R	0x131
#define CW_CODE_S	0x111
#define CW_CODE_T	0x3
#define CW_CODE_U	0x113
#define CW_CODE_V	0x1113
#define CW_CODE_W	0x133
#define CW_CODE_X	0x3113
#define CW_CODE_Y	0x3133
#define CW_CODE_Z	0x3311

#define CW_CODE_1	0x13333
#define CW_CODE_2	0x11333
#define CW_CODE_3	0x11133
#define CW_CODE_4	0x11113
#define CW_CODE_5	0x11111
#define CW_CODE_6	0x31111
#define CW_CODE_7	0x33111
#define CW_CODE_8	0x33311
#define CW_CODE_9	0x33331
#define CW_CODE_0	0x33333

#define CW_CODE_PER	0x131313
#define CW_CODE_COM	0x331133
#define CW_CODE_QUE	0x113311
#define CW_CODE_SEP	0x31113
#define CW_CODE_HIF	0x311113
#define CW_CODE_SLA	0x31131
#define CW_CODE_ATM	0x133131
#define CW_CODE_FIX	0x11111111
#define CW_CODE_SPACE	0xaaaaaaaa
#define CW_CODE_UNKNOWN	0xbbbbbbbb

class Morse {
	private:
		HMIDIOUT hMidiOut;
		void __InitMidiDevice__();
		void __ReleaseMidiDevice__();

		Morse() {
			this->__InitMidiDevice__();
			this->dotLen = 50;
	   	}
		~Morse() {
			this->__ReleaseMidiDevice__();
	   	}
	public:
		static Morse& GetInstance() {
			static Morse singleton;
			return singleton;
		}
		int dotLen;

		void ToString(int code, LPTSTR strOut, int strLen);
		void ToSound(int code);
};
