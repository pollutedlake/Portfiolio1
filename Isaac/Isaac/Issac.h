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
#include "Map.h"
#include "StartScene.h"
#include "UIMgr.h"
#include <vector>
using namespace std;

class Issac
{
private:
	Map* map;
	bool isStartScene;
	DoubleBuffering* doubleBuffering;
	StartScene* startScene;
	int screenColor[SCREENHEIGHT][SCREENWIDTH];
	int info[SCREENHEIGHT][SCREENWIDTH];
	int infoIndex;
	Player* player;
	Room* room;
	vector<Object*> objects;
	UIMgr* uiMgr;

public:
	Issac();
	~Issac();
	void startGame();
	void render();
};

