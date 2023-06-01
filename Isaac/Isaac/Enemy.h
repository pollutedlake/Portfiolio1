#pragma once
#include <utility>
#include <time.h>
#include "Object.h"

using namespace std;
class Enemy : public Object
{
protected:
int curHp;
int maxHp;
pair<int, int> dir;
int att;
bool isRed;
bool isTwinkle;
clock_t twinkleTime, redTime;
int velocity;
int price;

public:
	Enemy();
	~Enemy();
	void getDamage(int damage);
	int getAtt() { return att; }
	int getPrice() { return price; }
	pair<int, int> getDir() { return dir; }
	void setDirToPlayer(pair<int, int> playerPos);
};

