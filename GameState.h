#pragma once
#include <SDL.h>
#include "Snake.h"
#include "Linkedlist.h"

struct Walls
{
	float x, y;
	int w, h;
};

class GameState
{
	public:
		SDL_Renderer* renderer;
		Walls wallstb[20];
		Walls wallslr[20];

		// Methods
		void loadGame(Snake& head);
		void renderGame(Snake& head, Linkedlist& list);
		int processEvents(SDL_Window* window, Snake& head, Linkedlist& list);
};