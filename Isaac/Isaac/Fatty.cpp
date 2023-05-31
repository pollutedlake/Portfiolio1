#include "Fatty.h"

Fatty::Fatty(int x, int y)
{
	dotWidth = 32;
	dotHeight = 40;
	active = true;
	position.first = x;
	position.second = y;
	maxHp = 40;
	curHp = maxHp;
	att = 1;
	velocity = 2;
	walkIndex = 0;
	isWalk = false;
	check = false;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			for (int k = 0; k < 32; k++)
			{
				leftBody[i][j][k] = rightBody[i][j][31-k];
			}
		}
	}
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
		if (side)
		{
			if (dir.first < 0)
			{
				return isRed ? getRedLine(leftBody[walkIndex][row - 21]) : leftBody[walkIndex][row - 21];
			}
			return isRed ? getRedLine(rightBody[walkIndex][row - 21]) : rightBody[walkIndex][row - 21];
		}
		return isRed ? getRedLine(frontBody[walkIndex][row - 21]) : frontBody[walkIndex][row - 21];
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
	if (dir.first == 0 && dir.second == 0)
	{
		return;
	}
	if (!isWalk)
	{
		walkTime = curTime;
		isWalk = true;
	}
	if (isWalk)
	{
		if (curTime - walkTime > 100)
		{
			walkTime = curTime;
			if (walkIndex == 0 && !check)
			{
				walkIndex = 1;
				check = !check;
				increase = 1;
			}
			else if (walkIndex == 0 && check)
			{
				walkIndex = 4;
				check = !check;
				increase = 1;
			}
			else
			{
				if (walkIndex == 3 || walkIndex == 6)
				{
					increase = -1;
				}
				if (walkIndex == 4 && increase == -1)
				{
					walkIndex = 0;
				}
				else
				{
					walkIndex += increase;
				}
			}
		}
	}
	if (dir.first == 0 && dir.second != 0)
	{
		side = false;
		setPosition(make_pair(getPosition().first, getPosition().second + (dir.second / abs(dir.second)) * velocity));
	}
	else if (dir.second == 0)
	{
		side = true;
		setPosition(make_pair(getPosition().first + (dir.first / abs(dir.first)) * velocity, getPosition().second));
	}
	else if (abs(dir.first) >= abs(dir.second))
	{
		side = false;
		setPosition(make_pair(getPosition().first, getPosition().second + (dir.second / abs(dir.second)) * velocity));
	}
	else
	{
		side = true;
		setPosition(make_pair(getPosition().first + (dir.first / abs(dir.first)) * velocity, getPosition().second));
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