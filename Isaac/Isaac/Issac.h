#pragma once
#include "DoubleBuffering.h"
#include "Player.h"
#include "Coin.h"
#include<Windows.h>
#include<mmsystem.h>
#include<conio.h>
#include <time.h>
#include "Room.h"
#include "Sucker.h"
#include "Fatty.h"
#include "Map.h"
#include "SceneMgr.h"
#include "UIMgr.h"
#include "Shop.h"
#include <vector>
#include <fstream>
#pragma comment(lib, "winmm.lib")
using namespace std;

class Issac
{
private:
	Map* map;
	int scene;
	DoubleBuffering* doubleBuffering;
	SceneMgr* sceneMgr;
	int screenColor[SCREENHEIGHT][SCREENWIDTH];
	int info[SCREENHEIGHT][SCREENWIDTH];
	int infoIndex;
	Player* player;
	Room* room;
	vector<Object*> objects;
	UIMgr* uiMgr;
	Coin* coin;
	Coin* dropCoin;
	FILE* fp;
	Shop* shop;
	clock_t curTime, endTime;

public:
	Issac();
	~Issac();

	void saveGame();		
	void startGame();
	void render();
	void loadGame();
};

