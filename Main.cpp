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
	Snake body1(308, 240, 10, 10, 0, 0);
	Snake body2(296, 240, 10, 10, 0, 0);
	Snake body3(284, 240, 10, 10, 0, 0);
	Snake body4(272, 240, 10, 10, 0, 0);
	Snake body5(260, 240, 10, 10, 0, 0);
	Snake body6(248, 240, 10, 10, 0, 0);
	Snake body7(236, 240, 10, 10, 0, 0);
	Snake body8(224, 240, 10, 10, 0, 0);

	list.append(body8);
	list.append(body7);
	list.append(body6);
	list.append(body5);
	list.append(body4);
	list.append(body3);
	list.append(body2);
	list.append(body1);
	list.append(head);

	//list.printList();

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	int done = 0;

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	gameState.renderer = renderer;

	gameState.loadGame();

	while (!done)
	{
		done = gameState.processEvents(window,list);
		gameState.renderGame(list);
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