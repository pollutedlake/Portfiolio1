#pragma once
#include "Object.h"
#include "Player.h"
#include <string>
class Coin : public Object
{
private:
	int color[13][25] = { {99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99},
						  {99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99},
						  {99,	99,	0,	0,	0,	0,	0,	6,	6,	14,	14,	6,	6,	6,	14,	14,	6,	0,	0,	0,	0,	0,	99,	99,	99},
						  {99,	99,	0,	0,	0,	0,	0,	6,	6,	14,	14,	6,	6,	6,	14,	14,	6,	0,	0,	0,	0,	0,	99,	99,	99},
						  {99,	0,	0,	0,	6,	14,	14,	14,	14,	14,	6,	0,	0,	0,	6,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99},
						  {99,	0,	6,	6,	14,	14,	14,	14,	14,	6,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	0},
						  {0,	0,	0,	0,	6,	14,	14,	14,	14,	14,	6,	0,	0,	0,	6,	14,	14,	14,	14,	14,	6,	0,	0,	0,	0},
						  {0,	0,	6,	6,	0,	0,	0,	6,	6,	14,	14,	6,	6,	6,	14,	14,	6,	0,	0,	0,	0,	6,	0,	0,	0},
						  {99,	0,	0,	0,	6,	6,	14,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	14,	14,	6,	6,	0,	0,	99,	99},
						  {99,	99,	0,	0,	0,	0,	0,	6,	6,	14,	6,	14,	14,	14,	6,	14,	6,	0,	0,	0,	0,	0,	0,	99,	99},
						  {99,	99,	0,	0,	0,	0,	0,	6,	6,	14,	6,	14,	14,	14,	6,	14,	6,	0,	0,	0,	0,	0,	0,	99,	99},
						  {99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99},
						  {99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99}
	};

	int price;
public:
	Coin();
	Coin(pair<int, int> _position, int _price);
	~Coin();
	int* getColorLine(int row);

	void collision(Object* object);
};

