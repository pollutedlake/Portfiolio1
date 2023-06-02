#include "Shop.h"

Shop::Shop()
{
	Item heart = { "����", 5, "�ִ� ü�°� ���� ü���� 2ĭ �þ�ϴ�." };
	items.insert(pair<int, Item>(0, heart)); 
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
	cout << "��ſ� ���νð�" << endl;
	linePrint();
	cout << "0 : ��� ����\t1 : ��� �Ǹ�\t2 : ��� ����\t�� �� : ��������" << endl;
	linePrint();
	cout << "�Ͻ� �ൿ�� �Է����ּ��� : ";
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
			cout << index << "�� ���" << endl;
			(*sIIt)->printEquipment();
			linePrint();
		}
		linePrint();
		cout << "���� ������ : " << player->getMoney() << endl;
		cout << "������ ����� ��ȣ�� �Է��ϼ���(�� �� : �ڷΰ���) : ";
		int choice;
		cin >> choice;
		if (choice > 0 && index >= choice)
		{
			if (player->getMoney() < (*(saleItem.begin() + choice - 1))->getPrice())
			{
				cout << "���� �������� �����մϴ�.\n";
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
			cout << index << "�� ���" << endl;
			(*it)->printEquipment();
		}
		linePrint();
		linePrint();
		cout << "���� ������ : " << player->getMoney() << endl;
		cout << "�Ǹ��� ����� ��ȣ�� �Է��ϼ���(�� �� : �ڷΰ���) : ";
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
		cout << "Player�� ����" << endl;
		cout << "MAX HP : " << player->getMaxHp() << endl;
		cout << "HP : " << player->getCurHp() << endl;
		printf("���ݷ� : %d(10 + )\n", player->getAtt());
		cout << "���ǵ� : " << player->getSpeed() << endl;
		cout << "���ݼӵ� : " << player->getAttRate() << endl;
		linePrint();
		linePrint();
		cout << endl;
		linePrint();
		linePrint();
		cout << "���� �������� ���" << endl;
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
			cout << index << "�� ���" << endl;
			(*it)->printEquipment();
		}
		linePrint();
		linePrint();
		cout << "������ ����� ��ȣ�� �Է��ϼ���(�� �� : �ڷΰ���) : ";
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