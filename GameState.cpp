#include "GameState.h"

void GameState::loadGame(Snake& head)
{

}

void GameState::renderGame(Snake& head)
{
	// Set drawing color blue
	SDL_SetRenderDrawColor(renderer, 128, 128, 255, 255);
	// Clear the screen to blue
	SDL_RenderClear(renderer);
	head.drawSnake(renderer);
	SDL_RenderPresent(renderer);
}

int GameState::processEvents(SDL_Window* window, Snake& head)
{
	SDL_Event event;
	int done = 0;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_WINDOWEVENT_CLOSE:
		{
			if (window)
			{
				SDL_DestroyWindow(window);
				window = NULL;
				done = 1;
			}
		}
		break;
		case SDL_KEYDOWN:
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				done = 1;
				break;
			case SDLK_SPACE:
				break;
			}
		}
		break;
		case SDL_QUIT:
			// Quit game
			done = 1;
		}
		break;
	}
	head.snakeMovement();
	return done;
}