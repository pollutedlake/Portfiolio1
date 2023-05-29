#pragma once
#include "DoubleBuffering.h"
#include "Player.h"
#include<Windows.h>
#include<conio.h>
#include <time.h>
#include "Room.h"
#include "Sucker.h"
#include "Object.h"
#include "Fatty.h"
#include "StartScene.h"
#include <vector>
using namespace std;

class Issac
{
private:
	bool isStartScene;
	DoubleBuffering* doubleBuffering;
	StartScene* startScene;
	int screenColor[SCREENHEIGHT][SCREENWIDTH];
	int info[SCREENHEIGHT][SCREENWIDTH];
	int infoIndex;
	Player* player;
	Room* room;
	vector<Object*> objects;

public:
	Issac();
	~Issac();
	void startGame();
	void render();
};

