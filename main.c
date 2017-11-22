#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alu.h"
#include "assembler.h"
#include "gate.h"
#include "mux.h"
#include "rcadder.h"
#include "signal.h"
#include "memory.h"
#include "control.h"
#include "loader.h"
#include "regfileaccess.h"

static char * _parse_filename(char * filepath)
{
   char * base = NULL;
   char * extension = NULL;

   if (filepath == NULL) return base;

   base = strdup(basename(filepath));
   extension = strchr(base, '.');

   if (extension == NULL) {
      fprintf(stderr, "error: filename must have a asm extension\n");
		return NULL;
   } else {
      *extension = '\0';
      extension++;
      if (strcmp(extension, "asm") != 0) {
         fprintf(stderr, "error: filename must have a asm extension\n");
			return NULL;
      }
   }
   return base;
}

int main(int argc, char ** argv)
{
	char * binfilename = NULL;
	char * srcfilename = NULL;
	char * base = NULL;
	int i, cycle;
	bus32 tmp;

	bus8 inst_mem[4096];	/* instruction memory */
	bus8 main_mem[4096];	/* main memory */
	bus32 gnd;				/* ground bus signal */
	bus32 pc;				/* program counter */
	bus32 pc4;				/* PC + 4 bus */
	bus32 ir;				/* instruction register */
	bus32 jmp_addr;		/* jump bus */
	bus32 imm_sext;		/* immediate sign extended bus */
	bus32 imm_shext;		/* immediate sign extended shifted bus */
	bus32 branch_addr;	/* branch bus */
	bus32 mbranch_addr;	/* mbranch bus */

	/* control unit signals */
	wire reg_write, reg_dest;
	wire mem_read, mem_write, mem_toreg;
	wire jump, branch;
	wire alu_src;
	bus3 alu_op;

	/* register memory signals & controls */
	bus32 reg_in, reg_out1, reg_out2;
	bus32 reg_write_addr;

	/* main memory signal */
	bus32 mem_out;
	
	/* alu signals */
	wire zero;
	bus32 alu_src_val, alu_out;

	if (argc == 1) {
		fprintf(stderr, "usage: %s <filename>\n", argv[0]);
		return -1;
	}
	
	srcfilename = argv[1];
	base = _parse_filename(srcfilename);
	if (!base) return -1;
	binfilename = malloc(sizeof(char) * (strlen(base) + 5));
	sprintf(binfilename, "%s.bin", base);

	printf("assembling %s to %s...\n", srcfilename, binfilename);
	if (!Assemble(srcfilename, binfilename)) return -1;

	printf("loading %s into memory...\n", binfilename);
	LoadMemory(binfilename, inst_mem);	


	/* load PC with initial VM address of 0x00000000 */
	setbus32(gnd, "00000000000000000000000000000000");
	setbus32(pc, gnd);

	/* initialize memory */
	InitializeRegisterFileAccess();
	for (i=0; i < 4096; i++) setbus8(main_mem[i], "00000000");

   for(cycle=0; ; cycle++) 
	{
		/* load IR with PC value */
		MemoryAccess(ir, pc, gnd, '0', inst_mem); 

		/* report fetched register values */
		printf("cycle: %d, PC: %.32s (%d), IR: %.32s\n\t", cycle, pc, bus32toint(pc), ir);

		/* halt check */
		if (bus32toint(ir) == 0x0000003F) {
			printf("\nmachine halted\n");
			break;
		}
	
		/* PC + 4 data path */
		RCAdder_32(pc4, gnd, pc, "00000000000000000000000000000100", '0');

		/* jump data path */
		shiftleft2x(jmp_addr, ir);
		jmp_addr[0] = pc4[0];
		jmp_addr[1] = pc4[1];
		jmp_addr[2] = pc4[2];
		jmp_addr[3] = pc4[3];

		/* sign extended / shifted immediate data path */
		signextend(imm_sext, &ir[16]); 
		shiftleft2x(imm_shext, imm_sext); 

		/* control unit data path */
		ControlUnit(ir, &ir[26], &reg_write, &reg_dest,
						&mem_read, &mem_write, &mem_toreg, 
						&jump, &branch, &alu_src, alu_op);

		/* register memory data path - read */
		Mux2_5(reg_write_addr, &ir[11], &ir[16], reg_dest);
		RegisterFileAccess(&reg_out1, &reg_out2, &ir[6], &ir[11], reg_write_addr, reg_in, '0');

		/* alu data path */
		Mux2_32(alu_src_val, reg_out2, imm_sext, alu_src);
		zero = ALU(&alu_out, reg_out1, alu_src_val, alu_op);

		/* branch data path */
		RCAdder_32(branch_addr, gnd, pc4, imm_shext, '0');
		Mux2_32(mbranch_addr, pc4, branch_addr, AND2_1(zero, branch));
		Mux2_32(pc, mbranch_addr, jmp_addr, jump);

		/* main memory data path */
		MemoryAccess(mem_out, alu_out, reg_out2, mem_write, main_mem);
		Mux2_32(reg_in, alu_out, mem_out, mem_toreg);

		/* register memory data path - write */
		RegisterFileAccess(&reg_out1, &reg_out2, &ir[6], &ir[11], reg_write_addr, reg_in, reg_write);

		/* dump register memory and signal information */
		for (i=0; i < 14; i++) {
			inttobusn(i, 5, tmp);
			RegisterFileAccess(&reg_out1, &reg_out2, tmp, &ir[11], reg_write_addr, reg_in, '0');
			printf("R%d: %d, ", i, bus32toint(reg_out1));
		}
		printf("\b\b\n\tbranch_addr = %.32s (%d) jmp_addr = %.32s (%d)\n",
			branch_addr, bus32toint(branch_addr), jmp_addr, bus32toint(jmp_addr));
		printf("\topcode = %.6s, imm_sext = %.32s (%d), imm_shext = %.32s (%d), PC+4 = %.32s (%d)\n",
			ir, imm_sext, bus32toint(imm_sext), imm_shext, bus32toint(imm_shext), pc4, bus32toint(pc4));
		printf("\treg_write = %c, reg_dest = %c, mem_read = %c, mem_write = %c, mem_toreg = %c, jump = %c, branch = %c, alu_src = %c, alu_op = %.3s, zero = %c\n",
			reg_write, reg_dest, mem_read, mem_write, mem_toreg, jump, branch, alu_src, alu_op, zero);
		getchar();
	}

	printf("\ntotal no. cycles: %d\n", cycle);

    // report end of program information

	free(binfilename);
}

