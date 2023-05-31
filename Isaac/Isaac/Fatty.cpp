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
	att = 1;
	velocity = 2;
}

Fatty::~Fatty()
{

}

int* Fatty::getColorLine(int row)
{
	if (row < 21)
	{
		return isRed ? getRedLine(frontHead[row]) : frontHead[row];
	}
	else
	{
		return isRed ? getRedLine(frontBody[row - 21]) : frontBody[row - 21];
	}
}

const char* Fatty::getClassName()
{
	return typeid(this).name();
}

void Fatty::Update()
{
	curTime = clock();
	if (curTime - twinkleTime > 2000)
	{
		isTwinkle = false;
		isRed = false;
	}
	if (isTwinkle && (curTime - redTime > 200))
	{
		isRed = !isRed;
		redTime = curTime;
	}
}

int* Fatty::getRedLine(int* source)
{
	int red[32];
	for (int i = 0; i < 32; i++)
	{
		if (source[i] == 14)
		{
			red[i] = 4;
		}
		else
		{
			red[i] = source[i];
		}
	}
	return red;
}