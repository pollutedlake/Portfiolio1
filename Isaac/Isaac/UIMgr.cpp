#include "UIMgr.h"


UIMgr::UIMgr()
{

}

UIMgr::~UIMgr()
{

}

int* UIMgr::getFullHeartColorLine(int row)
{
	return fullHeart[row];
}

int* UIMgr::getHalfHeartColorLine(int row)
{
	return halfHeart[row];
}

int* UIMgr::getEmptyHeartColorLine(int row)
{
	return emptyHeart[row];
}