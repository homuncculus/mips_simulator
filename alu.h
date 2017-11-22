#ifndef __ALU_H__
#define __ALU_H__

#include "signal.h"

wire ALU(bus32 * out, bus32 in1, bus32 in2, bus3 op);
void ALUDriver(void);

#endif

