/*
 * HW1.c
 *
 *  Created on: Aug 23, 2019
 *      Author: Taylor Cox
 */

#include <stdio.h>
#include <stdlib.h>
#include "production.h"
#include "tests.h"
#include "TaylorCox.h"


main(int argc, char* argv[]){
	puts("!!!Running HW2!!!");
	if(tests()){
		puts("Tests succeeded! Running production...");
		production(argc, argv);
	} else {
		puts("Tests Failed!");
	}
	return EXIT_SUCCESS;
}
