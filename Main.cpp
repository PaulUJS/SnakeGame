#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include "GameState.h"
#include "Snake.h"
#include "Linkedlist.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	// Initializing varibles
	GameState gameState{};
	Linkedlist list{};

	// Creating snake head
	Snake head(320, 240, 10, 10, 0, 0);

	// Creating snake body
	Snake body1(310, 240, 10, 10, 0, 0);
	Snake body2(300, 240, 10, 10, 0, 0);
	Snake body3(290, 240, 10, 10, 0, 0);
	Snake body4(280, 240, 10, 10, 0, 0);
	Snake body5(270, 240, 10, 10, 0, 0);

	list.append(body1);
	list.append(body2);
	list.append(body3);
	list.append(body4);
	list.append(body5);

	list.printList();

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
		done = gameState.processEvents(window, head, list);
		head.processMovement();
		gameState.renderGame(head, list);
	}

	// Cleanup
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	window = nullptr;
	renderer = nullptr;

	// Quit 
	SDL_Quit();
	return 0;
}