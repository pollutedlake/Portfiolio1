#include "Shop.h"

Shop::Shop()
{
	Item heart = { "심장", 5, "최대 체력과 현재 체력이 2칸 늘어납니다." };
	Item mushroom = {"버섯", 6, "공격력을 10 올려준다."};
	Item invertedCross = { "역십자가", 7, "이동속도를 두배 올려준다." };
	Item ring = { "천사링", 8, "공격속도를 두배 올려준다." };
	items.insert(pair<int, Item>(0, heart)); 
	items.insert(pair<int, Item>(1, mushroom));
	items.insert(pair<int, Item>(2, invertedCross));
	items.insert(pair<int, Item>(3, ring));
	for (auto it = items.begin(); it != items.end(); ++it)
	{
		equipment = new Equipment(it->second.name, it->second.price, it->second.explanation, it->first);
		saleItem.push_back(equipment);
	}
}

Shop::~Shop()
{
	for (auto it = saleItem.begin(); it != saleItem.end(); ++it)
	{
		delete *(it--);
	}
	delete equipment;
} 

void Shop::startShopping(DoubleBuffering* doubleBuffering, Player* _player)
{
	doubleBuffering->screenRelease();
	CONSOLE_FONT_INFOEX info = { 0 };
	info.cbSize = sizeof(info);
	info.dwFontSize.Y = 15;
	info.FontWeight = FW_NORMAL;
	wcscpy_s(info.FaceName, L"Lucida Console");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
	player = _player;
	while(true)
	{
		bool endShopping = false;
		switch (printDoWhat())
		{
		case 0:
			while (true)
			{
				if (purchaseEquipment())
				{
					break;;
				}
			}
			break;
		case 1:
			sellEquipment();
			break;
		case 2:
			wearEquipment();
			break;
		default:
			endShopping = true;
			break;
		}
		if (endShopping)
		{
			break;
		}
	}
	system("cls");
	info.dwFontSize.Y = 6;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
	doubleBuffering->screenInit();
}

void Shop::linePrint()
{
	cout << "===================================================================" << endl;
}

int Shop::printDoWhat()
{
	system("cls");
	linePrint();
	cout << "즐거운 쇼핑시간" << endl;
	linePrint();
	cout << "0 : 장비 구매\t1 : 장비 판매\t2 : 장비 착용\t그 외 : 쇼핑종료" << endl;
	linePrint();
	cout << "하실 행동을 입력해주세요 : ";
	int choice;
	cin >> choice;
	return choice;
}

bool Shop::purchaseEquipment()
{
	while (true)
	{
		system("cls");
		linePrint();
		linePrint();
		int index = 0;
		for (auto sIIt = saleItem.begin(); sIIt != saleItem.end(); ++sIIt)
		{
			++index;
			cout << index << "번 장비" << endl;
			(*sIIt)->printEquipment();
			linePrint();
		}
		linePrint();
		cout << "현재 소지금 : " << player->getMoney() << endl;
		cout << "구매할 장비의 번호를 입력하세요(그 외 : 뒤로가기) : ";
		int choice;
		cin >> choice;
		if (choice > 0 && index >= choice)
		{
			if (player->getMoney() < (*(saleItem.begin() + choice - 1))->getPrice())
			{
				cout << "현재 소지금이 부족합니다.\n";
				Sleep(3000);
				continue;
			}
			else
			{
				player->putInventory(saleItem[choice-1]);
				player->setMoney(player->getMoney() - (saleItem[choice - 1])->getPrice());
				saleItem.erase(saleItem.begin() + choice - 1);
			}
		}
		else
		{
			return true;
		}
	}
}

void Shop::textColor(int font, int background)
{
	int color = font + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Shop::sellEquipment()
{
	while (true)
	{
		system("cls");
		linePrint();
		vector<Equipment*> inventory = player->getInventory();
		int index = 0;
		for (auto it = inventory.begin(); it < inventory.end(); ++it)
		{
			++index;
			linePrint();
			cout << index << "번 장비" << endl;
			(*it)->printEquipment();
		}
		linePrint();
		linePrint();
		cout << "현재 소지금 : " << player->getMoney() << endl;
		cout << "판매할 장비의 번호를 입력하세요(그 외 : 뒤로가기) : ";
		int choice;
		cin >> choice;
		if (choice > 0 && choice <= inventory.size())
		{
			Equipment* tempE = inventory.at(choice - 1);
			player->plusMoney(tempE->getPrice());
			saleItem.push_back(tempE);
			player->takeOutEquipment(choice - 1);
		}
		else {
			return;
		}
	}
}

void Shop::wearEquipment()
{
	while (true)
	{
		system("cls");
		linePrint();
		linePrint();
		cout << "Player의 스탯" << endl;
		cout << "MAX HP : " << player->getMaxHp() << endl;
		cout << "HP : " << player->getCurHp() << endl;
		printf("공격력 : %d(10 + )\n", player->getAtt());
		cout << "스피드 : " << player->getSpeed() << endl;
		cout << "공격속도 : " << player->getAttRate() << endl;
		linePrint();
		linePrint();
		cout << endl;
		linePrint();
		linePrint();
		cout << "현재 착용중인 장비" << endl;
		linePrint();
		if (player->getEquipment() != nullptr)
		{
			player->getEquipment()->printEquipment();
		}
		linePrint();
		linePrint();
		cout << endl;
		linePrint();
		vector<Equipment*> inventory = player->getInventory();
		int index = 0;
		for (auto it = inventory.begin(); it < inventory.end(); ++it)
		{
			++index;
			linePrint();
			cout << index << "번 장비" << endl;
			(*it)->printEquipment();
		}
		linePrint();
		linePrint();
		cout << "착용할 장비의 번호를 입력하세요(그 외 : 뒤로가기) : ";
		int choice;
		cin >> choice;
		if (choice > 0 && choice <= inventory.size())
		{
			player->wearEquipment(choice - 1);
		}
		else
		{
			return;
		}
	}
}

Equipment* Shop::getEquipment(int equipmentId)
{
	return saleItem[equipmentId];
}