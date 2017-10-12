#include "Game.h"
#include "EventManager.h"

Game* game = NULL;

int main( int argc, char* args[] )
{

	game = new Game();
	game->init("SDL Engine", 720, 480, false);

	while (game->running())
	{
		/* Init deltatime counter */
		game->NOW = SDL_GetPerformanceCounter();
		EventManager::handleEvents();
		game->calculateDelta();
		game->update();
		game->render();
	}

	game->clean();
	return 0;
}
