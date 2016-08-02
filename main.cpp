#include "game.h"

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

int main(int argc, char * argv[]){
	Game game(50, 20);
	game.play();

	return 0;
}
