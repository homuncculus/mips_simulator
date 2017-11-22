#include <libgen.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "signal.h"

#define DEBUG		0
#define MAX_LINE	50	

int LoadMemory(char * binfilename, bus8 memory[4096])
{
	char line[MAX_LINE];
	int addr, i;
	FILE * binfile;

	binfile = fopen(binfilename, "r");
	if (!binfile) {
		fprintf(stderr, "error: unable to open %s for reading\n", binfilename);
		return 0;
	}

	for (i=0; i < 4096; i++) setbus8(memory[i], "00000000");

	while (fgets(line, MAX_LINE, binfile)) {
		addr = bus32toint(line);
		setbus8(memory[addr], &line[33]);
		if (DEBUG) {
			printf("M[%.2d] <- %.8s\n", addr, &line[33]);
			printf("M[%.2d] -> %.8s\n", addr, memory[addr]);
		}
	}
	fclose(binfile);

	return 1;
}

