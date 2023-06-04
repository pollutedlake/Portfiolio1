#pragma once
#include<Windows.h>
#include "DoubleBuffering.h"
#include "Equipment.h"
#include "Player.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Item
{
	const char* name;
	int price;
	const char* explanation;
};

class Shop
{
private:
	vector<Equipment*> saleItem;
	Equipment* equipment;
	Player* player;
	map<int, Item> items;

public:
	Shop();
	~Shop();

	void startShopping(DoubleBuffering* doubleBuffering, Player* _player);
	void linePrint();
	int printDoWhat();
	Equipment* getEquipment(int equipmentId);
	void textColor(int color, int background);
	bool purchaseEquipment();
	void sellEquipment();
	void wearEquipment();
	vector<Equipment*>* getSaleItem() { return &saleItem; }
	map<int, Item> getItems() { return items; }
};

