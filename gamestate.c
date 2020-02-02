/*
 * gamestate.c
 *
 *  Created on: Sep 3, 2019
 *      Author: Taylor Cox
 */

#include <stdio.h>
#include <stdlib.h>
#include "TaylorCox.h"


char update(Gamestate* gamestate) {
	// Update the board to accurately represent where the moving marker is.
	// Used to call more functions before consolidated
	return move(gamestate);

}

void draw(Gamestate* gamestate) {
	// Draws the current board state to the screen
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			printf("%c ", gamestate->board.state[i][j]);
		}
		printf("\n");
	}

}

void reset(Gamestate* gamestate) {
	// Resets the gamestate, marker in the middle and board clear
	Marker start = {(SIZE-1)/2, (SIZE-1)/2, -1};
	clearBoard(&(gamestate->board));
	gamestate->marker = start;
	gamestate->board.state[gamestate->marker.x][gamestate->marker.y] = 'X';
}

char move(Gamestate* gs){
	// Moves the marker to a random point on the board
	int oldx = gs->marker.x, oldy = gs->marker.y;

	char toReplace = 'E';
	char toReturn = 'E';

	// MOVEMENT
	switch(rand() % 4) {
	case 0: // LEFT
		gs->marker.y--;
		toReplace = '-';
		toReturn = 'L';
		break;

	case 1: // RIGHT
		gs->marker.y++;
		toReplace = '-';
		toReturn = 'R';
		break;

	case 2: // UP
		gs->marker.x--;
		toReplace = '|';
		toReturn = 'U';
		break;

	case 3: // DOWN
		gs->marker.x++;
		toReplace = '|';
		toReturn = 'D';
		break;

	default:
		gs->marker.x++;
		toReplace = '|';
		toReturn = 'D';
		break;
	}

	//Handles out of boundry errors
	if(gs->marker.x > SIZE - 1) gs->marker.x = 0;
	if(gs->marker.y > SIZE - 1) gs->marker.y = 0;
	if(gs->marker.x < 0) gs->marker.x = SIZE - 1;
	if(gs->marker.y < 0) gs->marker.y = SIZE - 1;

	gs->board.state[oldx][oldy] = toReplace;
	gs->board.state[gs->marker.x][gs->marker.y] = 'X';

	return toReturn;
}
