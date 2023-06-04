#pragma once
#include<utility>
#include<typeinfo>
using namespace std;

class Object
{
protected:
	pair<int, int> position;
	int dotWidth;
	int dotHeight;
	bool active;

public:
	Object();
	~Object();

	int getDotWidth() { return dotWidth; }
	int getDotHeight() { return dotHeight; }
	bool isActive() { return active; }
	void switchActive() { active = !active; }
	pair<int, int> getPosition() { return position; }
	void setPosition(pair<int, int> _position) { position = _position; }
	virtual void collision(Object* object) {};

	virtual void Update() {};

	virtual void setDirToPlayer(pair<int, int> playerPos) {};

	virtual const char* getClassName() { return ""; }

	virtual int* getColorLine(int row) = 0;

	virtual int getPrice() { return 0; };
};

