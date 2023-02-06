#pragma once
#include <SDL.h>
#include "Snake.h"

class GameState
{
	public:
		SDL_Renderer* renderer;

		// Methods
		void loadGame(Snake& head);
		void renderGame(Snake& head);
		int processEvents(SDL_Window* window, Snake& head);
};