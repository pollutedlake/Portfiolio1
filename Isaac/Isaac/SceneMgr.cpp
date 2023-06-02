#include "SceneMgr.h"


SceneMgr::SceneMgr()
{
	
}

SceneMgr::~SceneMgr()
{
	
}

int* SceneMgr::getStartScene(int row)
{
	return startScene[row];
}

int* SceneMgr::getPressS(int row)
{
	return pressS[row];
}

int* SceneMgr::getPressL(int row)
{
	return pressL[row];
}

int* SceneMgr::getGameOver(int row)
{
	return gameOver[row];
}

int* SceneMgr::getGameClear(int row)
{
	return gameClear[row];
}