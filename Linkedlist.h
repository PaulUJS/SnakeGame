#pragma once
#include <iostream>
#include "Snake.h"
#include <SDL.h>

// Node of linked list
class Node
{
	public:
		Snake* data;
		Node* next;

		// Default constructor
		Node()
		{
			data = nullptr;
			next = nullptr;
		}

		// Parameterised Constructor
		Node(Snake& data)
		{
			this->data = &data;
			this->next = nullptr;
		}
};

// Linked list class to
// implement a linked list.
class Linkedlist
{
	Node* head;
	public:
		// Default constructor
		Linkedlist()
		{
			head = nullptr;
		}

		// Function for appending to the list
		void append(Snake&);

		// Print function
		void printList();

		// Deletes node at given position
		void deleteNode(int);

		// Returns node at given position
		void processNode(Snake& shead);

		void drawNode(SDL_Renderer* renderer);
};




