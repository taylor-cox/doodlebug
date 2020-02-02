/*
 * tests.h
 *
 *  Created on: Aug 22, 2019
 *      Author: Taylor Cox
 */

#include <stdlib.h>
#include <stdbool.h>
#include "board.h"

#ifndef TESTS_H_
#define TESTS_H_

bool tests();
bool testBoard();
bool testGamestate();
bool testClearBoard();
bool testEqual(Board b, char tester[][SIZE]);
bool testUpdate();
bool testDraw();
bool testReset();
bool testMove();


#endif /* TESTS_H_ */
