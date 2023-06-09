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
	price = 1;
}

Sucker::~Sucker()
{
	
}

// 상태와 위치 update
void Sucker::Update()
{
	// 상태 업데이트
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
			flyLeft[i][j] = flyRight[i][13 - j];
			flyLeft2[i][j] = flyRight2[i][13 - j];
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
	// 위치 업데이트
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

// 도트 색상 return
int* Sucker::getColorLine(int row)
{
	if(flyMotion)
	{
		if(dir.first > 0)
		{
			return isRed ? getRedLine(flyRight[row]) : flyRight[row];
		}
		else
		{
			return isRed ? getRedLine(flyLeft[row]) : flyLeft[row];
		}
	}
	if(dir.first > 0)
	{
		return isRed ? getRedLine(flyRight2[row]) : flyRight2[row];
	}
	else
	{
		return isRed ? getRedLine(flyLeft2[row]) : flyLeft2[row];
	}
}

// 빨개진 도트 색상 return
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