#include "Projectile.h"

Projectile::Projectile(int x, int y, pair<int, int> _dir)
{
	position.first = x;
	position.second = y;
	dotHeight = 7;
	dotWidth = 7;
	dir = _dir;
	velocity = 3;
	active = true;
}

Projectile::~Projectile()
{

}

// 위치 매 프레임마다 update
void Projectile::Update()
{
	position.first += dir.first * velocity;
	position.second += dir.second * velocity;
	if (position.second < 15 || position.second > 158) {
		active = false;
	}
	if (position.first < 20 || position.first > 293) {
		active = false;
	}
}

// Enemy에 충돌하면 데미지주고 비활성화
void Projectile::collision(Object* object)
{
	if (object->getClassName() == typeid(Sucker*).name() || object->getClassName() == typeid(Fatty*).name())
	{
		Enemy* enemy = (Enemy*)object;
		active = false;
		enemy->getDamage(10);
	}
}

int* Projectile::getColorLine(int row)
{
	return dotColor[row];
}

const char* Projectile::getClassName()
{
	return typeid(this).name();
}