#include "DxLib.h"
#include "Debug.h"

void Debug::Log(const TCHAR* text) {
	DrawString(0, 0, text, GetColor(255, 255, 255));
}

void Debug::LogWarning(const TCHAR* text) {
	DrawString(0, 0, text, GetColor(154, 205, 50));
}

void Debug::LogError(const TCHAR* text) {
	DrawString(0, 0, text, GetColor(255, 0, 0));
}