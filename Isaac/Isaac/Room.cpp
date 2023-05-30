#include "Room.h"

Room::Room()
{
	for (int i = 0; i < ROOMHEIGHT; i++)
	{
		for (int j = 0; j < ROOMWIDTH; j++)
		{
			color[i][j] = 6;
			info[i][j] = -1;
		}
	}
	clear = false;
	random_device oRandomDevice;
	mt19937_64 rnd(oRandomDevice());
	uniform_int_distribution<int> enemyNRange(1, 4);
	enemyN = enemyNRange(rnd);
	uniform_int_distribution<int> enemyType(0, 1);
	Enemy* enemy;
	for (int i = 0; i < enemyN; i++)
	{
		if (enemyType(rnd) == 0)
		{
			enemy = new Sucker(20, 15);
			enemies.push_back(enemy);
		}
		else {
			enemy = new Fatty(20, 15);
			enemies.push_back(enemy);
		}
	}
	enter = false;
}

Room::~Room()
{
	for (auto it = enemies.begin(); it != enemies.end(); ++it)
	{
		delete *it;
	}
	enemies.clear();
	delete right;
	delete left;
	delete up;
	delete down;
}

int* Room::getRoomColorLine(int col)
{
	return color[col];
}

int* Room::getRoomInfoLine(int col)
{
	return info[col];
}