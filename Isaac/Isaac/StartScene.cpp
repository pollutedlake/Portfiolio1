#include "StartScene.h"


StartScene::StartScene()
{
	
}

StartScene::~StartScene()
{
	
}

int* StartScene::getColorLine(int row)
{
	return startScene[row];
}

int* StartScene::getPressS(int row)
{
	return pressS[row];
}