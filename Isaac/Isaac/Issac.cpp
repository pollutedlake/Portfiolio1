#include "Issac.h"

Issac::Issac()
{
	doubleBuffering = new DoubleBuffering();
	player = new Player();
	startScene = new StartScene();
	room = new Room();
	//Fatty* fatty = new Fatty(20, 15);
	Sucker* sucker = new Sucker(20, 15);
	//system("mode con cols = 600 lines = 180 | title Issac");
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	objects.push_back(player);
	//objects.push_back(fatty);
	objects.push_back(sucker);
	infoIndex = 0;
	isStartScene = true;
}

Issac::~Issac()
{
	doubleBuffering->screenRelease();
	delete doubleBuffering;
	delete player;
	delete room;
	delete startScene;
}

void Issac::startGame()
{
	doubleBuffering->screenInit();
	while(true)
	{
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
		if(_kbhit())
		{
			int key = _getch();
			if (key == 224) {
				key = _getch();
				switch (key)
				{
				case 75:
					player->move(-1, 0);
				break;
				case 77:
					player->move(1, 0);
				break;
				case 72:
					player->move(0, -1);
				break;
				case 80:
					player->move(0, 1);
				break;

				}
			}
			else if (key == 'a' || key == 'A')
			{
				objects.push_back(player->attack());
			}
		}
		for (int i = 0; i < 150; i++)
		{
			for (int j = 0; j < 280; j++)
			{
				screenColor[i + 15][j + 20] = room->getRoomColorLine(i)[j];
				info[i + 15][j + 20] = room->getRoomInfoLine(i)[j];
			}
		}
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
				delete* objectIter;
				objects.erase(objectIter--);
				continue;
			}
		}
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
		render();
	}
}

void Issac::render()
{
	doubleBuffering->screenClear();
	doubleBuffering->screenPrint(screenColor);
	doubleBuffering->screenFlipping();
}
