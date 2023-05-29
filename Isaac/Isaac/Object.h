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
	pair<int, int> getPosition() { return position; }
	virtual void collision(Object* object) {};

	virtual void Update() {};

	virtual const char* getClassName() { return ""; }

	virtual int* getColorLine(int row) = 0;
};

