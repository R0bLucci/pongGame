#include "game.h"
#include "conio.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

Game::Game(int w, int h) :
width(w), height(h), ball(new Ball( w/2, h/2)), 
player1Score(0), player2Score(0),
quit(false),
player1(new Racket(1 , h/2)), 
player2(new Racket(w - 1, h/2)){


}

Game::~Game(){
	delete player1;
	delete player2;
	delete ball;
}


void Game::draw(){
	system("clear");
	//system("cls");
	for(int y = 0; y < height; y++){
		for(int x = 0; x < width + 1; x++){
			
			if(y == 0){
				cout << "\xB2";
			}
			else if( y == height -1){
				cout << "\xB2";	
			}
			else{
				if(x == 0){
					cout << "\xB2";
				}
				else if( x + 1 == width + 1){
					cout << "\xB2";
				}
				else{	

					if(ball->getX() == x && ball->getY() == y){
						cout << *ball;
					}
					else if(player1->getX() == x && player1->getY() - 1 == y){	
						cout << *player1;
					}
					else if(player1->getX() == x && player1->getY() == y){ 
						cout << *player1;
					}
					else if(player1->getX() == x && player1->getY() + 1 == y){
						cout << *player1;
					}	
					else if(player2->getX() == x && player2->getY() - 1 == y){
						cout << *player2;
					}
					else if(player2->getX() == x && player2->getY() == y){
						cout << *player2;
					}
					else if(player2->getX() == x && player2->getY() + 1 == y){
						cout << *player2; 
					}else{
						cout << " ";
					}
				}
			}
		}
	
		cout << endl; 
	}
	cout << "player 1: " << player1Score << endl;
	cout << "player 2: " << player2Score << endl;
} 

void Game::logic(){

	if(ball->getY() == 1)
		ball->setDir( ball->getDir() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
	else if(ball->getY() == height - 2)
		ball->setDir( ball->getDir() == DOWNRIGHT ? UPRIGHT : UPLEFT);

	if(ball->getX() == player1->getX() + 1 && ball->getY() == player1->getY() ||
			ball-> getX() == player1->getX() + 1 && ball->getY() == player1->getY() - 1 ||
			ball-> getX() == player1->getX() + 1 && ball->getY() == player1->getY() + 1 ){
		srand(time(NULL));				
		direction ran = (direction)((rand() % 3) + 1);
		ball->setDir(ran);
	}
	else if(ball->getX() == player2->getX() - 1 && ball->getY() == player2->getY() ||
			ball-> getX() == player2->getX() - 1 && ball->getY() == player2->getY() - 1 ||
			ball-> getX() == player2->getX() - 1 && ball->getY() == player2->getY() + 1 ){
		srand(time(NULL));				
		direction ran = (direction)((rand() % 3) + 4);
		ball->setDir(ran);
	}

	if(ball->getX() == 0){// player 2 scores
		player2Score++;
		ball->reset();
		player1->reset();
		player2->reset();
	}
	else if(ball->getX() == width){// player 1 scores
		player1Score++;
		ball->reset();
		player1->reset();
		player2->reset();
	}
		
		
}


void Game::input(){
	switch(ball->getDir()){
		case STOP:
		{
			srand(time(NULL));				
			direction ran = (direction)((rand() % 6) + 1);
			ball->setDir(ran);
		}
		break;			
		case UPRIGHT:
			ball->moveUpRight();
		break;
		case RIGHT:
			ball->moveRight();
		break;
		case DOWNRIGHT:
			ball->moveDownRight();
		break;
		case UPLEFT:
			ball->moveUpLeft();
		break;
		case LEFT:
			ball->moveLeft();
		break;
		case DOWNLEFT:
			ball->moveDownLeft();
		break;
		default:
		break;
	}	

	if(kbhit()){ 

		char c = getch();

		if(c =='q')
			quit = true;

		if(c == 'w'){
			if(player1->getY() > 2)
				player1->moveUp();
		}
		else if(c == 's'){
			if(player1->getY() < height - 3)
				player1->moveDown();
		}
	}
	if(ball->getX() > width - (width / 3)){
		if(ball->getDir() == UPRIGHT && player2->getY() > 2) 
			player2->moveUp();
		else if(ball->getDir() == DOWNRIGHT && player2->getY() < height - 3)
			player2->moveDown();	
		else if(ball->getDir() == RIGHT){
			while(player2->getY() < ball->getY()){
				player2->moveDown();
			}
			while(player2->getY() > ball->getY()){
				player2->moveUp();
			}
		}
	}
}

void Game::inputAndLogic(){
	input();
	logic();
}

void Game::play(){
	while(!quit){
		thread d(&Game::draw, this);
		thread ial(&Game::inputAndLogic, this);
		//thread i(&Game::input, this);
		//thread l(&Game::logic, this);
		d.join();
		ial.join();
		//i.join();
		//l.join();
	}
	/*
	while(!quit){
		draw();
		input();
		logic();
	}
	*/
}
