#pragma once
#include <utility>
using namespace std;
#define ROOMWIDTH		280
#define ROOMHEIGHT		150

class Room
{
private:
	int color[ROOMHEIGHT][ROOMWIDTH];
	int info[ROOMHEIGHT][ROOMWIDTH];
public:
	Room();
	~Room();

	int* getRoomColorLine(int col);
	int* getRoomInfoLine(int col);
};

