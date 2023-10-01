#pragma once

static class Debug {
public:
	static void Log(const TCHAR* text);
	static void LogWarning(const TCHAR* text);
	static void LogError(const TCHAR* text);
private:
};