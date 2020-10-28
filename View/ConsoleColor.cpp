//ConsoleColor.cpp
#include "ConsoleColor.h"
#include <windows.h>

unsigned short getConsoleColor()
{
	auto info = CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	return info.wAttributes;
}

void setConsoleColor(unsigned short c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}