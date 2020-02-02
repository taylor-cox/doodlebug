/*
 * board.h
 *
 *  Created on: Sep 3, 2019
 *      Author: Taylor Cox
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "marker.h"

#define SIZE 5

typedef struct {
	char state[SIZE][SIZE];
} Board;

void clearBoard(Board* b);

#endif /* BOARD_H_ */
