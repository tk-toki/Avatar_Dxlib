#include "DxLib.h"
#include "Debug.h"

void Debug::Log(const TCHAR* text) {
	DrawString(0, 0, text, GetColor(255, 255, 255));
}

void Debug::Log(bool flag) {
	TCHAR str[8];
	TCHAR* pStr = str;
	if (flag) {
		_stprintf_s(str, _T("true"));
	}
	else {
		_stprintf_s(str, _T("false"));
	}
	DrawString(0, 10, pStr, GetColor(255, 255, 255));
}