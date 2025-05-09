#pragma once
#ifndef FORMATO_H
#define FORMATO_H

#include <Windows.h>

inline void gotoxy(short x, short y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

inline void color(WORD col)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}

#endif // !FORMATO_H