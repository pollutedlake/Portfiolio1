#pragma once
#include <vector>
#include<random>
#include<Windows.h>
#include"Sucker.h"
#include"Fatty.h"
using namespace std;
#define ROOMWIDTH		280
#define ROOMHEIGHT		150

class Room
{
private:
	int color[ROOMHEIGHT][ROOMWIDTH];
	int info[ROOMHEIGHT][ROOMWIDTH];
	Room* right;
	Room* left;
	Room* up;
	Room* down;
	bool clear;
	int enemyN;
	vector<Enemy*> enemies;
	bool enter;

public:
	Room();
	Room(int startRoom);
	~Room();

	void setEnter(pair<int, int> playerPos);
	bool getEnter() { return enter; }
	void dieEnemy() { enemyN -= 1; }
	int getEnemyN() { return enemyN; }
	void setRight(Room* _right) { right = _right; }
	void setLeft(Room* _left) { left = _left; }
	void setUp(Room* _up) { up = _up; }
	void setDown(Room* _down) { down = _down; }
	void setClear() { clear = true; }
	bool isClear() { return clear; }
	Room* getRight() { return right; }
	Room* getLeft() { return left; }
	Room* getUp() { return up; }
	Room* getDown() { return down; }
	vector<Enemy*> getEnemies() { return enemies; }

	int* getRoomColorLine(int col);
	int* getRoomInfoLine(int col);
};

