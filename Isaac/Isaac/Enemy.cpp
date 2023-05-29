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
	if (curHp <= 0)
	{
		curHp = 0;
		active = false;
	}
}