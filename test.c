
/*
 * test.c
 *
 *  Created on: Apr 22, 2023
 *      Author: jconrad
 */

//#define DEBUG			//DEBUG must be defined here or on gcc command line

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "DebugKit.h"


int main(int argc, char* argv[]) {

	int c;

	printf("Starting...\n");

	opterr = 0;


	while ((c=getopt(argc,argv,"D")) != -1) {
		switch (c) {
		case 'D':
			DK_SET_VAR(foo,1);
			break;
		case '?':
			if (optopt == 'D') fprintf(stderr,"-%c requires an argument.\n",optopt);
			else if (isprint(optopt)) fprintf(stderr,"Unknown option -%c\n",optopt);
			return 1;
		default:
			abort();
		} //switch
	} //while

	DK_TRACE(foo,"Debugging foo\n");
	DK_TRACE(zot,"Debugging zot\n");

	return 0;
}
