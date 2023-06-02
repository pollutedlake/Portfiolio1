#include "DoubleBuffering.h"
#include<iostream>
using namespace std;

DoubleBuffering::DoubleBuffering()
{
	g_nScreenIndex = 0;
}

DoubleBuffering::~DoubleBuffering()
{

}

void DoubleBuffering::screenInit()
{
	CONSOLE_CURSOR_INFO cci;

	g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(g_hScreen[0], &cci);
	SetConsoleCursorInfo(g_hScreen[1], &cci);
}

void DoubleBuffering::screenFlipping()
{
	SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
	g_nScreenIndex = !g_nScreenIndex;
}

void DoubleBuffering::screenClear()
{
	COORD Coor = { 0, 0 };
	DWORD dw;
	FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', 600 * 600, Coor, &dw);
}

void DoubleBuffering::screenRelease()
{
	CloseHandle(g_hScreen[0]);
	CloseHandle(g_hScreen[1]);
}

void DoubleBuffering::printLine(int x, int y, int color, const char* string)
{
	DWORD dw;
	COORD CursorPosition = { x, y };
	setColor(color, color);
	SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
	WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string), &dw, NULL);
}

void DoubleBuffering::screenPrint(int screen[SCREENHEIGHT][SCREENWIDTH] )
{
	for (int i = 0; i < SCREENHEIGHT; i++)
	{
		int oldColor = 99;
		char str[SCREENWIDTH * 2 + 1] = "";
		int start = 0;
		for (int j = 0; j < SCREENWIDTH; j++)
		{
			int curColor = screen[i][j];
			if (oldColor != curColor || j == SCREENWIDTH - 1) {
				if (oldColor == 99)
				{
					oldColor = curColor;
					strcat_s(str, sizeof(str), "■");
					continue;
				}
				printLine(start, i, oldColor, str);
				start += strlen(str);
				oldColor = curColor;
				str[0] = '\0';
			}
			strcat_s(str, sizeof(str), "■");
		}
	}
}

void DoubleBuffering::setColor(int font, int background)
{
	int color = font + background * 16;
	SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], color);
}

void DoubleBuffering::changeFontSize(int fontSize)
{
	CONSOLE_FONT_INFOEX info = {0};
	info.cbSize = sizeof(info);
	info.dwFontSize.Y = fontSize;
	info.FontWeight = FW_NORMAL;
	wcscpy_s(info.FaceName, L"Lucida Console");
	SetCurrentConsoleFontEx(g_hScreen[g_nScreenIndex], NULL, &info);
}