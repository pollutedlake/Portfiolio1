#include "Sucker.h"


Sucker::Sucker(int x, int y)
{
	position.first = x;
	position.second = y;
	active = true;
	dotHeight = 17;
	dotWidth = 14;
	oldTime = clock();
	flyRate = 500;
	flyMotion = 0;
	maxHp = 20;
	curHp = maxHp;
}

Sucker::~Sucker()
{
	
}

void Sucker::Update()
{
	curTime = clock();
	if (curTime - oldTime > flyRate)
	{
		oldTime = curTime;
		flyMotion = !flyMotion;
	}
}

const char* Sucker::getClassName()
{
	return typeid(this).name();
}

int* Sucker::getColorLine(int row)
{
	if(flyMotion)
	{
		return fly[row];
	}
	return fly2[row];
}