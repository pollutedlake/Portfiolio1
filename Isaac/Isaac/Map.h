#pragma once
#include<random>
#include "Room.h"
using namespace std;

class Map
{
private:
	int map[5][5] = { {0, 0, 3, 0, 0},
					  {0, 2, 3, 3, 3},
					  {3, 0, 3, 0, 3},
					  {3, 3, 3, 3, 0},
					  {0, 3, 0, 1, 0}
	};
	int miniMap[20][20];
	int playerPosCol = 4;
	int playerPosRow = 3;
	Room* startRoom;
	Room* curRoom;
	Room* rooms[5][5];

public:
	Map();
	~Map();

	Room* getStartRoom() { return startRoom; }
	void setCurRoom(Room* _room) { curRoom = _room; }
	Room* getCurRoom() { return curRoom; }
	void createRooms();
	void update(int x, int y);
	void updateMiniMap();
	int* getMiniMap(int row);
};

