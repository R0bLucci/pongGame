#ifndef GAME_H
#define GAME_H

#include "ball.h"
#include "racket.h"

class Game{

public:
	Game(int w, int h);
	~Game();
	void draw();
	void inputAndLogic();
	void play();
private:
	int width;
	int height;
	int player1Score;
	int player2Score;
	bool quit;
	Ball * ball;
	Racket * player1;
	Racket * player2;
	void input();
	void logic();
};


#endif
