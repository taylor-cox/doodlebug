/*
 * board.c
 *
 *  Created on: Sep 3, 2019
 *      Author: Taylor Cox
 */

#include <stdio.h>
#include <stdlib.h>
#include "board.h"


void clearBoard(Board* b){
	// Clears the board with O
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			b->state[i][j] = 'O';
		}
	}
}


