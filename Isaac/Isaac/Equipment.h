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
								 {99,	99,	99,	0,	0,	0,	0,	99,	99,	99,	99}},
	
								{{99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
								 {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
								 {99, 99, 99,	99,	0,	0,	0,	99,	99, 99, 99},
								 {99, 99, 99,	0,	12,	12,	14,	0,	99, 99, 99},
								 {99, 99, 0,	4,	14,	12,	12,	6,	0,  99, 99},
								 {99, 99, 0,	12,	14,	12,	12,	14,	0,  99, 99},
								 {99, 99, 99,	0,	4,	6,	6,	0,	99, 99, 99},
								 {99, 99, 99,	99,	0,	6,	0,	99,	99, 99, 99},
								 {99, 99, 99,	99,	0,	0,	0,	99,	99, 99, 99},
								 {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}},

								{{99, 99,	99,	99,	99,	12,	12,	99,	99,	99,	99},
								 {99, 99,	99,	99,	12,	0,	0,	12,	99,	99,	99},
								 {99, 99,	99,	99,	12,	0,	0,	12,	99,	99,	99},
								 {99, 99,	99,	99,	12,	0,	0,	12,	99,	99,	99},
								 {99, 99,	99,	99,	12,	0,	0,	12,	99,	99,	99},
								 {99, 99,	12,	12,	12,	0,	0,	12,	12,	12,	99},
								 {99, 12,	0,	0,	0,	0,	0,	0,	0,	0,	12},
								 {99, 12,	0,	0,	0,	0,	0,	0,	0,	0,	12},
								 {99, 12,	12,	12,	12,	0,	0,	12,	12,	12,	12},
								 {99, 99,	99,	99,	12,	12,	12,	12,	99,	99,	99}},

								{{99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
								 {99,	99,	99,	99,	0,	0,	0,	99,	99,	99,	99},
								 {99,	99,	0,	0,	14,	14,	14,	0,	0,	99,	99},
								 {0,	0,	14,	14,	0,	0,	0,	14,	14,	0,	0},
								 {0,	14,	14,	0,	99,	99,	99,	0,	14,	14,	0},
								 {99,	0,	14,	14,	0,	0,	0,	14,	14,	0,	99},
								 {99,	99,	0,	6,	6,	14,	14,	6,	0,	99,	99},
								 {99,	99,	99,	0,	0,	0,	0,	0,	99,	99,	99},
								 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
								 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99}}
	};
	int dotWidth;
	int dotHeight;

public:
	Equipment();
	Equipment(const char* _name, int _price, const char* explanation, int id);
	~Equipment();

	void setName(char* _name) { name=_name; }
	const char* getName() { return name; }
	void setPrice(int _price) { price = _price; }
	int getPrice() { return price; }
	int getDotWidth() { return dotWidth; }
	int getDotHeight() { return dotHeight; }
	void setExplanation(char* _explanation) { explanation = _explanation; }
	const char* getExplanation() { return explanation; }
	void setEquipmentId(int id) { equipmentId = id; }
	int getEquipmentId() { return equipmentId; }
	void printEquipment();

	int* getDotLine(int row, int id);
};

