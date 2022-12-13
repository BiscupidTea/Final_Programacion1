#include "Game.h"

int main()
{
	srand(0);
	hideCursor();
	Game* game = new Game();
	game->GameLoop();

	delete game;
}