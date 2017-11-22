#ifndef __RCADDER_H__
#define __RCADDER_H__

#include "gate.h"
#include "signal.h"

void RCAdder_1(wire sum, wire * cout, wire a, wire b, wire cin);
void RCAdder_8(bus8 sum, wire * cout, bus8 a, bus8 b, wire cin);
void RCAdder_16(bus16 sum, wire * cout, bus16 a, bus16 b, wire cin);
void RCAdder_32(bus32 sum, wire * cout, bus32 a, bus32 b, wire cin);

void RCAdderDriver(void);

#endif
