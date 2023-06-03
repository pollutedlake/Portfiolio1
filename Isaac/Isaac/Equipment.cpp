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
	dotHeight = sizeof(itemsDot[equipmentId]) / sizeof(itemsDot[equipmentId][0]);
	dotWidth = sizeof(itemsDot[equipmentId][0]) / sizeof(itemsDot[equipmentId][0][0]);
}

Equipment::~Equipment()
{

}

void Equipment::printEquipment()
{
	cout << "�̸� : " << name << endl;
	cout << "���� : " << price << endl;
	cout << "Ư¡ : " << explanation << endl;
}

int* Equipment::getDotLine(int col, int id)
{
	return itemsDot[id][col];
}