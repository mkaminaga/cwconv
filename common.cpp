#include "common.h"

void error_console(LPTSTR msg) {
	_tprintf(_T("ERROR: %s\n"), msg);
}

void error_wondow(LPTSTR msg) {
	TCHAR temp[64] = {0};
	_stprintf(temp, _T("ERROR: %s"), msg);
	MessageBox(NULL, temp, _T("cwconv"), NULL);
}
