#ifndef BALL_H
#define BALL_H

#include <iostream>

using std::ostream;

enum  direction {

	STOP = 0,
	UPRIGHT = 1,
	RIGHT = 2,
	DOWNRIGHT = 3,
	UPLEFT = 4,
	LEFT = 5,
	DOWNLEFT = 6
};

class Ball{

public:
	Ball(int x, int y);
	~Ball();
	int getX();
	int getY();
	void reset();
	void setX(int newX);
	void setY(int newY);
	void moveUpRight();
	void moveRight();
	void moveDownRight();
	void moveUpLeft();
	void moveLeft();
	void moveDownLeft();
	direction getDir();
	void setDir(direction newDir);
	friend ostream & operator<<(ostream & os, Ball & ball);
private:
	int posX;
	int posY;
	int orgX;
	int orgY;
	direction dir;
};

#endif 
