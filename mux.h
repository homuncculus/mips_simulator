#ifndef __MUX_H__
#define __MUX_H__

#include "signal.h"

wire Mux2_1(wire in1, wire in2, wire select);
void Mux2_5(bus5 out, bus5 in1, bus5 in2, wire select);
void Mux2_8(bus8 out, bus8 in1, bus8 in2, wire select);
void Mux2_16(bus16 out, bus16 in1, bus16 in2, wire select);
void Mux2_32(bus32 out, bus32 in1, bus32 in2, wire select);
wire Mux4_1(wire in1, wire in2, wire in3, wire in4, bus2 select);
void Mux4_8(bus8 out, bus8 in1, bus8 in2, bus8 in3, bus8 in4, bus2 select);
void Mux4_16(bus16 out, bus16 in1, bus16 in2, bus16 in3, bus16 in4, bus2 select);
void Mux4_32(bus32 out, bus32 in1, bus32 in2, bus32 in3, bus32 in4, bus2 select);
wire Mux8_1(wire in1, wire in2, wire in3, wire in4, wire in5, wire in6, wire in7, wire in8, bus3 select);
void Mux8_8(bus8 out, bus8 in1, bus8 in2, bus8 in3, bus8 in4, bus8 in5, bus8 in6, bus8 in7, bus8 in8, bus3 select);
void Mux8_16(bus16 out, bus16 in1, bus16 in2, bus16 in3, bus16 in4, bus16 in5, bus16 in6, bus16 in7, bus16 in8, bus3 select);
void Mux8_32(bus32 out, bus32 in1, bus32 in2, bus32 in3, bus32 in4, bus32 in5, bus32 in6, bus32 in7, bus32 in8, bus3 select);

void MuxDriver(void);

#endif
