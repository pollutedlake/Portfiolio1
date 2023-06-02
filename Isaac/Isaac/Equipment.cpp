#include "Equipment.h"

Equipment::Equipment()
{

}

Equipment::Equipment(const char* _name, int _price, const char* _explantion, int id)
{
	name = _name;
	price = _price;
	explanation = _explantion;
	equipmentId = id;
}

Equipment::~Equipment()
{

}

void Equipment::printEquipment()
{
	cout << "이름 : " << name << endl;
	cout << "가격 : " << price << endl;
	cout << "특징 : " << explanation << endl;
}

int* Equipment::getDotLine(int col, int id)
{
	return itemsDot[id][col];
}