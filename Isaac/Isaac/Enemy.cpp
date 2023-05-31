#include "Enemy.h"

Enemy::Enemy()
{
	
}

Enemy::~Enemy()
{

}

void Enemy::getDamage(int damage)
{
	curHp -= damage;
	isRed = true;
	if (!isTwinkle)
	{
		redTime = clock();
	}
	isTwinkle = true;
	twinkleTime = clock();
	if (curHp <= 0)
	{
		curHp = 0;
		active = false;
	}
}

void Enemy::setDirToPlayer(pair<int, int> playerPos)
{
	dir.first =  playerPos.first - position.first;
	dir.second = playerPos.second - position.second;
	if (abs(dir.first) < 2)
	{
		dir.first = 0;
	}
	if (abs(dir.second) < 2)
	{
		dir.second = 0;
	}
}