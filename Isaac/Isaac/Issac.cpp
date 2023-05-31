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
	coin = new Coin();
}

Issac::~Issac()
{
	doubleBuffering->screenRelease();
	delete doubleBuffering;
	delete player;
	delete room;
	delete map;
	delete startScene;
	delete coin;
}

void Issac::startGame()
{
	doubleBuffering->screenInit();
	while(true)
	{
		// ���� Ÿ��Ʋ ȭ��
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
			room->setEnter(player->getPosition());
		}
		// ��ȿ� ���Ͱ� �� ������ �� Ŭ����
		if (room->getEnemyN() == 0)
		{
			room->setClear();
		}
		// Player�Է� �ޱ�
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
								player->setPosition(make_pair(270, player->getPosition().second));
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
								player->setPosition(make_pair(20, player->getPosition().second));
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
								player->setPosition(make_pair(player->getPosition().first, 127));
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
								player->setPosition(make_pair(player->getPosition().first, 15));
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
		// �� �ܰ� �� �׸���
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
		// �� �� �׸���
		int rightDoor[39][20];
		int upDoor[15][29];
		for (int i = 0; i < 39; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (i == 19) {
					rightDoor[i][j] = 0;
					continue;
				}
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
					if (j < 18)
					{
						rightDoor[i][j] = room->isClear() ? 0 : 99;
					}
					else if (j == 18)
					{
						rightDoor[i][j] = 0;
					}
					else {
						rightDoor[i][j] = 99;
					}
				}
				else {
					if (j < 19)
					{
						rightDoor[i][j] = room->isClear() ? 0 : 99;
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
				if (j == 14)
				{
					upDoor[i][j] = 0;
					continue;
				}
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
						upDoor[i][j] = room->isClear() ? 0 : 99;
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
						upDoor[i][j] = room->isClear() ? 0 : 99;
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
		// �� ���� �׸���
		for (int i = 0; i < 150; i++)
		{
			for (int j = 0; j < 280; j++)
			{
				screenColor[i + 15][j + 20] = room->getRoomColorLine(i)[j];
				info[i + 15][j + 20] = room->getRoomInfoLine(i)[j];
			}
		}
		// object�� ������Ʈ�ϰ� �浹üũ
		for (auto objectIter = objects.begin(); objectIter != objects.end(); ++objectIter)
		{
			(*objectIter)->Update();
			(*objectIter)->setDirToPlayer(player->getPosition());
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
						if ((*objectIter)->getClassName() == typeid(Sucker*).name() || (*objectIter)->getClassName() == typeid(Fatty*).name())
						{
							if (info[i + (*objectIter)->getPosition().second][j + (*objectIter)->getPosition().first] == 0)
							{
								player->getDamage(((Enemy*)(*objectIter))->getAtt());
							}
						}
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
		// object�� �׸���
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
		// �̴ϸ� ������Ʈ �׸���
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
		// ��Ʈ �׸���
		for (int i = 0; i < (player->getCurHp() / 2); i++)
		{
			for (int j = 0; j < 10; j++)
			{
				for (int k = 0; k < 11; k++)
				{
					if (uiMgr->getFullHeartColorLine(j)[k] == 99)
					{
						continue;
					}
					screenColor[j][k + 12 * i] = uiMgr->getFullHeartColorLine(j)[k];
				}
			}
		}
		if ((player->getCurHp() % 2))
		{
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 11; j++)
				{
					if (uiMgr->getHalfHeartColorLine(i)[j] == 99)
					{
						continue;
					}
					screenColor[i][j + 12 * (player->getCurHp() / 2)] = uiMgr->getHalfHeartColorLine(i)[j];
				}
			}
		}
		for (int i = 0; i < (player->getMaxHp() - player->getCurHp()) / 2; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				for (int k = 0; k < 11; k++)
				{
					if (uiMgr->getEmptyHeartColorLine(j)[k] == 99)
					{
						continue;
					}
					screenColor[j][k + 12 * (((player->getCurHp() / 2) + player->getCurHp() % 2) + i)] = uiMgr->getEmptyHeartColorLine(j)[k];
				}
			}
		}
		// ���� �׸���
		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				if (coin->getColorLine(i)[j] == 99)
				{
					continue;
				}
				screenColor[i][60 + j] = coin->getColorLine(i)[j];
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
