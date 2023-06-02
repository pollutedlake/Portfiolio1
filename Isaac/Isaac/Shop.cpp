#include "Shop.h"

Shop::Shop()
{
	screen = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	font = CreateFont()
}

Shop::~Shop()
{

}