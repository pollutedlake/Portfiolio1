#include "Boss.h"

Boss::Boss()
{

}

Boss::~Boss()
{

}

void Boss::Update()
{
	curTime = clock();
	if (curTime - twinkleTime > 2000)
	{
		isTwinkle = false;
		isRed = false;
	}
	if (isTwinkle && (curTime - redTime > 200))
	{
		isRed = !isRed;
		redTime = curTime;
	}
}