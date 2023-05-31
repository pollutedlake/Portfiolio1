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
	att = 1;
	isRed = false;
	isTwinkle = false;
	velocity = 2;
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
	if (dir.first == 0 && dir.second == 0)
	{
		return;
	}
	if (dir.first == 0 && dir.second != 0)
	{
		setPosition(make_pair(getPosition().first, getPosition().second + (dir.second / abs(dir.second)) * velocity));
	}
	else if (dir.second == 0)
	{
		setPosition(make_pair(getPosition().first + (dir.first / abs(dir.first)) * velocity, getPosition().second));
	}
	else if (abs(dir.first) >= abs(dir.second))
	{
		setPosition(make_pair(getPosition().first, getPosition().second + (dir.second / abs(dir.second)) * velocity));
	}
	else
	{
		setPosition(make_pair(getPosition().first + (dir.first / abs(dir.first)) * velocity, getPosition().second));
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
		return isRed ? getRedLine(flyRight[row]) : flyRight[row];
	}
	return isRed ? getRedLine(flyRight2[row]) : flyRight2[row];
}

int* Sucker::getRedLine(int* source)
{
	int red[14];
	for (int i = 0; i < 14; i++)
	{
		if (source[i] == 8)
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