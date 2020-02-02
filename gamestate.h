/*
 * gamestate.h
 *
 *  Created on: Sep 3, 2019
 *      Author: Taylor Cox
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include "marker.h"
#include "board.h"

typedef struct {
	Marker marker;
	Board board;
} Gamestate;

char update(Gamestate* gamestate);
void draw(Gamestate* gamestate);
void reset(Gamestate* gamestate);
char move(Gamestate* gamestate);


#endif /* GAMESTATE_H_ */
