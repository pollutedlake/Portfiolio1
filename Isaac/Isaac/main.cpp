#include "Issac.h"

/*
 콘솔버퍼사이즈 : 6px
 창사이즈 : 전체화면
*/

void main()
{
	Issac* issac = new Issac();
	issac->startGame();
	delete issac;
}