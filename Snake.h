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
		void drawSnake(SDL_Renderer* renderer)
		{
			SDL_Rect head = { x, y, w, h };

			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			SDL_RenderDrawRect(renderer, &head);
			SDL_RenderFillRect(renderer, &head);
		}
};