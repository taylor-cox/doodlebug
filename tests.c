/*
 * tests.c
 *
 *  Created on: Aug 22, 2019
 *      Author: Taylor Cox
 */

#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include "tests.h"
#include "TaylorCox.h"

bool tests() {
	// All tests
	printf("Testing...\n");
	bool t1 = testBoard();
	bool t2 = testGamestate();
	return t1 && t2;
}

bool testBoard() {
	// Test all functions on board
	bool t1 = testClearBoard();
	return t1;
}

bool testClearBoard() {
	// Tests clearing the board
	Marker mkr = {0, 0};
	Board bd = {};

	// Initialize the tester array.
	char tester[SIZE][SIZE];
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			tester[i][j] = 'O';
		}
	}

	// Tests
	bool t1 = !testEqual(bd, tester);
	clearBoard(&bd);
	bool t2 = testEqual(bd, tester);

	return t1 && t2;
}

bool testEqual(Board b, char tester[][SIZE]) {
	// Tests whether a board and a double array of characters is equal
	bool holder = true;
	for(int i = 0; i < SIZE && holder; i++){
		for (int j = 0; j < SIZE && holder; j++) {
			holder = b.state[i][j] == tester[i][j];
		}
	}
	return holder;
}

bool testGamestate() {
	// Tests all functions that operate on gamestates
	bool t1 = testUpdate();
	bool t2 = testDraw();
	bool t3 = testReset();
	bool t4 = testMove();
	return t1 && t2 && t3 && t4;
}

bool testUpdate() {
	// Update just calls move
	bool t1 = testMove();
	return t1;
}

bool testDraw() {
	// Tests drawing the board to the console
	char resp;
	Marker mkr = {0, 0};
	Board bd;
	clearBoard(&bd);
	Gamestate gs1 = {mkr, bd};
	reset(&gs1);
	draw(&gs1);
	printf("Does this look like a board with zeros everywhere but\nthe top left corner? (y/n) ");
	scanf("%c", &resp);
	fflush(stdout);
	return resp == 'y';
}

bool testReset() {
	// Tests reseting the gamestate
	Marker mkr = {0, 0};
	Board bd = {};
	clearBoard(&bd);
	Gamestate gs1 = {mkr, bd};
	reset(&gs1);

	char tester[SIZE][SIZE];
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			tester[i][j] = 'O';
		}
	}
	tester[2][2] = 'X';
	bool t1 = testEqual(gs1.board, tester);
	return t1;
}

bool testMove() {
	// Initialize variables
	Marker mkr = {0, 0};
	Board bd = {};
	clearBoard(&bd);
	Gamestate gs1 = {mkr, bd};

	// Init Testing Board
	char tester[SIZE][SIZE];
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			tester[i][j] = 'O';
		}
	}

	// Full tests of move
	bool t1 = testEqual(gs1.board, tester);
	move(&gs1);
	bool t2 = !testEqual(gs1.board, tester);
	reset(&gs1);
	tester[2][2] = 'X';
	bool t3 = testEqual(gs1.board, tester);
	move(&gs1);
	bool t4 = (gs1.board.state[2][2] == '|' || gs1.board.state[2][2] == '-');
	bool t5 = (gs1.board.state[1][2] == 'X' ||
			gs1.board.state[3][2] == 'X' ||
			gs1.board.state[2][1] == 'X' ||
			gs1.board.state[2][3] == 'X');

	return t1 && t2 && t3 && t4 && t5;
}
