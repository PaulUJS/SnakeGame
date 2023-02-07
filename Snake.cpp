#include "Snake.h"

void Snake::drawSnake(SDL_Renderer* renderer)
{
	SDL_Rect head = { x, y, w, h };

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &head);
	SDL_RenderFillRect(renderer, &head);
}

void Snake::snakeMovement()
{
	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_UP])
	{
		dx = 0;
		dy = 0;
		dy -= 0.75;
	}
	if (state[SDL_SCANCODE_DOWN])
	{
		dx = 0;
		dy = 0;
		dy += 0.75;
	}
	if (state[SDL_SCANCODE_LEFT])
	{
		dx = 0;
		dy = 0;
		dx -= 0.75;
	}
	if (state[SDL_SCANCODE_RIGHT])
	{
		dx = 0;
		dy = 0;
		dx += 0.75;
	}
}

void Snake::processMovement()
{
	// Adds velocity to x and y values to calculate how the snake moves
	x += dx;
	y += dy;
}
	