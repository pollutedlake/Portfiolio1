#pragma once
#include <utility>
#include "Object.h"

using namespace std;
class Enemy : public Object
{
protected:
int curHp;
int maxHp;
int dir;

public:
	Enemy();
	~Enemy();
	void getDamage(int damage);
	int getDir() { return dir; }
};

