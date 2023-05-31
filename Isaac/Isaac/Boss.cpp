#include "Boss.h"

Boss::Boss()
{
	dotWidth = 48;
	dotHeight = 33;
	active = true;
}

Boss::~Boss()
{

}

void Boss::Update()
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

int* Boss::getColorLine(int row)
{
	return leftIdle[row];
}

const char* Boss::getClassName()
{
	return typeid(this).name();
}