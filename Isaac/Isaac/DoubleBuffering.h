#pragma once
#include<Windows.h>
#include<string>

#define SCREENWIDTH		320
#define SCREENHEIGHT	180

class DoubleBuffering {
private:
	HANDLE g_hScreen[2];
	int g_nScreenIndex;
	int screenWidth = SCREENWIDTH;
	int screenHeight = SCREENHEIGHT;
	
public:
	DoubleBuffering();
	~DoubleBuffering();

	void screenInit();
	void screenFlipping();
	void screenClear();
	void screenRelease();
	void screenPrint(int screen[SCREENHEIGHT][SCREENWIDTH]);
	void printLine(int x, int y, int color, const char* string);
	void setColor(int font, int background);
};

