#pragma once
#include "Enemy.h"
#include <time.h>

class Boss : public Enemy
{
public:
	clock_t curTime;
	int rightIdle;
private:
	Boss();
	~Boss();

	void Update();
};

