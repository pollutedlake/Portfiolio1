#include "Player.h"

Player::Player()
{	
	position = make_pair(160, 90);
	dotWidth = 29;
	dotHeight = 37;
	speed = 5;
	lookAt = make_pair(0, 1);
	active = true;
	oldTime = clock();
	attRate = 1000;
	att = 10;
	maxHp = 6;
	curHp = maxHp;
	walkIndex = 0;
	isAttack = false;
	isWalk = false;
	invincibility = false;
	isRed = false;
	money = 0;
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
				return isRed ? getRedPlayer(rightAttackHead[row]) : rightAttackHead[row];
			}
			return isRed ? getRedPlayer(rightIdleHead[row]) : rightIdleHead[row];
		}
		else if (lookAt.first < 0)
		{
			if (isAttack)
			{
				return isRed ? getRedPlayer(leftAttackHead[row]) : leftAttackHead[row];
			}
			return isRed ? getRedPlayer(leftIdleHead[row]) : leftIdleHead[row];
		}
		else if(lookAt.second > 0)
		{
			if (isAttack)
			{
				return isRed ? getRedPlayer(frontAttackHead[row]) : frontAttackHead[row];
			}
			return isRed ? getRedPlayer(frontIdleHead[row]) : frontIdleHead[row];
		}
		return isRed ? getRedPlayer(backIdleHead[row]) : backIdleHead[row];
	}
	else
	{
		if (lookAt.first > 0)
		{
			return isRed ? getRedPlayer(rightIdleBody[walkIndex][row - 26]) : rightIdleBody[walkIndex][row - 26];
		}
		else if (lookAt.first < 0)
		{
			return isRed ? getRedPlayer(leftIdleBody[walkIndex][row - 26]) : leftIdleBody[walkIndex][row - 26];
		}
		return isRed ? getRedPlayer(frontIdleBody[walkIndex][row - 26]) : frontIdleBody[walkIndex][row - 26];
	}
}

int* Player::getRedPlayer(int* source)
{
	int red[29];
	for (int i = 0; i < 29; i++)
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
	if (invincibility)
	{
		if (curTime - twinkleTime > 200)
		{
			twinkleTime = curTime;
			isRed = !isRed;
		}
		if (curTime - invincibilityTime > 2000)
		{
			invincibility = false;
			isRed = false;
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

void Player::getDamage(int damage)
{
	if (!invincibility)
	{
		curHp -= damage;
		invincibility = true;
		twinkleTime = clock();
		isRed = true;
		invincibilityTime = clock();
		if (curHp <= 0)
		{
			curHp = 0;
		}
	}
}

void Player::putInventory(Equipment* equipment)
{
	inventory.push_back(equipment);
}

void Player::takeOutEquipment(int index)
{
	inventory.erase(inventory.begin() + index);
}

void Player::wearEquipment(int index)
{
	Equipment* tempE = inventory.at(index);
	if(equipment != nullptr)
	{
		putInventory(equipment);
		switch (equipment->getEquipmentId())
		{
		case 0:
			maxHp -= 2;
			if (curHp > maxHp)
			{
				curHp = maxHp;
			}
			break;
		case 1:
			att -= 10;
			break;
		case 2:
			speed /= 2;
			break;
		case 3:
			attRate *= 2;
			break;
		}
	}
	switch (tempE->getEquipmentId())
	{
	case 0:
		maxHp += 2;
		curHp += 2;
		break;
	case 1:
		att += 10;
		break;
	case 2:
		speed *= 2;
		break;
	case 3:
		attRate /= 2;
		break;
	}
	equipment = tempE;
	takeOutEquipment(index);
}