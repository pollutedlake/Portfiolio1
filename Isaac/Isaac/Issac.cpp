#include "Issac.h"

Issac::Issac()
{
	doubleBuffering = new DoubleBuffering();
	player = new Player();
	startScene = new StartScene();
	map = new Map();
	room = map->getCurRoom();
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	objects.push_back(player);
	infoIndex = 0;
	isStartScene = true;
	uiMgr = new UIMgr();
}

Issac::~Issac()
{
	doubleBuffering->screenRelease();
	delete doubleBuffering;
	delete player;
	delete room;
	delete map;
	delete startScene;
}

void Issac::startGame()
{
	doubleBuffering->screenInit();
	while(true)
	{
		// 시작 타이틀 화면
		if (isStartScene)
		{
			for (int i = 0; i < 79; i++)
			{
				for (int j = 0; j < 96; j++)
				{
					if (startScene->getColorLine(i)[j] == 99)
					{
						continue;
					}
					screenColor[(SCREENHEIGHT - 79) / 2 + i][(SCREENWIDTH - 96) / 2 + j] = startScene->getColorLine(i)[j];
				}
			}
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 73; j++)
				{
					if (startScene->getPressS(i)[j] == 99)
					{
						continue;
					}
					screenColor[150 + i][124 + j] = startScene->getPressS(i)[j];
				}
			}
			if (_kbhit())
			{
				int key = _getch();
				if (key == 's' || key == 'S')
				{
					isStartScene = false;
				}
			}
			render();
			continue;
		}
		room = map->getCurRoom();
		if (!room->getEnter())
		{
			vector<Enemy*> enemies = room->getEnemies();
			for (auto it = enemies.begin(); it != enemies.end(); ++it)
			{
				objects.push_back(*it);
			}
			room->setEnter();
		}
		// 방안에 몬스터가 다 죽으면 방 클리어
		if (room->getEnemyN() == 0)
		{
			room->setClear();
		}
		// Player입력 받기
		if(_kbhit())
		{
			int key = _getch();
			if (key == 224) {
				key = _getch();
				switch (key)
				{
				case 75:
					if ((player->getPosition().first <= 20) && (room->isClear()))
					{
						if ((player->getPosition().second <= 90) && (player->getPosition().second >= 52))
						{
							if (room->getLeft() != nullptr)
							{
								player->setPosiiton(make_pair(270, player->getPosition().second));
								map->setCurRoom(room->getLeft());
								map->update(-1, 0);
								continue;
							}
						}
					}
					else
					{
						player->move(-1, 0);
					}
				break;
				case 77:
					if ((player->getPosition().first >= 271) && (room->isClear()))
					{
						if ((player->getPosition().second <= 90) && (player->getPosition().second >= 52))
						{
							if (room->getRight() != nullptr)
							{
								player->setPosiiton(make_pair(20, player->getPosition().second));
								map->setCurRoom(room->getRight());
								map->update(1, 0);
								continue;
							}
						}
					}
					player->move(1, 0);
				break;
				case 72:
					if ((player->getPosition().second <= 15) && (room->isClear()))
					{
						if ((player->getPosition().first <= 167) && (player->getPosition().first >= 137))
						{
							if (room->getUp() != nullptr)
							{
								player->setPosiiton(make_pair(player->getPosition().first, 127));
								map->setCurRoom(room->getUp());
								map->update(0, -1);
								continue;
							}
						}
					}
					player->move(0, -1);
				break;
				case 80:
					if ((player->getPosition().second >= 128) && (room->isClear()))
					{
						if ((player->getPosition().first <= 167) && (player->getPosition().first >= 137))
						{
							if (room->getDown() != nullptr)
							{
								player->setPosiiton(make_pair(player->getPosition().first, 15));
								map->setCurRoom(room->getDown());
								map->update(0, 1);
								continue;
							}
						}
					}
					player->move(0, 1);
				break;

				}
			}
			else if (key == 'a' || key == 'A')
			{
				objects.push_back(player->attack());
			}
		}
		// 방 외곽 벽 그리기
		for (int i = 0; i < 180; i++)
		{
			for (int j = 0; j < 320; j++)
			{
				if ((i + 5 == j) && (i < 15))
				{
					screenColor[i][j] = 0;
				}
				else if ((i == 315 - j) && (i < 15))
				{
					screenColor[i][j] = 0;
				}
				else if ((i > 164) && (j == 184 - i))
				{
					screenColor[i][j] = 0;
				}
				else if ((i > 164) && (j - i == 135))
				{
					screenColor[i][j] = 0;
				}
				else
				{
					screenColor[i][j] = 8;
				}
			}
		}
		// 방 문 그리기
		int rightDoor[39][20];
		int upDoor[15][29];
		for (int i = 0; i < 39; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if ((i == 0) || (i == 38))
				{
					if (j < 18)
					{
						rightDoor[i][j] = 0;
					}
					else {
						rightDoor[i][j] = 99;
					}
				}
				else if ((i == 1) || (i == 37))
				{
					if (j != 18)
					{
						rightDoor[i][j] = 99;
					}
					if (j == 18)
					{
						rightDoor[i][j] = 0;
					}
				}
				else {
					if (j < 19)
					{
						rightDoor[i][j] = 99;
					}
					else {
						rightDoor[i][j] = 0;
					}
				}
			}
		}
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 29; j++)
			{
				if (i == 0)
				{
					if (j < 2 || j > 26)
					{
						upDoor[i][j] = 99;
					}
					else
					{
						upDoor[i][j] = 0;
					}
				}
				else if (i == 1)
				{
					if (j == 1 || j == 27)
					{
						upDoor[i][j] = 0;
					}
					else
					{
						upDoor[i][j] = 99;
					}
				}
				else
				{
					if (j == 0 || j == 28)
					{
						upDoor[i][j] = 0;
					}
					else
					{
						upDoor[i][j] = 99;
					}
				}
			}
		}
		if (room->getLeft() != nullptr)
		{
			for (int i = 0; i < 39; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					if (rightDoor[i][19 - j] == 99)
					{
						continue;
					}
					screenColor[i + 70][j] = rightDoor[i][19 - j];
				}
			}
		}
		if (room->getRight() != nullptr)
		{
			for (int i = 0; i < 39; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					if (rightDoor[i][j] == 99)
					{
						continue;
					}
					screenColor[i + 70][j + 300] = rightDoor[i][j];
				}
			}
		}
		if (room->getUp() != nullptr)
		{
			for (int i = 0; i < 15; i++)
			{
				for (int j = 0; j < 29; j++)
				{
					if (upDoor[i][j] == 99)
					{
						continue;
					}
					screenColor[i][j + 152] = upDoor[i][j];
				}
			}
		}
		if (room->getDown() != nullptr)
		{
			for (int i = 0; i < 15; i++)
			{
				for (int j = 0; j < 29; j++)
				{
					if (upDoor[14 - i][j] == 99)
					{
						continue;
					}
					screenColor[i + 165][j + 152] = upDoor[14 - i][j];
				}
			}
		}
		// 방 내부 그리기
		for (int i = 0; i < 150; i++)
		{
			for (int j = 0; j < 280; j++)
			{
				screenColor[i + 15][j + 20] = room->getRoomColorLine(i)[j];
				info[i + 15][j + 20] = room->getRoomInfoLine(i)[j];
			}
		}
		// object들 업데이트하고 충돌체크
		for (auto objectIter = objects.begin(); objectIter != objects.end(); ++objectIter)
		{
			(*objectIter)->Update();
			bool isCollision = false;
			for (int i = 0; i < (*objectIter)->getDotHeight(); i++)
			{
				for (int j = 0; j < (*objectIter)->getDotWidth(); j++)
				{
					if ((*objectIter)->getColorLine(i)[j] == 99)
					{
						continue;
					}
					screenColor[i + (*objectIter)->getPosition().second][j + (*objectIter)->getPosition().first] = (*objectIter)->getColorLine(i)[j];
					if (info[i + (*objectIter)->getPosition().second][j + (*objectIter)->getPosition().first] >= 0)
					{
						(*objectIter)->collision(objects.at(info[i + (*objectIter)->getPosition().second][j + (*objectIter)->getPosition().first]));
						isCollision = true;
						break;
					}
					info[i + (*objectIter)->getPosition().second][j + (*objectIter)->getPosition().first] = objectIter - objects.begin();
				}
				if (isCollision)
				{
					break;
				}
			}
			if (!((*objectIter)->isActive()))
			{
				if (((*objectIter)->getClassName() == typeid(Sucker*).name()) || ((*objectIter)->getClassName() == typeid(Fatty*).name()))
				{
					room->dieEnemy();
				}
				delete* objectIter;
				objects.erase(objectIter--);
				continue;
			}
		}
		// object들 그리기
		for (auto objectIter = objects.begin(); objectIter != objects.end(); ++objectIter)
		{
			for (int i = 0; i < (*objectIter)->getDotHeight(); i++)
			{
				for (int j = 0; j < (*objectIter)->getDotWidth(); j++)
				{
					if ((*objectIter)->getColorLine(i)[j] == 99)
					{
						continue;
					}
					screenColor[i + (*objectIter)->getPosition().second][j + (*objectIter)->getPosition().first] = (*objectIter)->getColorLine(i)[j];
				}
			}
		}
		// 미니맵 업데이트 그리기
		map->updateMiniMap();
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (map->getMiniMap(i)[j] == 99)
				{
					continue;
				}
				screenColor[i + 5][j + 290] = map->getMiniMap(i)[j];
			}
		}
		for (int i = 0; i < ceil(player->getMaxHp() / 2); i++)
		{
			for (int j = 0; j < 10; j++)
			{
				for (int k = 0; k < 11; k++)
				{
					if (uiMgr->getHeartColorLine(j)[k] == 99)
					{
						continue;
					}
					screenColor[j][k + 12 * i] = uiMgr->getHeartColorLine(j)[k];
				}
			}
		}
		render();
	}
}

void Issac::render()
{
	doubleBuffering->screenClear();
	doubleBuffering->screenPrint(screenColor);
	doubleBuffering->screenFlipping();
}
