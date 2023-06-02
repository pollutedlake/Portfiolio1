#pragma once
#include<iostream>
using namespace std;

class Equipment
{
private:
	const char* name;
	int price;
	const char* explanation;
	int equipmentId;
	int itemsDot[4][10][11] = { {{99,	99,	99,	99,	99,	0,	99,	99,	99,	99,	99},
								 {99,	99,	99,	99,	0,	4,	0,	99,	0,	0,	99},
								 {99,	99,	99,	99,	0,	4,	4,	0,	4,	4,	0},
								 {0,	0,	0,	0,	4,	4,	4,	4,	4,	0,	99},
								 {0,	0,	4,	4,	4,	4,	4,	0,	0,	0,	99},
								 {0,	4,	4,	4,	4,	4,	4,	4,	4,	0,	99},
								 {0,	4,	4,	4,	4,	4,	4,	4,	4,	0,	99},
								 {99,	0,	4,	4,	4,	4,	4,	4,	4,	0,	99},
								 {99,	0,	0,	4,	4,	4,	4,	0,	0,	99,	99},
								 {99,	99,	99,	0,	0,	0,	0,	99,	99,	99,	99}}};

public:
	Equipment();
	Equipment(const char* _name, int _price, const char* explanation, int id);
	~Equipment();

	void setName(char* _name) { name=_name; }
	const char* getName() { return name; }
	void setPrice(int _price) { price = _price; }
	int getPrice() { return price; }
	void setExplanation(char* _explanation) { explanation = _explanation; }
	const char* getExplanation() { return explanation; }
	void setEquipmentId(int id) { equipmentId = id; }
	int getEquipmentId() { return equipmentId; }
	void printEquipment();

	int* getDotLine(int row, int id);
};

