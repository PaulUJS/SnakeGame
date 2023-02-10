#pragma once
#include <SDL.h>
#include <cstdlib>
#include "Linkedlist.h"

struct Food
{
	float x, y;
	int w, h;
};

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
		Food food;

		// Methods
		void loadGame();
		void renderGame(Linkedlist& list);
		int processEvents(SDL_Window* window, Linkedlist& list);
		void spawnFood();

};