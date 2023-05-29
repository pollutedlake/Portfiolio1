#include "Room.h"

Room::Room()
{
	for (int i = 0; i < ROOMHEIGHT; i++)
	{
		for (int j = 0; j < ROOMWIDTH; j++)
		{
			color[i][j] = 6;
			info[i][j] = -1;
		}
	}
}

Room::~Room()
{

}

int* Room::getRoomColorLine(int col)
{
	return color[col];
}

int* Room::getRoomInfoLine(int col)
{
	return info[col];
}