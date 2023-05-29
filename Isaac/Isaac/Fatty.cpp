#include "Fatty.h"

Fatty::Fatty(int x, int y)
{
	dotWidth = 32;
	dotHeight = 35;
	active = true;
	position.first = x;
	position.second = y;
	maxHp = 40;
	curHp = maxHp;
}

Fatty::~Fatty()
{

}

int* Fatty::getColorLine(int row)
{
	if (row < 21)
	{
		return frontHead[row];
	}
	else
	{
		return frontBody[row - 21];
	}
}

const char* Fatty::getClassName()
{
	return typeid(this).name();
}