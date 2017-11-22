#ifndef __CONTROL_H__
#define __CONTROL_H__

#include "signal.h"

void ControlUnit(bus6 opcode, bus6 funct, 
					  wire * reg_write, wire * reg_dest,
					  wire * mem_read, wire * mem_write, wire * mem_toreg,
					  wire * jump, wire * branch,
					  wire * alu_src, bus3 alu_op);

void ControlUnitDriver(void);

#endif

