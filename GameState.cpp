#include "GameState.h"

void GameState::loadGame(Snake& head)
{
	// Floor
	for (int i = 0; i < 10; i++)
	{
		wallstb[i].x = i * 64;
		wallstb[i].y = 470;
		wallstb[i].w = 64;
		wallstb[i].h = 10;
	}
	// Right Wall
	for (int i = 0; i < 10; i++)
	{
		wallslr[i].x = wallstb[9].x + 54;
		wallslr[i].y = i * 48;
		wallslr[i].w = 10;
		wallslr[i].h = 48;
	}
	// Ceiling
	for (int i = 10; i < 20; i++)
	{
		int x = 0;
		wallstb[i].x = wallstb[i-10].x;
		wallstb[i].y = 0;
		wallstb[i].w = 64;
		wallstb[i].h = 10;
		x += 1;
	}
	// Left Wall
	for (int i = 10; i < 20; i++)
	{
		wallslr[i].x = wallstb[0].x;
		wallslr[i].y = wallslr[i - 10].y;
		wallslr[i].w = 10;
		wallslr[i].h = 48;
	}
}

void GameState::renderGame(Snake& head, Linkedlist& list)
{
	// Set drawing color blue
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	// Clear the screen to blue
	SDL_RenderClear(renderer);

	// Rendering the Floor/Ceiling
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	for (int i = 0; i < 20; i++)
	{
		SDL_Rect rect = {wallstb[i].x, wallstb[i].y, wallstb[i].w, wallstb[i].h};
		SDL_RenderFillRect(renderer, &rect);
	}
	// Rendering Walls
	for (int i = 0; i < 20; i++)
	{
		SDL_Rect rect = { wallslr[i].x, wallslr[i].y, wallslr[i].w, wallslr[i].h };
		SDL_RenderFillRect(renderer, &rect);
	}

	// Draws head of snake
	head.drawSnake(renderer);
	list.drawNode(renderer);

	SDL_RenderPresent(renderer);
}

int GameState::processEvents(SDL_Window* window, Snake& head, Linkedlist& list)
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
	list.processNode(head);
	return done;
}