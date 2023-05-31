#pragma once
#include "Enemy.h"
#include <time.h>

class Boss : public Enemy
{
private:
	clock_t curTime;
	int leftIdle[33][48] = { {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	99,	99,	99,	99,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	99,	99,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	99,	99,	99,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	99,	99,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	99,	99,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	99,	99,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	99,	0,	14,	14,	14,	0,	0,	0,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	0,	0,	0,	0,	0,	14,	14,	14,	0,	0,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	99,	0,	14,	14,	14,	14,	0,	15,	15,	0,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	0,	0,	0,	15,	0,	0,	0,	0,	14,	14,	14,	14,	14,	0,	0,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	0,	0,	14,	14,	14,	0,	15,	15,	0,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	15,	15,	0,	0,	0,	0,	0,	14,	14,	14,	14,	14,	14,	0,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	0,	14,	14,	14,	14,	0,	0,	0,	0,	0,	14,	14,	14,	14,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	0,	0,	0,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	0,	99,	99,	99,	99},
							 {99,	99,	99,	0,	14,	14,	14,	14,	14,	0,	0,	0,	0,	0,	14,	14,	14,	0,	4,	0,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	0,	0,	0,	0,	0,	0,	14,	14,	14,	14,	14,	14,	14,	0,	0,	99,	99,	99},
							 {99,	99,	99,	0,	14,	14,	14,	14,	14,	0,	0,	0,	0,	14,	14,	14,	14,	0,	4,	4,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	14,	14,	14,	14,	14,	14,	0,	0,	99,	99,	99},
							 {99,	99,	0,	0,	14,	14,	14,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	0,	4,	4,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	14,	14,	14,	14,	14,	14,	0,	0,	99,	99},
							 {99,	0,	0,	14,	14,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	4,	4,	4,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	14,	14,	14,	14,	14,	14,	14,	14,	0,	99,	99},
							 {99,	0,	0,	14,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	4,	4,	4,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	14,	14,	14,	14,	14,	14,	14,	0,	99,	99},
							 {99,	0,	14,	14,	14,	14,	0,	0,	0,	0,	14,	14,	14,	14,	14,	0,	4,	4,	4,	0,	0,	14,	14,	14,	14,	14,	14,	14,	0,	0,	14,	0,	0,	0,	0,	0,	4,	14,	14,	0,	0,	14,	14,	14,	14,	14,	0,	99},
							 {99,	0,	14,	14,	14,	14,	0,	4,	4,	4,	0,	14,	14,	14,	0,	0,	4,	4,	4,	0,	0,	0,	14,	14,	14,	14,	0,	0,	4,	4,	0,	4,	4,	0,	4,	4,	0,	14,	14,	14,	14,	0,	0,	14,	14,	14,	0,	99},
							 {99,	0,	14,	0,	14,	14,	0,	4,	4,	0,	0,	0,	0,	0,	0,	0,	4,	4,	4,	0,	0,	0,	0,	0,	0,	0,	4,	4,	4,	0,	4,	15,	15,	15,	0,	4,	0,	0,	0,	14,	14,	4,	4,	14,	14,	14,	0,	99},
							 {0,	14,	14,	14,	14,	14,	0,	0,	0,	15,	15,	0,	4,	4,	0,	15,	0,	0,	0,	0,	0,	0,	0,	4,	4,	4,	4,	4,	4,	0,	15,	15,	15,	15,	15,	0,	4,	4,	0,	14,	14,	0,	4,	14,	14,	14,	0,	0},
							 {0,	14,	14,	0,	14,	14,	0,	0,	0,	15,	15,	0,	4,	0,	15,	15,	0,	0,	0,	0,	0,	0,	0,	0,	4,	4,	4,	4,	0,	15,	15,	15,	15,	15,	15,	0,	4,	4,	0,	14,	14,	14,	0,	14,	14,	14,	0,	0},
							 {0,	14,	14,	14,	14,	14,	0,	0,	0,	0,	0,	0,	0,	0,	15,	15,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	15,	15,	15,	15,	15,	15,	0,	4,	4,	0,	14,	14,	14,	0,	14,	14,	14,	0,	0},
							 {0,	14,	14,	14,	14,	14,	0,	0,	0,	0,	0,	0,	0,	0,	15,	15,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	15,	15,	15,	15,	15,	0,	4,	4,	0,	14,	14,	14,	14,	14,	14,	14,	0,	0},
							 {0,	14,	14,	14,	14,	14,	14,	0,	0,	0,	15,	15,	15,	0,	0,	0,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	0,	0,	15,	15,	0,	0,	0,	0,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0},
							 {0,	14,	14,	14,	14,	14,	14,	14,	0,	0,	0,	15,	4,	0,	0,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	4,	15,	15,	0,	0,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0},
							 {99,	0,	14,	14,	14,	14,	14,	14,	14,	0,	0,	0,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	0,	0,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	99},
							 {99,	0,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	99,	99},
							 {99,	99,	0,	0,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	0,	0,	99,	99},
							 {99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99}
	};
public:
	Boss();
	~Boss();

	void Update();
	int* getColorLine(int row);
	const char* getClassName();
};

