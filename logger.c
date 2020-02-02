/*
 * logger.c
 *
 *  Created on: Sep 4, 2019
 *      Author: Taylor Cox
 */

#include "logger.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log(const char* tag, const char* msg) {
	time_t now;
	time(&now);
	FILE* fp = fopen("/logging/log.txt", "w");
	fprintf(fp, "%s [%s]: %s", ctime(&now), tag, msg);
}
