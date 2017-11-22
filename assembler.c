#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assembler.h"
#include "signal.h"

#define DEBUG		0
#define MAX_LINE 	40

struct instruction {
	char name[5];
	char type;
	char opcode[6];
	char funct[6];
};

static struct instruction _instructions[] = {
	{"add", 		'r', "000000", "100000"},
	{"addu",		'r', "000000", "100001"},
	{"sub", 		'r', "000000", "100010"},
	{"subu", 	'r', "000000", "100011"},
	{"addi", 	'i', "001000", "000000"},
	{"addiu",	'r', "001001", "000000"},
	{"lw", 		'i', "100011", "011000"},
	{"sw", 		'i', "101011", "000000"},
	{"and", 		'r', "000000", "100100"},
	{"andi", 	'i', "001100", "000000"},
	{"or", 		'r', "000000", "100101"},
	{"ori", 		'i', "001101", "000000"},
	{"slt", 		'i', "000000", "101010"},
	{"slti", 	'i', "001010", "000000"},
	{"beq",		'i', "000100", "000000"},
	{"bne", 		'i', "000101", "000000"},
	{"j", 		'j', "000010", "000000"},
	{"halt",		'h', "000000", "000000"}
};

static char _regnum[32][5] = 
	{"00000", "00001", "00010", "00011", "00100", "00101", "00110", "00111", 
	 "01000", "01001", "01010", "01011", "01100", "01101", "01110", "01111",
	 "10000", "10001", "10010", "10011", "10100", "10101", "10110", "10111", 
	 "11000", "11001", "11010", "11011", "11100", "11101", "11110", "11111"};

static char * _getregnum(char * token)
{
	return _regnum[atoi(&token[1])];
}

static void _tokenize(char * line, char ** tokens)
{
	int i, len;
	for (i=0; i < 4; i++) {
		tokens[i] = strtok(line, " ,()");
		line = NULL;
		if (tokens[i]) {
			len = strlen(tokens[i]);
			if ((tokens[i][len-1] == '\n') || (tokens[i][len-1] == '\r')) tokens[i][len-1] = '\0';
		}
	}
}

static int _assembleop(FILE * binfile, int linenum, char ** tokens, struct instruction * inst)
{
	char * rs;
	char * rt;
	char * rd;
	char imm[26];
	bus32 addr1, addr2, addr3, addr4;

	inttobusn(linenum, 32, addr1);
	inttobusn(linenum+1, 32, addr2);
	inttobusn(linenum+2, 32, addr3);
	inttobusn(linenum+3, 32, addr4);

	switch (inst->type) {

		case 'i':
			if (tokens[0][1] == 'w') {
				if ((tokens[1][0] != '$') || (tokens[3][0] != '$')) {
					fprintf(stderr, "error:%d: I-type instructions must have register operands and an immediate value\n", linenum);
					return 0;	
				}
				rs = _getregnum(tokens[3]);
				inttobusn(strtol(tokens[2], NULL, 16), 16, imm);
			} else {
				if ((tokens[1][0] != '$') || (tokens[2][0] != '$')) {
					fprintf(stderr, "error:%d: I-type instructions must have register operands and an immediate value\n", linenum);
					return 0;	
				}
				rs = _getregnum(tokens[2]);
				inttobusn(strtol(tokens[3], NULL, 16), 16, imm);
			}
			rt = _getregnum(tokens[1]);
			fprintf(binfile, "%.32s %.6s%.2s\n%.32s %.3s%.5s\n%.32s %.8s\n%.32s %.8s\n", 
				addr1, inst->opcode, rs, addr2, &rs[2], rt, addr3, imm, addr4, &imm[8]);
			if (DEBUG) {
				printf("opcode = %.6s, rs = %.5s, rt = %.5s, imm = %.16s -> %s %s %s %s\n", 
					inst->opcode, rs, rt, imm, tokens[0], tokens[1], tokens[2], tokens[3]); 
			}
			break;

		case 'h':
			fprintf(binfile, "%.32s 00000000\n%.32s 00000000\n%.32s 00000000\n%.32s 00111111\n", 
				addr1, addr2, addr3, addr4);
			if (DEBUG) printf("halt\n");
			return 2;
			break;

		case 'j':
			inttobusn(strtol(tokens[1], NULL, 16), 26, imm);
			fprintf(binfile, "%.32s %.6s%.2s\n%.32s %.8s\n%.32s %.8s\n%.32s %.8s\n", 
				addr1, inst->opcode, imm, addr2, &imm[2], addr3, &imm[10], addr4, &imm[18]); 
			if (DEBUG) {
				printf("opcode = %.6s, imm = %.26s -> %s %s\n", 
					inst->opcode, imm, tokens[0], tokens[1]); 
			}
			break;

		case 'r':
			if ((tokens[1][0] != '$') || (tokens[2][0] != '$') || (tokens[3][0] != '$')) {
				fprintf(stderr, "error:%d: R-type instructions can only have register operands\n", linenum);
				return 0;	
			}
			rs = _getregnum(tokens[2]);
			rt = _getregnum(tokens[3]);
			rd = _getregnum(tokens[1]);
			fprintf(binfile, "%.32s %.6s%.2s\n%.32s %.3s%.5s\n%.32s 00000%.3s\n%.32s %.2s%.6s\n", 
				addr1, inst->opcode, rs, addr2, &rs[2], rt, addr3, &rt[2], addr4, rd, inst->funct);
			if (DEBUG) {
				printf("opcode = %.6s, rs = %.5s, rt = %.5s, rd = %.5s, funct = %.6s -> %s %s %s %s\n",
					inst->opcode, rs, rt, rd, inst->funct, tokens[0], tokens[1], tokens[2], tokens[3]); 
			}
			break;
	}
	
	return 1;
}

int Assemble(char * srcfilename, char * binfilename)
{
	char srcline[MAX_LINE];
	char * tokens[4];
	FILE * binfile;
	FILE * srcfile;
	int i, address;
	struct instruction * inst;

	binfile = fopen(binfilename, "w");
	if (!binfile) {
		fprintf(stderr, "error: unable to open %s for writing\n", binfilename);
		return 0;
	} 
	srcfile = fopen(srcfilename, "r");	
	if (!srcfile) {
		fprintf(stderr, "error: unable to open %s for reading\n", srcfilename);
		fclose(binfile);
		return 0;
	}

	address = 0;
	while (fgets(srcline, MAX_LINE, srcfile))
	{
		_tokenize(srcline, tokens);
		inst = NULL;
		for (i=0; i < 18; i++) {
			if (strcmp(tokens[0], _instructions[i].name) == 0) {
				inst = &_instructions[i];
				break;
			}
		}
		if (!inst) {
			fprintf(stderr, "error:%d: instruction %s not recognized\n", address, tokens[0]);
			fclose(srcfile);
			fclose(binfile);
			return 0;
		} else {
			switch (_assembleop(binfile, address, tokens, inst)) {
				case 0:
					return 0;
				case 1:
					break;	
				case 2:	/* halt instruction encountered */
					if (DEBUG) printf("\n");
					fclose(srcfile);
					fclose(binfile);
					return 1;
			}
		}
		address += 4;
	}
	if (DEBUG) printf("\n");
	fclose(srcfile);
	fclose(binfile);
	return 1;
}

