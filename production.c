/*
 * production.c
 *
 *  Created on: Aug 22, 2019
 *      Author: Taylor Cox
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tests.h"
#include "TaylorCox.h"
#include "logger.h"


int production(int argc, char* argv[]){
	// Initializing variables and randomizer
	srand(time(NULL));
	int board[SIZE][SIZE];
	Marker player = {0, 0};
	Board one = {board};
	Gamestate state = {player, one};
	int numLoops = 30;
	LLNode* head = malloc(sizeof(LLNode));
	LLNode* current = malloc(sizeof(LLNode));
	current->next = NULL;
	head->next = current;
	reset(&state);

	// Moves the cursor a certain number of times, and records
	// where it moves.
	for(int i = 0; i < numLoops; i++) {
		printf("Iteration %d:\n", i);
		draw(&state);
		current->val = update(&state);
		LLNode* next = malloc(sizeof(LLNode));
		next->next = NULL;
		current->next = next;
		current = next;
	}

	// Prints the full path of the player
	head = head->next;
	while(head != NULL){
		printf("%c -> ", head->val);
		head = head->next;
	}
	return 0;
}
