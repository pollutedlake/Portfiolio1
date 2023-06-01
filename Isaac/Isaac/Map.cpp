#include "Map.h"

Map::Map()
{
	for (int i = 0; i < 20; i++)
	{
		miniMap[0][i] = 0;
		miniMap[19][i] = 0;
		miniMap[i][0] = 0;
		miniMap[i][19] = 0;
	}
	for (int i = 1; i < 19; i++)
	{
		for (int j = 1; j < 19; j++)
		{
			miniMap[i][j] = 99;
		}
	}
	createRooms();
}

Map::~Map()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			delete rooms[i][j];
		}
	}
	delete startRoom;
	delete curRoom;
}

void Map::createRooms()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (map[i][j] != 0)
			{
				if (map[i][j] == 1)
				{
					rooms[i][j] = new Room(1);
					startRoom = rooms[i][j];
					playerPosCol = i;
					playerPosRow = j;
				}
				else if (map[i][j] == 2)
				{
					rooms[i][j] = new Room(2);
				}
				else if (map[i][j] == 5)
				{
					rooms[i][j] = new Room(3);
				}
				else
				{
					rooms[i][j] = new Room();
				}
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (map[i][j] != 0)
			{
				if (i > 0)
				{
					if (map[i - 1][j] != 0)
					{
						rooms[i][j]->setUp(rooms[i - 1][j]);
					}
				}
				if (i < 4)
				{
					if (map[i + 1][j] != 0)
					{
						rooms[i][j]->setDown(rooms[i + 1][j]);
					}
				}
				if (j > 0)
				{
					if (map[i][j - 1] != 0)
					{
						rooms[i][j]->setLeft(rooms[i][j - 1]);
					}
				}
				if (j < 4)
				{
					if (map[i][j + 1] != 0)
					{
						rooms[i][j]->setRight(rooms[i][j + 1]);
					}
				}
			}
		}
	}
	curRoom = startRoom;
}

void Map::update(int x, int y)
{
	map[playerPosCol][playerPosRow] = 4;
	playerPosCol += y;
	playerPosRow += x;
	map[playerPosCol][playerPosRow] = 1;
}

void Map::updateMiniMap()
{
	for (int i = 1; i < 19; i++)
	{
		for (int j = 1; j < 19; j++)
		{
			miniMap[i][j] = 99;
		}
	}
	for (int i = playerPosCol - 2; i < playerPosCol + 3; i++)
	{
		if (i < 0 || i > 4)
		{
			continue;
		}
		for (int j = playerPosRow - 2; j < playerPosRow + 3; j++)
		{
			if (j < 0 || j > 4)
			{
				continue;
			}
			int color = 99;
			switch (map[i][j])
			{
			case 1:
				color = 14;
				break;
			case 4:
				color = 15;
				break;
			case 2:
				if ((abs(playerPosCol - i) < 2) && (abs(playerPosRow - j) < 2))
				{
					color = 12;
				}
				break;
			case 3:
				if ((abs(playerPosCol - i) < 2) && (abs(playerPosRow - j) < 2))
				{
					color = 8;
				}
				break;
			case 5:
				color = 1;
				break;
			}
			if (color == 99)
			{
				continue;
			}
			miniMap[(i - playerPosCol) * 3 + 9][(j - playerPosRow) * 3 + 9] = color;
			miniMap[(i - playerPosCol) * 3 + 9][(j - playerPosRow) * 3 + 10] = color;
			miniMap[(i - playerPosCol) * 3 + 10][(j - playerPosRow) * 3 + 9] = color;
			miniMap[(i - playerPosCol) * 3 + 10][(j - playerPosRow) * 3 + 10] = color;
			for (int k = 0; k < 4; k++)
			{
				miniMap[(i - playerPosCol) * 3 + 8][(j - playerPosRow) * 3 + 8 + k] = 0;
				miniMap[(i - playerPosCol) * 3 + 8 + k][(j - playerPosRow) * 3 + 8] = 0;
				miniMap[(i - playerPosCol) * 3 + 8 + k][(j - playerPosRow) * 3 + 11] = 0;
				miniMap[(i - playerPosCol) * 3 + 11][(j - playerPosRow) * 3 + 8 + k] = 0;

			}
		}
	}
}

int* Map::getMiniMap(int row)
{
	return miniMap[row];
}

int* Map::getMap(int col)
{
	return map[col];
}

void Map::setMap(int _map[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			map[i][j] = _map[i][j];
		}
	}
}

void Map::setCurRoom(int col, int row)
{
	playerPosCol = col;
	playerPosRow = row;
	curRoom = rooms[col][row];
}

void Map::setEnter(int col, int row)
{
	rooms[col][row]->setEnter();
	rooms[col][row]->setClear();
}