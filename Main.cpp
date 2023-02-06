#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include "GameState.h"
#include "Snake.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	// Initializing varibles
	GameState gameState;
	Snake head(200, 200, 25, 25, 0, 0);


	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	int done = 0;

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	gameState.renderer = renderer;

	gameState.loadGame(head);

	while (!done)
	{
		done = gameState.processEvents(window, head);
		head.processMovement();
		gameState.renderGame(head);
	}

	// Cleanup
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	window = NULL;
	renderer = NULL;

	// Quit 
	SDL_Quit();
	return 0;
}