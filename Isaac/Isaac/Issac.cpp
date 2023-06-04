#include "Issac.h"

Issac::Issac()
{
	doubleBuffering = new DoubleBuffering();
	player = new Player();
	sceneMgr = new SceneMgr();
	map = new Map();
	room = map->getCurRoom();
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	objects.push_back(player);
	infoIndex = 0;
	scene = STARTSCENE;
	//isStartScene = true;
	uiMgr = new UIMgr();
	coin = new Coin();
	shop = new Shop();
	fp = NULL;
	endTime = NULL;
	fopen_s(&fp, "save.txt", "r");
	PlaySound(TEXT("./sound.wav"), NULL, SND_ASYNC | SND_LOOP);
}

Issac::~Issac()
{
	doubleBuffering->screenRelease();
	delete doubleBuffering;
	delete player;
	delete room;
	delete map;
	delete sceneMgr;
	delete coin;
	delete shop;
	fclose(fp);
}

void Issac::startGame()
{
	doubleBuffering->screenInit();
	while(true)
	{
		curTime = clock();
		// 시작 타이틀 화면
		if(scene == STARTSCENE)
		//if (isStartScene)
		{
			for (int i = 0; i < 79; i++)
			{
				for (int j = 0; j < 96; j++)
				{
					if (sceneMgr->getStartScene(i)[j] == 99)
					{
						continue;
					}
					screenColor[(SCREENHEIGHT - 79) / 2 + i][(SCREENWIDTH - 96) / 2 + j] = sceneMgr->getStartScene(i)[j];
				}
			}
			bool existFile;
			if (fp == NULL)
			{
				existFile = false;
			}
			else {
				existFile = true;
			}
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 73; j++)
				{
					if (sceneMgr->getPressS(i)[j] != 99)
					{
						screenColor[150 + i][124 + j] = sceneMgr->getPressS(i)[j];
					}
					if (existFile)
					{
						if (sceneMgr->getPressL(i)[j] != 99 && j < 70)
						{
							screenColor[165 + i][124 + j] = sceneMgr->getPressL(i)[j];
						}
					}
				}
			}
			if (_kbhit())
			{
				int key = _getch();
				if (key == 's' || key == 'S')
				{
					scene = INGAME;
					//isStartScene = false;
					if(fp != nullptr)
					{
						fclose(fp);
					}
				}
				if ((key == 'l' || key == 'L') && existFile)
				{
					scene = INGAME;
					//isStartScene = false;
					fclose(fp);
					loadGame();
				}
				if (key == 27)
				{
					return;
				}
			}
			render();
			continue;
		}
		// 게임오버 화면
		if (player->getCurHp() == 0)
		{
			for (int i = 0; i < SCREENHEIGHT; i++)
			{
				for (int j = 0; j < SCREENWIDTH; j++)
				{
					if ((i > 78) && (i < 102))
					{
						if ((j > 140) && (j < 179))
						{
							screenColor[i][j] = sceneMgr->getGameOver(i - 79)[j - 141];
						}
						else {
							screenColor[i][j] = 0;
						}
					}
					else {
						screenColor[i][j] = 0;
					}
				}
			}
			if (endTime == NULL)
			{
				endTime = clock();
			}
			if (curTime - endTime > 5000)
			{
				scene = STARTSCENE;
				endTime = NULL;
			}
			render();
			continue;
		}
		room = map->getCurRoom();
		// 게임클리어 화면
		if (room->getIsEndRoom())
		{
			for (int i = 0; i < SCREENHEIGHT; i++)
			{
				for (int j = 0; j < SCREENWIDTH; j++)
				{
					if ((i > 78) && (i < 102))
					{
						if ((j > 140) && (j < 179))
						{
							screenColor[i][j] = sceneMgr->getGameClear(i - 79)[j - 141];
						}
						else {
							screenColor[i][j] = 0;
						}
					}
					else {
						screenColor[i][j] = 0;
					}
				}
			}
			if (endTime == NULL)
			{
				endTime = clock();
			}
			if (curTime - endTime > 5000)
			{
				scene = STARTSCENE;
				endTime = NULL;
			}
			render();
			continue;
		}
		// Room에 입장하면 Player를 제외한 Object들을 비활성화하고 Room에 생성된 Enemy들을 objects에 넣어준다.
		if (!room->getEnter())
		{
			for (auto it = objects.begin() + 1; it != objects.end(); ++it)
			{
				(*it)->switchActive();
			}
			vector<Enemy*> enemies = room->getEnemies();
			for (auto it = enemies.begin(); it != enemies.end(); ++it)
			{
				objects.push_back(*it);
			}
			if (room->setEnter(player->getPosition()))
			{
				saveGame();
			}
		}
		// 방안에 몬스터가 다 죽으면 방 클리어
		if (room->getEnemyN() == 0)
		{
			room->setClear();
		}
		// Player 입력 받기
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
								if (room->getLeft()->getRoomType() == SHOP)
								{
									shop->startShopping(doubleBuffering, player);
									continue;
								}
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
								if (room->getRight()->getRoomType() == SHOP)
								{
									shop->startShopping(doubleBuffering, player);
									continue;
								}
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
								if (room->getUp()->getRoomType() == SHOP)
								{
									shop->startShopping(doubleBuffering, player);
									continue;
								}
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
								if (room->getDown()->getRoomType() == SHOP)
								{
									shop->startShopping(doubleBuffering, player);
									continue;
								}
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
				Projectile* tempProjectile = player->attack();
				if(tempProjectile != nullptr)
				{
					objects.push_back(tempProjectile);
				}
			}
			else if (key == 27)
			{
				return;
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
		// 방 내부 그리기
		for (int i = 0; i < 150; i++)
		{
			for (int j = 0; j < 280; j++)
			{
				screenColor[i + 15][j + 20] = room->getRoomColorLine(i)[j];
				info[i + 15][j + 20] = room->getRoomInfoLine(i)[j];
			}
		}
		// object들 업데이트
		for (auto objectIter = objects.begin(); objectIter != objects.end(); ++objectIter)
		{
			(*objectIter)->Update();
			(*objectIter)->setDirToPlayer(player->getPosition());
		}
		// 비활성화된 object삭제
		for (auto objectIter = objects.begin(); objectIter != objects.end(); ++objectIter)
		{
			if (!((*objectIter)->isActive()))
			{
				if ((*objectIter)->getClassName() == typeid(Sucker*).name() || (*objectIter)->getClassName() == typeid(Fatty*).name())
				{
					room->dieEnemy();
					dropCoin = new Coin((*objectIter)->getPosition(), (*objectIter)->getPrice());
					objects.push_back(dropCoin);
				}
				delete* objectIter;
				objects.erase(objectIter--);
				continue;
			}
		}
		// object정보 업데이트하면서 충돌체크
		for (auto objectIter = objects.begin(); objectIter != objects.end(); ++objectIter)
		{
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
		}
		// 화면에 출력될 도트 색상 업데이트
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
		// 하트 그리기
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
		// 소지금 그리기
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
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (uiMgr->getEqualSign(i)[j] == 99)
				{
					continue;
				}
				screenColor[6 + i][90 + j] = uiMgr->getEqualSign(i)[j];
			}
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (uiMgr->getNumber(player->getMoney() / 10, i)[j] != 99)
				{
					screenColor[6 + i][98 + j] = uiMgr->getNumber(player->getMoney() / 10, i)[j];
				}
				if (uiMgr->getNumber(player->getMoney() % 10, i)[j] != 99)
				{
					screenColor[6 + i][103 + j] = uiMgr->getNumber(player->getMoney() % 10, i)[j];
				}
			}
		}
		// 착용한 장비 그리기
		if (player->getEquipment() != nullptr)
		{
			for (int i = 0; i < player->getEquipment()->getDotHeight(); i++)
			{
				for (int j = 0; j < player->getEquipment()->getDotWidth(); j++)
				{
					if (player->getEquipment()->getDotLine(i, player->getEquipment()->getEquipmentId())[j] != 99)
					{
						screenColor[i][115 + j] = player->getEquipment()->getDotLine(i, player->getEquipment()->getEquipmentId())[j];
					}
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

/*
Player의 스탯과 현재까지의 진행상황을 저장하기 위한 방들의 정보, 착용하고 있는 장비의 고유ID, 인벤토리에 있는 장비들의 고유 ID를 저장한다.
*/
void Issac::saveGame()
{
	if (0 == fopen_s(&fp, "save.txt", "w"))
	{
		// Player의 스탯
		fprintf(fp, "%d %d %d %d %d %d\n", player->getMaxHp(), player->getCurHp(), player->getMoney(), player->getAtt(), player->getSpeed(), player->getAttRate());
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				fprintf(fp, "%d ", map->getMap(i)[j]);
			}
		}
		// 착용하고 있는 장비
		fprintf(fp, "%d %d ", player->getEquipment() != nullptr ? 1 : 0, player->getEquipment() != nullptr ? player->getEquipment()->getEquipmentId() : -1);
		// 인벤토리에 있는 장비
		fprintf(fp, "%d ", player->getInventorySize());
		if (player->getInventorySize() > 0)
		{
			for (int i = 0; i < player->getInventorySize(); i++)
			{
				fprintf(fp, "%d ", player->getInventory()[i]->getEquipmentId());
			}
		}
		fclose(fp);
	}
}

/*
Player의 스탯과 현재 착용하고 있는 장비와 인벤토리에 있는 장비들의 고유ID를 읽어와 적용하고 상점에서 파는 장비들 목록에서 제거한다.
*/
void Issac::loadGame()
{
	if (0 == fopen_s(&fp, "save.txt", "r"))
	{
		// Player의 스탯
		int maxHp, curHp, money, att, speed, attRate, hasEquipment, equipmentId;
		int tempMap[5][5];
		fscanf_s(fp, "%d %d %d %d %d %d", &maxHp, &curHp, &money, &att, &speed, &attRate);
		// 맵 정보
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				fscanf_s(fp, "%d ", &tempMap[i][j]);
				if (tempMap[i][j] == 1)
				{
					map->setCurRoom(i, j);
				}
				else if (tempMap[i][j] == 4)
				{
					map->setEnter(i, j);
				}
			}
		}
		// 착용하고 있는 장비
		fscanf_s(fp, "%d %d ", &hasEquipment, &equipmentId);
		if (hasEquipment)
		{
			player->putInventory(shop->getEquipment(equipmentId));
			player->wearEquipment(0);
		}
		// 인벤토리
		int inventoryN;
		int inventoryId;
		const char* itemName = shop->getItems()[equipmentId].name;
		for (unsigned int j = 0; j < (*(shop->getSaleItem())).size(); j)
		{
			if ((*(shop->getSaleItem()))[j]->getName() == itemName)
			{
				(*(shop->getSaleItem())).erase((*(shop->getSaleItem())).begin() + j);
			}
			else {
				j++;
			}
		}
		fscanf_s(fp, "%d ", &inventoryN);
		for (int i = 0; i < inventoryN; i++)
		{
			fscanf_s(fp, "%d ", &inventoryId);
			player->putInventory(shop->getEquipment(inventoryId));
			const char* itemName = shop->getItems()[inventoryId].name;
			for (unsigned int j = 0; j < (*(shop->getSaleItem())).size();)
			{
				if ((*(shop->getSaleItem()))[j]->getName() == itemName)
				{
					(*(shop->getSaleItem())).erase((*(shop->getSaleItem())).begin() + j);
				}
				else {
					j++;
				}
			}
		}
		player->setMaxHp(maxHp);
		player->setcurHp(curHp);
		player->setMoney(money);
		player->setAtt(att);
		player->setAttRate(attRate);
		player->setSpeed(speed);
		map->setMap(tempMap);
		fclose(fp);
	}
}
