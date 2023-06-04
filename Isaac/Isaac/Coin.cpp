#include "Coin.h"

Coin::Coin()
{

}

Coin::Coin(pair<int, int> _position, int _price)
{
	position.first = _position.first;
	position.second = _position.second;
	active = true;
	dotHeight = 13;
	dotWidth = 25;
	price = _price;
}

Coin::~Coin()
{

}

int* Coin::getColorLine(int row)
{
	return color[row];
}

// player와 충돌 시 비활성화되고 소지금 증가
void Coin::collision(Object* object)
{
	if (!strcmp(object->getClassName(), typeid(Player*).name()))
	{
		Player* player = (Player*)object;
		active = false;
		player->plusMoney(price);
	}
}