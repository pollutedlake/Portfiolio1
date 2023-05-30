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
	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			flyLeft[i][j] = flyRight[i][j];
			flyLeft2[i][j] = flyRight2[i][j];
		}
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
		return flyRight[row];
	}
	return flyRight2[row];
}