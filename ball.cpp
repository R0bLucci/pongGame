#include "ball.h"

using std::cout;

Ball::Ball(int x, int y) :
posX(x), posY(y), 
orgX(x), orgY(y),
dir(STOP){

}

Ball::~Ball(){ /*TODO*/}


int Ball::getX(){
	return posX;
}

int Ball::getY(){
	return posY;
}

void Ball::setX(int newX){
	posX = newX;
}

void Ball::setY(int newY){
	posY = newY;
}

direction Ball::getDir(){
	return dir;
}

void Ball::setDir(direction newDir){
	dir = newDir;
}

void Ball::moveUpRight(){
	posX++; posY--;
}

void Ball::moveRight(){
	posX++;
}

void Ball::moveDownRight(){
	posX++; posY++;
}

void Ball::moveUpLeft(){
	posX--; posY--;
}

void Ball::moveLeft(){
	posX--;
}

void Ball::moveDownLeft(){
	posX--; posY++;
}

void Ball::reset(){
	posX = orgX;
	posY = orgY;	
	dir = STOP;	
}

ostream & operator<<(ostream & os, Ball & ball){
	os << "\xFE";
	return os;
}
