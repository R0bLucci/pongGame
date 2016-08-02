#ifndef RACKET_H
#define RACKET_H

#include <iostream>
using std::ostream;

class Racket{

private:
	int posX;
	int posY;
	int orgX;
	int orgY;

public:
	Racket(int x, int y);
	~Racket();
	int getX();
	int getY();
	void moveUp();
	void moveDown();
	void reset();
	friend ostream & operator<<(ostream & os, Racket & racket);
};
#endif 
