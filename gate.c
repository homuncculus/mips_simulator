#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gate.h"
#include "signal.h"

wire AND2_1(wire in1, wire in2)
{
	if ((in1 == '1') && (in2 == '1')) {
		return '1';
	} else {
		return '0';
	}
}
void AND2_2(bus2 out, bus2 in1, bus2 in2)
{
	out[0] = AND2_1(in1[0], in2[0]);
	out[1] = AND2_1(in1[1], in2[1]);
}
void AND2_8(bus8 out, bus8 in1, bus8 in2)
{
	AND2_2(out, in1, in2);
	AND2_2(&out[2], &in1[2], &in2[2]);
	AND2_2(&out[4], &in1[4], &in2[4]);
	AND2_2(&out[6], &in1[6], &in2[6]);
}
void AND2_16(bus16 out, bus16 in1, bus16 in2)
{
	AND2_8(out, in1, in2);
	AND2_8(&out[8], &in1[8], &in2[8]);
}
void AND2_32(bus32 out, bus32 in1, bus32 in2)
{
	AND2_16(out, in1, in2);
	AND2_16(&out[16], &in1[16], &in2[16]);
}
wire AND3_1(wire in1, wire in2, wire in3)
{
	return AND2_1(AND2_1(in1, in2), in3);
}
void AND3_2(bus2 out, bus2 in1, bus2 in2, bus2 in3)
{
	out[0] = AND3_1(in1[0], in2[0], in3[0]);
	out[1] = AND3_1(in1[1], in2[1], in3[1]);
}
void AND3_8(bus8 out, bus8 in1, bus8 in2, bus8 in3)
{
	AND3_2(out, in1, in2, in3);
	AND3_2(&out[2], &in1[2], &in2[2], &in3[2]);
	AND3_2(&out[4], &in1[4], &in2[4], &in3[4]);
	AND3_2(&out[6], &in1[6], &in2[6], &in3[6]);
}
void AND3_16(bus16 out, bus16 in1, bus16 in2, bus16 in3)
{
	AND3_8(out, in1, in2, in3);
	AND3_8(&out[8], &in1[8], &in2[8], &in3[8]);
}
void AND3_32(bus32 out, bus32 in1, bus32 in2, bus32 in3)
{
	AND3_16(out, in1, in2, in3);
	AND3_16(&out[16], &in1[16], &in2[16], &in3[16]);
}
wire AND4_1(wire in1, wire in2, wire in3, wire in4)
{
	return AND2_1(AND2_1(in1, in2), AND2_1(in3, in4));
}
void AND4_2(bus2 out, bus2 in1, bus2 in2, bus2 in3, bus2 in4)
{
	out[0] = AND4_1(in1[0], in2[0], in3[0], in4[0]);
	out[1] = AND4_1(in1[1], in2[1], in3[1], in4[1]);
}
void AND4_8(bus8 out, bus8 in1, bus8 in2, bus8 in3, bus8 in4)
{
	AND4_2(out, in1, in2, in3, in4);
	AND4_2(&out[2], &in1[2], &in2[2], &in3[2], &in4[2]);
	AND4_2(&out[4], &in1[4], &in2[4], &in3[2], &in4[4]);
	AND4_2(&out[6], &in1[6], &in2[6], &in3[6], &in4[4]);
}
void AND4_16(bus16 out, bus16 in1, bus16 in2, bus16 in3, bus16 in4)
{
	AND4_8(out, in1, in2, in3, in4);
	AND4_8(&out[8], &in1[8], &in2[8], &in3[8], &in4[8]);
}
void AND4_32(bus32 out, bus32 in1, bus32 in2, bus32 in3, bus32 in4)
{
	AND4_16(out, in1, in2, in3, in4);
	AND4_16(&out[16], &in1[16], &in2[16], &in3[16], &in4[16]);
}
wire AND6_1(wire in1, wire in2, wire in3, wire in4, wire in5, wire in6)
{
	return AND2_1(AND3_1(in1, in2, in3), AND3_1(in4, in5, in6)); 
}
void AND6_2(bus2 out, bus2 in1, bus2 in2, bus2 in3, bus2 in4, bus2 in5, bus2 in6)
{
	out[0] = AND6_1(in1[0], in2[0], in3[0], in4[0], in5[0], in6[0]);
	out[1] = AND6_1(in1[1], in2[1], in3[1], in4[1], in5[1], in6[1]);
}
void AND6_8(bus8 out, bus8 in1, bus8 in2, bus8 in3, bus8 in4, bus8 in5, bus8 in6)
{
	AND6_2(out, in1, in2, in3, in4, in5, in6);
	AND6_2(&out[2], &in1[2], &in2[2], &in3[2], &in4[2], &in5[2], &in6[2]);
	AND6_2(&out[4], &in1[4], &in2[4], &in3[4], &in4[4], &in5[4], &in6[4]);
	AND6_2(&out[6], &in1[6], &in2[6], &in3[6], &in4[6], &in5[6], &in6[6]);
}
void AND6_16(bus16 out, bus16 in1, bus16 in2, bus16 in3, bus16 in4, bus16 in5, bus16 in6)
{
	AND6_8(out, in1, in2, in3, in4, in5, in6);
	AND6_8(&out[8], &in1[8], &in2[8], &in3[8], &in4[8], &in5[8], &in6[8]);
}
void AND6_32(bus32 out, bus32 in1, bus32 in2, bus32 in3, bus32 in4, bus32 in5, bus32 in6)
{
	AND6_16(out, in1, in2, in3, in4, in5, in6);
	AND6_16(&out[16], &in1[16], &in2[16], &in3[16], &in4[16], &in5[16], &in6[16]);
}
wire AND8_1(wire in1, wire in2, wire in3, wire in4, wire in5, wire in6, wire in7, wire in8)
{
	return AND2_1(AND4_1(in1, in2, in3, in4), AND4_1(in5, in6, in7, in8));
}
void AND8_2(bus8 out, bus8 in1, bus8 in2, bus8 in3, bus8 in4, bus8 in5, bus8 in6, bus8 in7, bus8 in8)
{
	out[0] = AND8_1(in1[0], in2[0], in3[0], in4[0], in5[0], in6[0], in7[0], in8[0]);
	out[1] = AND8_1(in1[1], in2[1], in3[1], in4[1], in5[1], in6[1], in7[1], in8[1]);
}
void AND8_8(bus8 out, bus8 in1, bus8 in2, bus8 in3, bus8 in4, bus8 in5, bus8 in6, bus8 in7, bus8 in8)
{
	AND8_2(out, in1, in2, in3, in4, in5, in6, in7, in8);
	AND8_2(&out[2], &in1[2], &in2[2], &in3[2], &in4[2], &in5[2], &in6[2], &in7[2], &in8[2]);
	AND8_2(&out[4], &in1[4], &in2[4], &in3[4], &in4[4], &in5[4], &in6[4], &in7[4], &in8[4]);
	AND8_2(&out[6], &in1[6], &in2[6], &in3[6], &in4[6], &in5[6], &in6[6], &in7[6], &in8[6]);
}
void AND8_16(bus16 out, bus16 in1, bus16 in2, bus16 in3, bus16 in4, bus16 in5, bus16 in6, bus16 in7, bus16 in8)
{
	AND8_8(out, in1, in2, in3, in4, in5, in6, in7, in8);
	AND8_8(&out[8], &in1[8], &in2[8], &in3[8], &in4[8], &in5[8], &in6[8], &in7[8], &in8[8]);
}
void AND8_32(bus32 out, bus32 in1, bus32 in2, bus32 in3, bus32 in4, bus32 in5, bus32 in6, bus32 in7, bus32 in8)
{
	AND8_16(out, in1, in2, in3, in4, in5, in6, in7, in8);
	AND8_16(&out[16], &in1[16], &in2[16], &in3[16], &in4[16], &in5[16], &in6[16], &in7[16], &in8[16]);
}

wire NAND2_1(wire in1, wire in2)
{
	return NOT_1(AND2_1(in1, in2)); 
}
void NAND2_2(bus2 out, bus2 in1, bus2 in2)
{
	out[0] = NAND2_1(in1[0], in2[0]);
	out[1] = NAND2_1(in1[1], in2[1]);
}
void NAND2_8(bus8 out, bus8 in1, bus8 in2)
{
	NAND2_2(out, in1, in2);
	NAND2_2(&out[2], &in1[2], &in2[2]);
	NAND2_2(&out[4], &in1[4], &in2[4]);
	NAND2_2(&out[6], &in1[6], &in2[6]);
}
void NAND2_16(bus16 out, bus16 in1, bus16 in2)
{
	NAND2_8(out, in1, in2);
	NAND2_8(&out[8], &in1[8], &in2[8]);
}
void NAND2_32(bus32 out, bus32 in1, bus32 in2)
{
	NAND2_16(out, in1, in2);
	NAND2_16(&out[16], &in1[16], &in2[16]);
}
wire NAND3_1(wire in1, wire in2, wire in3)
{
	return NOT_1(AND3_1(in1, in2, in3));
}
void NAND3_2(bus2 out, bus2 in1, bus2 in2, bus2 in3)
{
	out[0] = NAND3_1(in1[0], in2[0], in3[0]);
	out[1] = NAND3_1(in1[1], in2[1], in3[1]);
}
void NAND3_8(bus8 out, bus8 in1, bus8 in2, bus8 in3)
{
	NAND3_2(out, in1, in2, in3);
	NAND3_2(&out[2], &in1[2], &in2[2], &in3[2]);
	NAND3_2(&out[4], &in1[4], &in2[4], &in3[4]);
	NAND3_2(&out[6], &in1[6], &in2[6], &in3[6]);
}
void NAND3_16(bus16 out, bus16 in1, bus16 in2, bus16 in3)
{
	NAND3_8(out, in1, in2, in3);
	NAND3_8(&out[8], &in1[8], &in2[8], &in3[8]);
}
void NAND3_32(bus32 out, bus32 in1, bus32 in2, bus32 in3)
{
	NAND3_16(out, in1, in2, in3);
	NAND3_16(&out[16], &in1[16], &in2[16], &in3[16]);
}
wire NAND4_1(wire in1, wire in2, wire in3, wire in4)
{
	return NOT_1(AND4_1(in1, in2, in3, in4));
}
void NAND4_2(bus2 out, bus2 in1, bus2 in2, bus2 in3, bus2 in4)
{
	out[0] = NAND4_1(in1[0], in2[0], in3[0], in4[0]);
	out[1] = NAND4_1(in1[1], in2[1], in3[1], in4[1]);
}
void NAND4_8(bus8 out, bus8 in1, bus8 in2, bus8 in3, bus8 in4)
{
	NAND4_2(out, in1, in2, in3, in4);
	NAND4_2(&out[2], &in1[2], &in2[2], &in3[2], &in4[2]);
	NAND4_2(&out[4], &in1[4], &in2[4], &in3[2], &in4[4]);
	NAND4_2(&out[6], &in1[6], &in2[6], &in3[6], &in4[4]);
}
void NAND4_16(bus16 out, bus16 in1, bus16 in2, bus16 in3, bus16 in4)
{
	NAND4_8(out, in1, in2, in3, in4);
	NAND4_8(&out[8], &in1[8], &in2[8], &in3[8], &in4[8]);
}
void NAND4_32(bus32 out, bus32 in1, bus32 in2, bus32 in3, bus32 in4)
{
	NAND4_16(out, in1, in2, in3, in4);
	NAND4_16(&out[16], &in1[16], &in2[16], &in3[16], &in4[16]);
}
wire NAND6_1(wire in1, wire in2, wire in3, wire in4, wire in5, wire in6)
{
	return NOT_1(AND6_1(in1, in2, in3, in4, in5, in6)); 
}
void NAND6_2(bus2 out, bus2 in1, bus2 in2, bus2 in3, bus2 in4, bus2 in5, bus2 in6)
{
	out[0] = NAND6_1(in1[0], in2[0], in3[0], in4[0], in5[0], in6[0]);
	out[1] = NAND6_1(in1[1], in2[1], in3[1], in4[1], in5[1], in6[1]);
}
void NAND6_8(bus8 out, bus8 in1, bus8 in2, bus8 in3, bus8 in4, bus8 in5, bus8 in6)
{
	NAND6_2(out, in1, in2, in3, in4, in5, in6);
	NAND6_2(&out[2], &in1[2], &in2[2], &in3[2], &in4[2], &in5[2], &in6[2]);
	NAND6_2(&out[4], &in1[4], &in2[4], &in3[4], &in4[4], &in5[4], &in6[4]);
	NAND6_2(&out[6], &in1[6], &in2[6], &in3[6], &in4[6], &in5[6], &in6[6]);
}
void NAND6_16(bus16 out, bus16 in1, bus16 in2, bus16 in3, bus16 in4, bus16 in5, bus16 in6)
{
	NAND6_8(out, in1, in2, in3, in4, in5, in6);
	NAND6_8(&out[8], &in1[8], &in2[8], &in3[8], &in4[8], &in5[8], &in6[8]);
}
void NAND6_32(bus32 out, bus32 in1, bus32 in2, bus32 in3, bus32 in4, bus32 in5, bus32 in6)
{
	NAND6_16(out, in1, in2, in3, in4, in5, in6);
	NAND6_16(&out[16], &in1[16], &in2[16], &in3[16], &in4[16], &in5[16], &in6[16]);
}
wire NAND8_1(wire in1, wire in2, wire in3, wire in4, wire in5, wire in6, wire in7, wire in8)
{
	return NOT_1(AND8_1(in1, in2, in3, in4, in5, in6, in7, in8));
}
void NAND8_2(bus8 out, bus8 in1, bus8 in2, bus8 in3, bus8 in4, bus8 in5, bus8 in6, bus8 in7, bus8 in8)
{
	out[0] = NAND8_1(in1[0], in2[0], in3[0], in4[0], in5[0], in6[0], in7[0], in8[0]);
	out[1] = NAND8_1(in1[1], in2[1], in3[1], in4[1], in5[1], in6[1], in7[1], in8[1]);
}
void NAND8_8(bus8 out, bus8 in1, bus8 in2, bus8 in3, bus8 in4, bus8 in5, bus8 in6, bus8 in7, bus8 in8)
{
	NAND8_2(out, in1, in2, in3, in4, in5, in6, in7, in8);
	NAND8_2(&out[2], &in1[2], &in2[2], &in3[2], &in4[2], &in5[2], &in6[2], &in7[2], &in8[2]);
	NAND8_2(&out[4], &in1[4], &in2[4], &in3[4], &in4[4], &in5[4], &in6[4], &in7[4], &in8[4]);
	NAND8_2(&out[6], &in1[6], &in2[6], &in3[6], &in4[6], &in5[6], &in6[6], &in7[6], &in8[6]);
}
void NAND8_16(bus16 out, bus16 in1, bus16 in2, bus16 in3, bus16 in4, bus16 in5, bus16 in6, bus16 in7, bus16 in8)
{
	NAND8_8(out, in1, in2, in3, in4, in5, in6, in7, in8);
	NAND8_8(&out[8], &in1[8], &in2[8], &in3[8], &in4[8], &in5[8], &in6[8], &in7[8], &in8[8]);
}
void NAND8_32(bus32 out, bus32 in1, bus32 in2, bus32 in3, bus32 in4, bus32 in5, bus32 in6, bus32 in7, bus32 in8)
{
	NAND8_16(out, in1, in2, in3, in4, in5, in6, in7, in8);
	NAND8_16(&out[16], &in1[16], &in2[16], &in3[16], &in4[16], &in5[16], &in6[16], &in7[16], &in8[16]);
}

wire NOR2_1(wire in1, wire in2)
{
	return NOT_1(OR2_1(in1, in2));
}
void NOR2_2(bus2 out, bus2 in1, bus2 in2)
{
	out[0] = NOR2_1(in1[0], in2[0]);
	out[1] = NOR2_1(in1[1], in2[1]);
}
void NOR2_8(bus8 out, bus8 in1, bus8 in2)
{
	NOR2_2(out, in1, in2);
	NOR2_2(&out[2], &in1[2], &in2[2]);
	NOR2_2(&out[4], &in1[4], &in2[4]);
	NOR2_2(&out[6], &in1[6], &in2[6]);
}
void NOR2_16(bus16 out, bus16 in1, bus16 in2)
{
	NOR2_8(out, in1, in2);
	NOR2_8(&out[8], &in1[8], &in2[8]);
}
void NOR2_32(bus32 out, bus32 in1, bus32 in2)
{
	NOR2_16(out, in1, in2);
	NOR2_16(&out[16], &in1[16], &in2[16]);
}
wire NOR3_1(wire in1, wire in2, wire in3)
{
	return NOT_1(OR3_1(in1, in2, in3));
}
void NOR3_2(bus2 out, bus2 in1, bus2 in2, bus2 in3)
{
	out[0] = NOR3_1(in1[0], in2[0], in3[0]);
	out[1] = NOR3_1(in1[1], in2[1], in3[1]);
}
void NOR3_8(bus8 out, bus8 in1, bus8 in2, bus8 in3)
{
	NOR3_2(out, in1, in2, in3);
	NOR3_2(&out[2], &in1[2], &in2[2], &in3[2]);
	NOR3_2(&out[4], &in1[4], &in2[4], &in3[4]);
	NOR3_2(&out[6], &in1[6], &in2[6], &in3[6]);
}
void NOR3_16(bus16 out, bus16 in1, bus16 in2, bus16 in3)
{
	NOR3_8(out, in1, in2, in3);
	NOR3_8(&out[8], &in1[8], &in2[8], &in3[8]);
}
void NOR3_32(bus32 out, bus32 in1, bus32 in2, bus32 in3)
{
	NOR3_16(out, in1, in2, in3);
	NOR3_16(&out[16], &in1[16], &in2[16], &in3[16]);
}
wire NOR4_1(wire in1, wire in2, wire in3, wire in4)
{
	return NOT_1(OR4_1(in1, in2, in3, in4));
}
void NOR4_2(bus2 out, bus2 in1, bus2 in2, bus2 in3, bus2 in4)
{
	out[0] = NOR4_1(in1[0], in2[0], in3[0], in4[0]);
	out[1] = NOR4_1(in1[1], in2[1], in3[1], in4[1]);
}
void NOR4_8(bus8 out, bus8 in1, bus8 in2, bus8 in3, bus8 in4)
{
	NOR4_2(out, in1, in2, in3, in4);
	NOR4_2(&out[2], &in1[2], &in2[2], &in3[2], &in4[2]);
	NOR4_2(&out[4], &in1[4], &in2[4], &in3[2], &in4[4]);
	NOR4_2(&out[6], &in1[6], &in2[6], &in3[6], &in4[4]);
}
void NOR4_16(bus16 out, bus16 in1, bus16 in2, bus16 in3, bus16 in4)
{
	NOR4_8(out, in1, in2, in3, in4);
	NOR4_8(&out[8], &in1[8], &in2[8], &in3[8], &in4[8]);
}
void NOR4_32(bus32 out, bus32 in1, bus32 in2, bus32 in3, bus32 in4)
{
	NOR4_16(out, in1, in2, in3, in4);
	NOR4_16(&out[16], &in1[16], &in2[16], &in3[16], &in4[16]);
}
wire NOR6_1(wire in1, wire in2, wire in3, wire in4, wire in5, wire in6)
{
	return NOT_1(OR6_1(in1, in2, in3, in4, in5, in6)); 
}
void NOR6_2(bus2 out, bus2 in1, bus2 in2, bus2 in3, bus2 in4, bus2 in5, bus2 in6)
{
	out[0] = NOR6_1(in1[0], in2[0], in3[0], in4[0], in5[0], in6[0]);
	out[1] = NOR6_1(in1[1], in2[1], in3[1], in4[1], in5[1], in6[1]);
}
void NOR6_8(bus8 out, bus8 in1, bus8 in2, bus8 in3, bus8 in4, bus8 in5, bus8 in6)
{
	NOR6_2(out, in1, in2, in3, in4, in5, in6);
	NOR6_2(&out[2], &in1[2], &in2[2], &in3[2], &in4[2], &in5[2], &in6[2]);
	NOR6_2(&out[4], &in1[4], &in2[4], &in3[4], &in4[4], &in5[4], &in6[4]);
	NOR6_2(&out[6], &in1[6], &in2[6], &in3[6], &in4[6], &in5[6], &in6[6]);
}
void NOR6_16(bus16 out, bus16 in1, bus16 in2, bus16 in3, bus16 in4, bus16 in5, bus16 in6)
{
	NOR6_8(out, in1, in2, in3, in4, in5, in6);
	NOR6_8(&out[8], &in1[8], &in2[8], &in3[8], &in4[8], &in5[8], &in6[8]);
}
void NOR6_32(bus32 out, bus32 in1, bus32 in2, bus32 in3, bus32 in4, bus32 in5, bus32 in6)
{
	NOR6_16(out, in1, in2, in3, in4, in5, in6);
	NOR6_16(&out[16], &in1[16], &in2[16], &in3[16], &in4[16], &in5[16], &in6[16]);
}
wire NOR8_1(wire in1, wire in2, wire in3, wire in4, wire in5, wire in6, wire in7, wire in8)
{
	return NOT_1(OR8_1(in1, in2, in3, in4, in5, in6, in7, in8));
}
void NOR8_2(bus8 out, bus8 in1, bus8 in2, bus8 in3, bus8 in4, bus8 in5, bus8 in6, bus8 in7, bus8 in8)
{
	out[0] = NOR8_1(in1[0], in2[0], in3[0], in4[0], in5[0], in6[0], in7[0], in8[0]);
	out[1] = NOR8_1(in1[1], in2[1], in3[1], in4[1], in5[1], in6[1], in7[1], in8[1]);
}
void NOR8_8(bus8 out, bus8 in1, bus8 in2, bus8 in3, bus8 in4, bus8 in5, bus8 in6, bus8 in7, bus8 in8)
{
	NOR8_2(out, in1, in2, in3, in4, in5, in6, in7, in8);
	NOR8_2(&out[2], &in1[2], &in2[2], &in3[2], &in4[2], &in5[2], &in6[2], &in7[2], &in8[2]);
	NOR8_2(&out[4], &in1[4], &in2[4], &in3[4], &in4[4], &in5[4], &in6[4], &in7[4], &in8[4]);
	NOR8_2(&out[6], &in1[6], &in2[6], &in3[6], &in4[6], &in5[6], &in6[6], &in7[6], &in8[6]);
}
void NOR8_16(bus16 out, bus16 in1, bus16 in2, bus16 in3, bus16 in4, bus16 in5, bus16 in6, bus16 in7, bus16 in8)
{
	NOR8_8(out, in1, in2, in3, in4, in5, in6, in7, in8);
	NOR8_8(&out[8], &in1[8], &in2[8], &in3[8], &in4[8], &in5[8], &in6[8], &in7[8], &in8[8]);
}
void NOR8_32(bus32 out, bus32 in1, bus32 in2, bus32 in3, bus32 in4, bus32 in5, bus32 in6, bus32 in7, bus32 in8)
{
	NOR8_16(out, in1, in2, in3, in4, in5, in6, in7, in8);
	NOR8_16(&out[16], &in1[16], &in2[16], &in3[16], &in4[16], &in5[16], &in6[16], &in7[16], &in8[16]);
}

wire NOT_1(wire in)
{
	if (in == '1') {
		return '0';
	} else {
		return '1';
	}
}
void NOT_2(bus2 out, bus2 in)
{
	out[0] = NOT_1(in[0]);
	out[1] = NOT_1(in[1]);
}
void NOT_8(bus8 out, bus8 in)
{
	NOT_2(out, in);
	NOT_2(&out[2], &in[2]);
	NOT_2(&out[4], &in[4]);
	NOT_2(&out[6], &in[6]);	
}
void NOT_16(bus16 out, bus16 in)
{
	NOT_8(out, in);
	NOT_8(&out[8], &in[8]);
}
void NOT_32(bus32 out, bus32 in)
{
	NOT_16(out, in);
	NOT_16(&out[16], &in[16]);
}

wire OR2_1(wire in1, wire in2)
{
	if ((in1 == '1') || (in2 == '1')) {
		return '1';
	} else {
		return '0';
	}
}
void OR2_2(bus2 out, bus2 in1, bus2 in2)
{
	out[0] = OR2_1(in1[0], in2[0]);
	out[1] = OR2_1(in1[1], in2[1]);
}
void OR2_8(bus8 out, bus8 in1, bus8 in2)
{
	OR2_2(out, in1, in2);
	OR2_2(&out[2], &in1[2], &in2[2]);
	OR2_2(&out[4], &in1[4], &in2[4]);
	OR2_2(&out[6], &in1[6], &in2[6]);
}
void OR2_16(bus16 out, bus16 in1, bus16 in2)
{
	OR2_8(out, in1, in2);
	OR2_8(&out[8], &in1[8], &in2[8]);
}
void OR2_32(bus32 out, bus32 in1, bus32 in2)
{
	OR2_16(out, in1, in2);
	OR2_16(&out[16], &in1[16], &in2[16]);
}
wire OR3_1(wire in1, wire in2, wire in3)
{
	return OR2_1(OR2_1(in1, in2), in3);
}
void OR3_2(bus2 out, bus2 in1, bus2 in2, bus2 in3)
{
	out[0] = OR3_1(in1[0], in2[0], in3[0]);
	out[1] = OR3_1(in1[1], in2[1], in3[1]);
}
void OR3_8(bus8 out, bus8 in1, bus8 in2, bus8 in3)
{
	OR3_2(out, in1, in2, in3);
	OR3_2(&out[2], &in1[2], &in2[2], &in3[2]);
	OR3_2(&out[4], &in1[4], &in2[4], &in3[4]);
	OR3_2(&out[6], &in1[6], &in2[6], &in3[6]);
}
void OR3_16(bus16 out, bus16 in1, bus16 in2, bus16 in3)
{
	OR3_8(out, in1, in2, in3);
	OR3_8(&out[8], &in1[8], &in2[8], &in3[8]);
}
void OR3_32(bus32 out, bus32 in1, bus32 in2, bus32 in3)
{
	OR3_16(out, in1, in2, in3);
	OR3_16(&out[16], &in1[16], &in2[16], &in3[16]);
}
wire OR4_1(wire in1, wire in2, wire in3, wire in4)
{
	return OR2_1(OR2_1(in1, in2), OR2_1(in3, in4));
}
void OR4_2(bus2 out, bus2 in1, bus2 in2, bus2 in3, bus2 in4)
{
	out[0] = OR4_1(in1[0], in2[0], in3[0], in4[0]);
	out[1] = OR4_1(in1[1], in2[1], in3[1], in4[1]);
}
void OR4_8(bus8 out, bus8 in1, bus8 in2, bus8 in3, bus8 in4)
{
	OR4_2(out, in1, in2, in3, in4);
	OR4_2(&out[2], &in1[2], &in2[2], &in3[2], &in4[2]);
	OR4_2(&out[4], &in1[4], &in2[4], &in3[2], &in4[4]);
	OR4_2(&out[6], &in1[6], &in2[6], &in3[6], &in4[4]);
}
void OR4_16(bus16 out, bus16 in1, bus16 in2, bus16 in3, bus16 in4)
{
	OR4_8(out, in1, in2, in3, in4);
	OR4_8(&out[8], &in1[8], &in2[8], &in3[8], &in4[8]);
}
void OR4_32(bus32 out, bus32 in1, bus32 in2, bus32 in3, bus32 in4)
{
	OR4_16(out, in1, in2, in3, in4);
	OR4_16(&out[16], &in1[16], &in2[16], &in3[16], &in4[16]);
}
wire OR6_1(wire in1, wire in2, wire in3, wire in4, wire in5, wire in6)
{
	return OR2_1(OR3_1(in1, in2, in3), OR3_1(in4, in5, in6)); 
}
void OR6_2(bus2 out, bus2 in1, bus2 in2, bus2 in3, bus2 in4, bus2 in5, bus2 in6)
{
	out[0] = OR6_1(in1[0], in2[0], in3[0], in4[0], in5[0], in6[0]);
	out[1] = OR6_1(in1[1], in2[1], in3[1], in4[1], in5[1], in6[1]);
}
void OR6_8(bus8 out, bus8 in1, bus8 in2, bus8 in3, bus8 in4, bus8 in5, bus8 in6)
{
	OR6_2(out, in1, in2, in3, in4, in5, in6);
	OR6_2(&out[2], &in1[2], &in2[2], &in3[2], &in4[2], &in5[2], &in6[2]);
	OR6_2(&out[4], &in1[4], &in2[4], &in3[4], &in4[4], &in5[4], &in6[4]);
	OR6_2(&out[6], &in1[6], &in2[6], &in3[6], &in4[6], &in5[6], &in6[6]);
}
void OR6_16(bus16 out, bus16 in1, bus16 in2, bus16 in3, bus16 in4, bus16 in5, bus16 in6)
{
	OR6_8(out, in1, in2, in3, in4, in5, in6);
	OR6_8(&out[8], &in1[8], &in2[8], &in3[8], &in4[8], &in5[8], &in6[8]);
}
void OR6_32(bus32 out, bus32 in1, bus32 in2, bus32 in3, bus32 in4, bus32 in5, bus32 in6)
{
	OR6_16(out, in1, in2, in3, in4, in5, in6);
	OR6_16(&out[16], &in1[16], &in2[16], &in3[16], &in4[16], &in5[16], &in6[16]);
}
wire OR8_1(wire in1, wire in2, wire in3, wire in4, wire in5, wire in6, wire in7, wire in8)
{
	return OR2_1(OR4_1(in1, in2, in3, in4), OR4_1(in5, in6, in7, in8));
}
void OR8_2(bus8 out, bus8 in1, bus8 in2, bus8 in3, bus8 in4, bus8 in5, bus8 in6, bus8 in7, bus8 in8)
{
	out[0] = OR8_1(in1[0], in2[0], in3[0], in4[0], in5[0], in6[0], in7[0], in8[0]);
	out[1] = OR8_1(in1[1], in2[1], in3[1], in4[1], in5[1], in6[1], in7[1], in8[1]);
}
void OR8_8(bus8 out, bus8 in1, bus8 in2, bus8 in3, bus8 in4, bus8 in5, bus8 in6, bus8 in7, bus8 in8)
{
	OR8_2(out, in1, in2, in3, in4, in5, in6, in7, in8);
	OR8_2(&out[2], &in1[2], &in2[2], &in3[2], &in4[2], &in5[2], &in6[2], &in7[2], &in8[2]);
	OR8_2(&out[4], &in1[4], &in2[4], &in3[4], &in4[4], &in5[4], &in6[4], &in7[4], &in8[4]);
	OR8_2(&out[6], &in1[6], &in2[6], &in3[6], &in4[6], &in5[6], &in6[6], &in7[6], &in8[6]);
}
void OR8_16(bus16 out, bus16 in1, bus16 in2, bus16 in3, bus16 in4, bus16 in5, bus16 in6, bus16 in7, bus16 in8)
{
	OR8_8(out, in1, in2, in3, in4, in5, in6, in7, in8);
	OR8_8(&out[8], &in1[8], &in2[8], &in3[8], &in4[8], &in5[8], &in6[8], &in7[8], &in8[8]);
}
void OR8_32(bus32 out, bus32 in1, bus32 in2, bus32 in3, bus32 in4, bus32 in5, bus32 in6, bus32 in7, bus32 in8)
{
	OR8_16(out, in1, in2, in3, in4, in5, in6, in7, in8);
	OR8_16(&out[16], &in1[16], &in2[16], &in3[16], &in4[16], &in5[16], &in6[16], &in7[16], &in8[16]);
}

wire XOR2_1(wire in1, wire in2)
{
	if (in1 == in2) {
		return '0';
	} else {
		return '1';
	}
}
void XOR2_2(bus2 out, bus2 in1, bus2 in2)
{
	out[0] = XOR2_1(in1[0], in2[0]);
	out[1] = XOR2_1(in1[1], in2[1]);
}
void XOR2_8(bus8 out, bus8 in1, bus8 in2)
{
	XOR2_2(out, in1, in2);
	XOR2_2(&out[2], &in1[2], &in2[2]);
	XOR2_2(&out[4], &in1[4], &in2[4]);
	XOR2_2(&out[6], &in1[6], &in2[6]);
}
void XOR2_16(bus16 out, bus16 in1, bus16 in2)
{
	XOR2_8(out, in1, in2);
	XOR2_8(&out[8], &in1[8], &in2[8]);
}
void XOR2_32(bus32 out, bus32 in1, bus32 in2)
{
	XOR2_16(out, in1, in2);
	XOR2_16(&out[16], &in1[16], &in2[16]);
}
wire XOR3_1(wire in1, wire in2, wire in3)
{
	return XOR2_1(XOR2_1(in1, in2), in3);
}
void XOR3_2(bus2 out, bus2 in1, bus2 in2, bus2 in3)
{
	out[0] = XOR3_1(in1[0], in2[0], in3[0]);
	out[1] = XOR3_1(in1[1], in2[1], in3[1]);
}
void XOR3_8(bus8 out, bus8 in1, bus8 in2, bus8 in3)
{
	XOR3_2(out, in1, in2, in3);
	XOR3_2(&out[2], &in1[2], &in2[2], &in3[2]);
	XOR3_2(&out[4], &in1[4], &in2[4], &in3[4]);
	XOR3_2(&out[6], &in1[6], &in2[6], &in3[6]);
}
void XOR3_16(bus16 out, bus16 in1, bus16 in2, bus16 in3)
{
	XOR3_8(out, in1, in2, in3);
	XOR3_8(&out[8], &in1[8], &in2[8], &in3[8]);
}
void XOR3_32(bus32 out, bus32 in1, bus32 in2, bus32 in3)
{
	XOR3_16(out, in1, in2, in3);
	XOR3_16(&out[16], &in1[16], &in2[16], &in3[16]);
}
wire XOR4_1(wire in1, wire in2, wire in3, wire in4)
{
	return XOR2_1(XOR3_1(in1, in2, in3), in4);
}
void XOR4_2(bus2 out, bus2 in1, bus2 in2, bus2 in3, bus2 in4)
{
	out[0] = XOR4_1(in1[0], in2[0], in3[0], in4[0]);
	out[1] = XOR4_1(in1[1], in2[1], in3[1], in4[1]);
}
void XOR4_8(bus8 out, bus8 in1, bus8 in2, bus8 in3, bus8 in4)
{
	XOR4_2(out, in1, in2, in3, in4);
	XOR4_2(&out[2], &in1[2], &in2[2], &in3[2], &in4[2]);
	XOR4_2(&out[4], &in1[4], &in2[4], &in3[2], &in4[4]);
	XOR4_2(&out[6], &in1[6], &in2[6], &in3[6], &in4[4]);
}
void XOR4_16(bus16 out, bus16 in1, bus16 in2, bus16 in3, bus16 in4)
{
	XOR4_8(out, in1, in2, in3, in4);
	XOR4_8(&out[8], &in1[8], &in2[8], &in3[8], &in4[8]);
}
void XOR4_32(bus32 out, bus32 in1, bus32 in2, bus32 in3, bus32 in4)
{
	XOR4_16(out, in1, in2, in3, in4);
	XOR4_16(&out[16], &in1[16], &in2[16], &in3[16], &in4[16]);
}
wire XOR6_1(wire in1, wire in2, wire in3, wire in4, wire in5, wire in6)
{
	return XOR2_1(XOR3_1(in1, in2, in3), XOR3_1(in4, in5, in6)); 
}
void XOR6_2(bus2 out, bus2 in1, bus2 in2, bus2 in3, bus2 in4, bus2 in5, bus2 in6)
{
	out[0] = XOR6_1(in1[0], in2[0], in3[0], in4[0], in5[0], in6[0]);
	out[1] = XOR6_1(in1[1], in2[1], in3[1], in4[1], in5[1], in6[1]);
}
void XOR6_8(bus8 out, bus8 in1, bus8 in2, bus8 in3, bus8 in4, bus8 in5, bus8 in6)
{
	XOR6_2(out, in1, in2, in3, in4, in5, in6);
	XOR6_2(&out[2], &in1[2], &in2[2], &in3[2], &in4[2], &in5[2], &in6[2]);
	XOR6_2(&out[4], &in1[4], &in2[4], &in3[4], &in4[4], &in5[4], &in6[4]);
	XOR6_2(&out[6], &in1[6], &in2[6], &in3[6], &in4[6], &in5[6], &in6[6]);
}
void XOR6_16(bus16 out, bus16 in1, bus16 in2, bus16 in3, bus16 in4, bus16 in5, bus16 in6)
{
	XOR6_8(out, in1, in2, in3, in4, in5, in6);
	XOR6_8(&out[8], &in1[8], &in2[8], &in3[8], &in4[8], &in5[8], &in6[8]);
}
void XOR6_32(bus32 out, bus32 in1, bus32 in2, bus32 in3, bus32 in4, bus32 in5, bus32 in6)
{
	XOR6_16(out, in1, in2, in3, in4, in5, in6);
	XOR6_16(&out[16], &in1[16], &in2[16], &in3[16], &in4[16], &in5[16], &in6[16]);
}
wire XOR8_1(wire in1, wire in2, wire in3, wire in4, wire in5, wire in6, wire in7, wire in8)
{
	return XOR2_1(XOR4_1(in1, in2, in3, in4), XOR4_1(in5, in6, in7, in8));
}
void XOR8_2(bus8 out, bus8 in1, bus8 in2, bus8 in3, bus8 in4, bus8 in5, bus8 in6, bus8 in7, bus8 in8)
{
	out[0] = XOR8_1(in1[0], in2[0], in3[0], in4[0], in5[0], in6[0], in7[0], in8[0]);
	out[1] = XOR8_1(in1[1], in2[1], in3[1], in4[1], in5[1], in6[1], in7[1], in8[1]);
}
void XOR8_8(bus8 out, bus8 in1, bus8 in2, bus8 in3, bus8 in4, bus8 in5, bus8 in6, bus8 in7, bus8 in8)
{
	XOR8_2(out, in1, in2, in3, in4, in5, in6, in7, in8);
	XOR8_2(&out[2], &in1[2], &in2[2], &in3[2], &in4[2], &in5[2], &in6[2], &in7[2], &in8[2]);
	XOR8_2(&out[4], &in1[4], &in2[4], &in3[4], &in4[4], &in5[4], &in6[4], &in7[4], &in8[4]);
	XOR8_2(&out[6], &in1[6], &in2[6], &in3[6], &in4[6], &in5[6], &in6[6], &in7[6], &in8[6]);
}
void XOR8_16(bus16 out, bus16 in1, bus16 in2, bus16 in3, bus16 in4, bus16 in5, bus16 in6, bus16 in7, bus16 in8)
{
	XOR8_8(out, in1, in2, in3, in4, in5, in6, in7, in8);
	XOR8_8(&out[8], &in1[8], &in2[8], &in3[8], &in4[8], &in5[8], &in6[8], &in7[8], &in8[8]);
}
void XOR8_32(bus32 out, bus32 in1, bus32 in2, bus32 in3, bus32 in4, bus32 in5, bus32 in6, bus32 in7, bus32 in8)
{
	XOR8_16(out, in1, in2, in3, in4, in5, in6, in7, in8);
	XOR8_16(&out[16], &in1[16], &in2[16], &in3[16], &in4[16], &in5[16], &in6[16], &in7[16], &in8[16]);
}

wire XNOR2_1(wire in1, wire in2)
{
	return NOT_1(XOR2_1(in1, in2));
}
void XNOR2_2(bus2 out, bus2 in1, bus2 in2)
{
	out[0] = XNOR2_1(in1[0], in2[0]);
	out[1] = XNOR2_1(in1[1], in2[1]);
}
void XNOR2_8(bus8 out, bus8 in1, bus8 in2)
{
	XNOR2_2(out, in1, in2);
	XNOR2_2(&out[2], &in1[2], &in2[2]);
	XNOR2_2(&out[4], &in1[4], &in2[4]);
	XNOR2_2(&out[6], &in1[6], &in2[6]);
}
void XNOR2_16(bus16 out, bus16 in1, bus16 in2)
{
	XNOR2_8(out, in1, in2);
	XNOR2_8(&out[8], &in1[8], &in2[8]);
}
void XNOR2_32(bus32 out, bus32 in1, bus32 in2)
{
	XNOR2_16(out, in1, in2);
	XNOR2_16(&out[16], &in1[16], &in2[16]);
}
wire XNOR3_1(wire in1, wire in2, wire in3)
{
	return NOT_1(XOR3_1(in1, in2, in3));
}
void XNOR3_2(bus2 out, bus2 in1, bus2 in2, bus2 in3)
{
	out[0] = XNOR3_1(in1[0], in2[0], in3[0]);
	out[1] = XNOR3_1(in1[1], in2[1], in3[1]);
}
void XNOR3_8(bus8 out, bus8 in1, bus8 in2, bus8 in3)
{
	XNOR3_2(out, in1, in2, in3);
	XNOR3_2(&out[2], &in1[2], &in2[2], &in3[2]);
	XNOR3_2(&out[4], &in1[4], &in2[4], &in3[4]);
	XNOR3_2(&out[6], &in1[6], &in2[6], &in3[6]);
}
void XNOR3_16(bus16 out, bus16 in1, bus16 in2, bus16 in3)
{
	XNOR3_8(out, in1, in2, in3);
	XNOR3_8(&out[8], &in1[8], &in2[8], &in3[8]);
}
void XNOR3_32(bus32 out, bus32 in1, bus32 in2, bus32 in3)
{
	XNOR3_16(out, in1, in2, in3);
	XNOR3_16(&out[16], &in1[16], &in2[16], &in3[16]);
}
wire XNOR4_1(wire in1, wire in2, wire in3, wire in4)
{
	return NOT_1(XOR4_1(in1, in2, in3, in4));
}
void XNOR4_2(bus2 out, bus2 in1, bus2 in2, bus2 in3, bus2 in4)
{
	out[0] = XNOR4_1(in1[0], in2[0], in3[0], in4[0]);
	out[1] = XNOR4_1(in1[1], in2[1], in3[1], in4[1]);
}
void XNOR4_8(bus8 out, bus8 in1, bus8 in2, bus8 in3, bus8 in4)
{
	XNOR4_2(out, in1, in2, in3, in4);
	XNOR4_2(&out[2], &in1[2], &in2[2], &in3[2], &in4[2]);
	XNOR4_2(&out[4], &in1[4], &in2[4], &in3[2], &in4[4]);
	XNOR4_2(&out[6], &in1[6], &in2[6], &in3[6], &in4[4]);
}
void XNOR4_16(bus16 out, bus16 in1, bus16 in2, bus16 in3, bus16 in4)
{
	XNOR4_8(out, in1, in2, in3, in4);
	XNOR4_8(&out[8], &in1[8], &in2[8], &in3[8], &in4[8]);
}
void XNOR4_32(bus32 out, bus32 in1, bus32 in2, bus32 in3, bus32 in4)
{
	XNOR4_16(out, in1, in2, in3, in4);
	XNOR4_16(&out[16], &in1[16], &in2[16], &in3[16], &in4[16]);
}
wire XNOR6_1(wire in1, wire in2, wire in3, wire in4, wire in5, wire in6)
{
	return NOT_1(XOR6_1(in1, in2, in3, in4, in5, in6)); 
}
void XNOR6_2(bus2 out, bus2 in1, bus2 in2, bus2 in3, bus2 in4, bus2 in5, bus2 in6)
{
	out[0] = XNOR6_1(in1[0], in2[0], in3[0], in4[0], in5[0], in6[0]);
	out[1] = XNOR6_1(in1[1], in2[1], in3[1], in4[1], in5[1], in6[1]);
}
void XNOR6_8(bus8 out, bus8 in1, bus8 in2, bus8 in3, bus8 in4, bus8 in5, bus8 in6)
{
	XNOR6_2(out, in1, in2, in3, in4, in5, in6);
	XNOR6_2(&out[2], &in1[2], &in2[2], &in3[2], &in4[2], &in5[2], &in6[2]);
	XNOR6_2(&out[4], &in1[4], &in2[4], &in3[4], &in4[4], &in5[4], &in6[4]);
	XNOR6_2(&out[6], &in1[6], &in2[6], &in3[6], &in4[6], &in5[6], &in6[6]);
}
void XNOR6_16(bus16 out, bus16 in1, bus16 in2, bus16 in3, bus16 in4, bus16 in5, bus16 in6)
{
	XNOR6_8(out, in1, in2, in3, in4, in5, in6);
	XNOR6_8(&out[8], &in1[8], &in2[8], &in3[8], &in4[8], &in5[8], &in6[8]);
}
void XNOR6_32(bus32 out, bus32 in1, bus32 in2, bus32 in3, bus32 in4, bus32 in5, bus32 in6)
{
	XNOR6_16(out, in1, in2, in3, in4, in5, in6);
	XNOR6_16(&out[16], &in1[16], &in2[16], &in3[16], &in4[16], &in5[16], &in6[16]);
}
wire XNOR8_1(wire in1, wire in2, wire in3, wire in4, wire in5, wire in6, wire in7, wire in8)
{
	return XNOR2_1(XNOR4_1(in1, in2, in3, in4), XNOR4_1(in5, in6, in7, in8));
}
void XNOR8_2(bus8 out, bus8 in1, bus8 in2, bus8 in3, bus8 in4, bus8 in5, bus8 in6, bus8 in7, bus8 in8)
{
	out[0] = XNOR8_1(in1[0], in2[0], in3[0], in4[0], in5[0], in6[0], in7[0], in8[0]);
	out[1] = XNOR8_1(in1[1], in2[1], in3[1], in4[1], in5[1], in6[1], in7[1], in8[1]);
}
void XNOR8_8(bus8 out, bus8 in1, bus8 in2, bus8 in3, bus8 in4, bus8 in5, bus8 in6, bus8 in7, bus8 in8)
{
	XNOR8_2(out, in1, in2, in3, in4, in5, in6, in7, in8);
	XNOR8_2(&out[2], &in1[2], &in2[2], &in3[2], &in4[2], &in5[2], &in6[2], &in7[2], &in8[2]);
	XNOR8_2(&out[4], &in1[4], &in2[4], &in3[4], &in4[4], &in5[4], &in6[4], &in7[4], &in8[4]);
	XNOR8_2(&out[6], &in1[6], &in2[6], &in3[6], &in4[6], &in5[6], &in6[6], &in7[6], &in8[6]);
}
void XNOR8_16(bus16 out, bus16 in1, bus16 in2, bus16 in3, bus16 in4, bus16 in5, bus16 in6, bus16 in7, bus16 in8)
{
	XNOR8_8(out, in1, in2, in3, in4, in5, in6, in7, in8);
	XNOR8_8(&out[8], &in1[8], &in2[8], &in3[8], &in4[8], &in5[8], &in6[8], &in7[8], &in8[8]);
}
void XNOR8_32(bus32 out, bus32 in1, bus32 in2, bus32 in3, bus32 in4, bus32 in5, bus32 in6, bus32 in7, bus32 in8)
{
	XNOR8_16(out, in1, in2, in3, in4, in5, in6, in7, in8);
	XNOR8_16(&out[16], &in1[16], &in2[16], &in3[16], &in4[16], &in5[16], &in6[16], &in7[16], &in8[16]);
}

