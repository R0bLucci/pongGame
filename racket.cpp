#include "racket.h"

using std::endl;

Racket::Racket(int x, int y) : 
posX(x), posY(y),
orgX(x), orgY(y){



}

Racket::~Racket(){ /*TODO*/}

int Racket::getX(){
	return posX;
}

int Racket::getY(){
	return posY;
}

void Racket::moveUp(){
	posY--;
}

void Racket::moveDown(){
	posY++;
}
	
void Racket::reset(){
	posX = orgX;
	posY = orgY;
}

ostream & operator<<(ostream & os, Racket & racket){
	os << "\xDB";
	return os;
}
