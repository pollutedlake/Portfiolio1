#include "Player.h"

Player::Player()
{	
	position = make_pair(160, 90);
	motion = FRONTIDLE;
	dotWidth = 29;
	dotHeight = 37;
	speed = 5;
	lookAt = make_pair(0, 1);
	active = true;
	oldTime = clock();
	attRate = 1500;
	att = 10;
	maxHp = 6;
	curHp = maxHp;
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 29; j++)
		{
			leftIdleHead[i][j] = rightIdleHead[i][28 - j];
			if (i > 10)
			{
				continue;
			}
			leftIdleBody[i][j] = rightIdleBody[i][28 - j];
		}
	}
}

Player::~Player()
{

}

void Player::move(int x, int y)
{	
	if((position.first > 20 || x >= 0) && (position.first < 271 || x <= 0) )
	{
		position.first += x * speed;
	}
	if((position.second > 15 || y >= 0) && (position.second < 128 || y <= 0))
	{
		position.second += y * speed;
	}
	lookAt = make_pair(x, y);
}

int* Player::getColorLine(int row)
{
	if (row < 26)
	{
		if (lookAt.first > 0)
		{
			return rightIdleHead[row];
		}
		else if (lookAt.first < 0)
		{
			return leftIdleHead[row];
		}
		else if(lookAt.second > 0)
		{
			return frontIdleHead[row];
		}
		return backIdleHead[row];
	}
	else
	{
		if (lookAt.first > 0)
		{
			return rightIdleBody[row - 26];
		}
		else if (lookAt.first < 0)
		{
			return leftIdleBody[row - 26];
		}
		return frontIdleBody[row - 26];
	}
}

void Player::Update()
{
	curTime = clock();
}

const char* Player::getClassName()
{
	return typeid(this).name();
}

Projectile* Player::attack()
{
	if(curTime - oldTime > attRate)
	{
		Projectile* projectile = new Projectile(position.first + 11 + (lookAt.first > 0 ? 19 : (18 * lookAt.first)), position.second + 12 + (lookAt.second > 0 ? 22 : (19 * lookAt.second)), lookAt);
		oldTime = curTime;
		return projectile;
	}
}