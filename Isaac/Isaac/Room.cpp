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

Room::Room(int roomType)
{
	if(roomType == 1)
	{
		for (int i = 0; i < ROOMHEIGHT; i++)
		{
			for (int j = 0; j < ROOMWIDTH; j++)
			{
				color[i][j] = 6;
				info[i][j] = -1;
			}
		}
		clear = true;
		enter = true;
		enemyN = 0;
	}
	else if (roomType == 2)
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
		enter = false;
		Enemy* boss = new Boss();
		boss->setPosition(make_pair(136, 74));
		enemies.push_back(boss);
		enemyN = 1;
	}
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

void Room::setEnter(pair<int, int> playerPos)
{
	random_device oRandomDevice;
	mt19937_64 rnd(oRandomDevice());
	uniform_int_distribution<int> xRange(20, 250);
	uniform_int_distribution<int> yRange(15, 125);
	uniform_int_distribution<int> sector(0, 2);
	enter = true;
	for (auto it = enemies.begin(); it != enemies.end(); ++it)
	{
		if ((*it)->getClassName() == typeid(Boss*).name())
		{
			return;
		}
		if (playerPos.first < 21)
		{
			switch (sector(rnd))
			{
			case 0:
				(*it)->setPosition(make_pair(xRange(rnd), 15));
				break;
			case 1:
				(*it)->setPosition(make_pair(250, yRange(rnd)));
				break;
			case 2:
				(*it)->setPosition(make_pair(xRange(rnd), 125));
				break;
			}
		}
		else if (playerPos.first > 269)
		{
			switch (sector(rnd))
			{
			case 0:
				(*it)->setPosition(make_pair(xRange(rnd), 125));
				break;
			case 1:
				(*it)->setPosition(make_pair(20, yRange(rnd)));
				break;
			case 2:
				(*it)->setPosition(make_pair(xRange(rnd), 15));
				break;
			}
		}
		else {
			if (playerPos.second < 16)
			{
				switch (sector(rnd))
				{
				case 0:
					(*it)->setPosition(make_pair(250, yRange(rnd)));
					break;
				case 1:
					(*it)->setPosition(make_pair(xRange(rnd), 125));
					break;
				case 2:
					(*it)->setPosition(make_pair(20, yRange(rnd)));
					break;
				}
			}
			else
			{
				switch (sector(rnd))
				{
				case 0:
					(*it)->setPosition(make_pair(20, yRange(rnd)));
					break;
				case 1:
					(*it)->setPosition(make_pair(xRange(rnd), 15));
					break;
				case 2:
					(*it)->setPosition(make_pair(250, yRange(rnd)));
					break;
				}
			}
		}
	}
}