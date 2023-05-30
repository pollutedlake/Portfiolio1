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
	curHp = 3;
	walkIndex = 0;
	isAttack = false;
	isWalk = false;
	for(int k = 0; k < 7; k++)
	{
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < 29; j++)
			{
				leftIdleHead[i][j] = rightIdleHead[i][28 - j];
				leftAttackHead[i][j] = rightAttackHead[i][28 - j];
				if (i > 10)
				{
					continue;
				}
				leftIdleBody[k][i][j] = rightIdleBody[k][i][28 - j];
			}
		}
	}
}

Player::~Player()
{

}

void Player::move(int x, int y)
{	
	if(!isWalk)
	{
		isWalk = true;
		walkTime = clock();
	}
	idleTime = clock();
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
			if (isAttack)
			{
				return rightAttackHead[row];
			}
			return rightIdleHead[row];
		}
		else if (lookAt.first < 0)
		{
			if (isAttack)
			{
				return leftAttackHead[row];
			}
			return leftIdleHead[row];
		}
		else if(lookAt.second > 0)
		{
			if (isAttack)
			{
				return frontAttackHead[row];
			}
			return frontIdleHead[row];
		}
		return backIdleHead[row];
	}
	else
	{
		if (lookAt.first > 0)
		{
			return rightIdleBody[walkIndex][row - 26];
		}
		else if (lookAt.first < 0)
		{
			return leftIdleBody[walkIndex][row - 26];
		}
		return frontIdleBody[walkIndex][row - 26];
	}
}

void Player::Update()
{
	curTime = clock();
	if (isAttack)
	{
		if (curTime - attTime > 100)
		{
			isAttack = false;
		}
	}
	if (isWalk)
	{
		if (curTime - walkTime > 100)
		{
			walkIndex = (walkIndex + 1) % 7;
			walkTime = curTime;
		}
		if (curTime - idleTime > 300)
		{
			isWalk = false;
			walkIndex = 0;
		}
	}
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
		attTime = clock();
		isAttack = true;
		return projectile;
	}
}