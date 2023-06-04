#pragma once
#include<random>
#include "Room.h"
using namespace std;

class Map
{
private:
	// Room들의 정보가 저장된 배열
	int map[5][5] = { {0, 0, 6, 0, 0},
					  {0, 2, 5, 3, 3},
					  {3, 0, 3, 0, 3},
					  {3, 3, 3, 3, 0},
					  {0, 6, 0, 1, 0}
	};
	// 미니맵 도트 색상
	int miniMap[20][20];

	// Player현재위치
	int playerPosCol;
	int playerPosRow;
	Room* curRoom;

	Room* startRoom;
	Room* rooms[5][5];

public:
	Map();
	~Map();

	Room* getStartRoom() { return startRoom; }
	void setCurRoom(Room* _room) { curRoom = _room; }
	void setCurRoom(int col, int row);
	Room* getCurRoom() { return curRoom; }
	void createRooms();
	void setEnter(int col, int row);
	void update(int x, int y);
	void updateMiniMap();
	int* getMiniMap(int row);
	int* getMap(int col);
	void setMap(int _map[5][5]);
};

