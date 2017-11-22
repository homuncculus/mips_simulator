#include <stdio.h>

#include "signal.h"
#include "gate.h"
#include "rcadder.h"
#include "mux.h"
#include "alu.h"

void ControlUnit(bus6 opcode, bus6 funct, 
					  wire * reg_write, wire * reg_dest,
					  wire * mem_read, wire * mem_write, wire * mem_toreg,
					  wire * jump, wire * branch,
					  wire * alu_src, bus3 alu_op)
{
	*reg_write = OR2_1(funct[0], opcode[2]);

	*reg_dest = OR2_1(
						funct[0], 
						AND6_1(opcode[0], NOT_1(opcode[1]), NOT_1(opcode[2]), NOT_1(opcode[3]), opcode[4], opcode[5])
						);

	*mem_read = AND6_1(opcode[0], NOT_1(opcode[1]), NOT_1(opcode[2]), NOT_1(opcode[3]), opcode[4], opcode[5]);

	*mem_write = AND6_1(opcode[0], NOT_1(opcode[1]), opcode[2], NOT_1(opcode[3]), opcode[4], opcode[5]);

	*mem_toreg = AND6_1(opcode[0], NOT_1(opcode[1]), opcode[2], NOT_1(opcode[3]), opcode[4], opcode[5]);

	*jump = AND6_1(NOT_1(opcode[0]), NOT_1(opcode[1]), NOT_1(opcode[2]), NOT_1(opcode[3]), opcode[4], NOT_1(opcode[5]));

	*branch = AND6_1(NOT_1(opcode[0]), NOT_1(opcode[1]), NOT_1(opcode[2]), opcode[3], NOT_1(opcode[4]), '1');

	*alu_src = OR2_1(
					AND3_1(NOT_1(opcode[0]), NOT_1(opcode[1]), opcode[2]),
					AND2_1(opcode[0], NOT_1(opcode[1]))
					);

	alu_op[0] = OR3_1(
						AND6_1(funct[0], NOT_1(funct[1]), NOT_1(funct[2]), NOT_1(funct[3]), funct[4], '1'),
						AND6_1(funct[0], NOT_1(funct[1]), funct[2], NOT_1(funct[3]), funct[4], NOT_1(funct[5])), 
						AND3_1(
							NOT_1(opcode[0]),
							NOT_1(opcode[1]),
							OR2_1(
								AND4_1(opcode[2], NOT_1(opcode[3]), opcode[4], NOT_1(opcode[5])),
								AND3_1(NOT_1(opcode[2]), opcode[3], NOT_1(opcode[4]))
								)
							)
						);

	alu_op[1] = NOT_1(OR2_1(
						AND6_1(NOT_1(opcode[0]), NOT_1(opcode[1]), opcode[2], opcode[3], NOT_1(opcode[4]), '1'),
						AND6_1(funct[0], NOT_1(funct[1]), NOT_1(funct[2]), funct[3], NOT_1(funct[4]), '1')
						));

	alu_op[2] = OR2_1(
						AND4_1(funct[0], NOT_1(funct[1]), XOR2_1(funct[2], funct[3]), XOR2_1(funct[4], funct[5])), 
						AND4_1(
							NOT_1(opcode[0]), 
							NOT_1(opcode[1]),
							opcode[2],
							OR2_1(
								AND3_1(NOT_1(opcode[3]), opcode[4], NOT_1(opcode[5])),
								AND3_1(opcode[3], NOT_1(opcode[4]), opcode[5])
								)
							)
						);

	appendnull(3, alu_op);

}

static void _ControlUnitDriverInst(char * name, bus6 opcode, bus6 funct)
{
	wire reg_write, reg_dest;
	wire mem_read, mem_write, mem_toreg;
	wire jump, branch;
	wire alu_src;
	bus3 alu_op;
	
	ControlUnit(opcode, funct, &reg_write, &reg_dest, &mem_read, &mem_write, &mem_toreg, &jump, &branch, &alu_src, alu_op);
	printf("%s\t%s\t%s\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%s\n", 
		name, opcode, funct, reg_write, reg_dest, mem_read, mem_write, mem_toreg, jump, branch, alu_src, alu_op);
}
void ControlUnitDriver(void)
{
	printf("name\topcode\tfunct\treg_write\t\tmem_write\t\tbranch\n\t\t\t\treg_dest\t\tmem_toreg\t\talu_src\n\t\t\t\t\tmem_read\t\tjump\t\t\talu_op\n\n");
	_ControlUnitDriverInst("add", 	"000000", "100000");
	_ControlUnitDriverInst("addu", 	"000000", "100001");
	_ControlUnitDriverInst("sub", 	"000000", "100010");
	_ControlUnitDriverInst("subu", 	"000000", "100011");
	_ControlUnitDriverInst("tco", 	"000000", "100110");
	_ControlUnitDriverInst("addi", 	"001000", "000000");
	_ControlUnitDriverInst("addiu", 	"001001", "000000");
	_ControlUnitDriverInst("lw", 		"100011", "011000");
	_ControlUnitDriverInst("sw", 		"101011", "000000");
	_ControlUnitDriverInst("and", 	"000000", "100100");
	_ControlUnitDriverInst("andi", 	"001100", "000000");
	_ControlUnitDriverInst("or", 		"000000", "100101");
	_ControlUnitDriverInst("ori", 	"001101", "000000");
	_ControlUnitDriverInst("slt", 	"000000", "101010");
	_ControlUnitDriverInst("slti", 	"001010", "000000");
	_ControlUnitDriverInst("beq",		"000100", "000000");
	_ControlUnitDriverInst("bne", 	"000101", "000000");
	_ControlUnitDriverInst("j", 		"000010", "000000");
}

