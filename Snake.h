#pragma once
#include <SDL.h>

class Snake
{
	public:
		// Variables
		float x, y, dx, dy;
		int w, h;

		// Contrstructer
		Snake(float x, float y, int w, int h, float dx, float dy)
		{
			this->x = x;
			this->y = y;
			this->w = w;
			this->h = h;
			this->dx = dx;
			this->dy = dy;
		}
	// Methods
	void drawSnake(SDL_Renderer* renderer);
	void processMovement();
	void snakeMovement();
};