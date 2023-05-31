#pragma once
#include<utility>
#include<typeinfo>
#include"Object.h"
#include "Sucker.h"
#include "Fatty.h"
using namespace std;

class Projectile : public Object
{
private:
	pair<int, int>  dir;
	int dotColor[7][7] = { {99, 99, 0, 0, 0, 99, 99},
						   {99, 0,  3, 3, 3, 0,  99},
						   {0,  3,  3, 3, 3, 3,  0},
						   {0,  3,  3, 3, 3, 3,  0},
						   {0,  3,  3, 3, 3, 3,  0},
						   {99, 0,  3, 3, 3, 0,  99},
						   {99, 99, 0, 0, 0, 99, 99}
	};
	int velocity;
public:
	Projectile(int x, int y, pair<int, int> _dir);
	~Projectile();

	void Update();
	const char* getClassName();
	void collision(Object* object);

	int* getColorLine(int row);
};

