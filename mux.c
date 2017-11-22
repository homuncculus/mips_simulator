#include <stdio.h>
#include "signal.h"
#include "gate.h"
#include "mux.h"

wire Mux2_1(wire in1, wire in2, wire select)
{
	return OR2_1(AND2_1(in1, NOT_1(select)), AND2_1(in2, select));
}
void Mux2_5(bus5 out, bus5 in1, bus5 in2, wire select)
{
	out[0] = OR2_1(AND2_1(in1[0], NOT_1(select)), AND2_1(in2[0], select));
	out[1] = OR2_1(AND2_1(in1[1], NOT_1(select)), AND2_1(in2[1], select));
	out[2] = OR2_1(AND2_1(in1[2], NOT_1(select)), AND2_1(in2[2], select));
	out[3] = OR2_1(AND2_1(in1[3], NOT_1(select)), AND2_1(in2[3], select));
	out[4] = OR2_1(AND2_1(in1[4], NOT_1(select)), AND2_1(in2[4], select));
}
void Mux2_8(bus8 out, bus8 in1, bus8 in2, wire select)
{
	out[0] = OR2_1(AND2_1(in1[0], NOT_1(select)), AND2_1(in2[0], select));
	out[1] = OR2_1(AND2_1(in1[1], NOT_1(select)), AND2_1(in2[1], select));
	out[2] = OR2_1(AND2_1(in1[2], NOT_1(select)), AND2_1(in2[2], select));
	out[3] = OR2_1(AND2_1(in1[3], NOT_1(select)), AND2_1(in2[3], select));
	out[4] = OR2_1(AND2_1(in1[4], NOT_1(select)), AND2_1(in2[4], select));
	out[5] = OR2_1(AND2_1(in1[5], NOT_1(select)), AND2_1(in2[5], select));
	out[6] = OR2_1(AND2_1(in1[6], NOT_1(select)), AND2_1(in2[6], select));
	out[7] = OR2_1(AND2_1(in1[7], NOT_1(select)), AND2_1(in2[7], select));
}
void Mux2_16(bus16 out, bus16 in1, bus16 in2, wire select)
{
	Mux2_8(out, in1, in2, select);
	Mux2_8(&out[8], &in1[8], &in2[8], select);
}
void Mux2_32(bus32 out, bus32 in1, bus32 in2, wire select)
{
	Mux2_16(out, in1, in2, select);
	Mux2_16(&out[16], &in1[16], &in2[16], select);
}

wire Mux4_1(wire in1, wire in2, wire in3, wire in4, bus2 select)
{
	return Mux2_1(Mux2_1(in1, in2, select[1]), Mux2_1(in3, in4, select[1]), select[0]);
}
void Mux4_8(bus8 out, bus8 in1, bus8 in2, bus8 in3, bus8 in4, bus2 select)
{
	out[0] = Mux4_1(in1[0], in2[0], in3[0], in4[0], select);
	out[1] = Mux4_1(in1[1], in2[1], in3[1], in4[1], select);
	out[2] = Mux4_1(in1[2], in2[2], in3[2], in4[2], select);
	out[3] = Mux4_1(in1[3], in2[3], in3[3], in4[3], select);
	out[4] = Mux4_1(in1[4], in2[4], in3[4], in4[4], select);
	out[5] = Mux4_1(in1[5], in2[5], in3[5], in4[5], select);
	out[6] = Mux4_1(in1[6], in2[6], in3[6], in4[6], select);
	out[7] = Mux4_1(in1[7], in2[7], in3[7], in4[7], select);
}
void Mux4_16(bus16 out, bus16 in1, bus16 in2, bus16 in3, bus16 in4, bus2 select)
{
	Mux4_8(out, in1, in2, in3, in4, select);
	Mux4_8(&out[8], &in1[8], &in2[8], &in3[8], &in4[8], select);
}
void Mux4_32(bus32 out, bus32 in1, bus32 in2, bus32 in3, bus32 in4, bus2 select)
{
	Mux4_16(out, in1, in2, in3, in4, select);
	Mux4_16(&out[16], &in1[16], &in2[16], &in3[16], &in4[16], select);
}

wire Mux8_1(wire in1, wire in2, wire in3, wire in4, wire in5, wire in6, wire in7, wire in8, bus3 select)
{
	return Mux2_1(Mux4_1(in1, in2, in3, in4, &select[1]), Mux4_1(in5, in6, in7, in8, &select[1]), select[0]);
}
void Mux8_8(bus8 out, bus8 in1, bus8 in2, bus8 in3, bus8 in4, bus8 in5, bus8 in6, bus8 in7, bus8 in8, bus3 select)
{
	out[0] = Mux8_1(in1[0], in2[0], in3[0], in4[0], in5[0], in6[0], in7[0], in8[0], select);
	out[1] = Mux8_1(in1[1], in2[1], in3[1], in4[1], in5[1], in6[1], in7[1], in8[1], select);
	out[2] = Mux8_1(in1[2], in2[2], in3[2], in4[2], in5[2], in6[2], in7[2], in8[2], select);
	out[3] = Mux8_1(in1[3], in2[3], in3[3], in4[3], in5[3], in6[3], in7[3], in8[3], select);
	out[4] = Mux8_1(in1[4], in2[4], in3[4], in4[4], in5[4], in6[4], in7[4], in8[4], select);
	out[5] = Mux8_1(in1[5], in2[5], in3[5], in4[5], in5[5], in6[5], in7[5], in8[5], select);
	out[6] = Mux8_1(in1[6], in2[6], in3[6], in4[6], in5[6], in6[6], in7[6], in8[6], select);
	out[7] = Mux8_1(in1[7], in2[7], in3[7], in4[7], in5[7], in6[7], in7[7], in8[7], select);
}
void Mux8_16(bus16 out, bus16 in1, bus16 in2, bus16 in3, bus16 in4, bus16 in5, bus16 in6, bus16 in7, bus16 in8, bus3 select)
{
	Mux8_8(out, in1, in2, in3, in4, in5, in6, in7, in8, select);
	Mux8_8(&out[8], &in1[8], &in2[8], &in3[8], &in4[8], &in5[8], &in6[8], &in7[8], &in8[8], select);
}
void Mux8_32(bus32 out, bus32 in1, bus32 in2, bus32 in3, bus32 in4, bus32 in5, bus32 in6, bus32 in7, bus32 in8, bus3 select)
{
	Mux8_16(out, in1, in2, in3, in4, in5, in6, in7, in8, select);
	Mux8_16(&out[16], &in1[16], &in2[16], &in3[16], &in4[16], &in5[16], &in6[16], &in7[16], &in8[16], select);
}

void MuxDriver(void)
{
	bus32 in1, in2, in3, in4, in5, in6, in7, in8, out;

	setbus32(in1, "00000000000000000000000000000001");
	setbus32(in2, "00000000000000000000000000010000");
	setbus32(in3, "00000000000000000000000100000000");
	setbus32(in4, "00000000000000000001000000000000");
	setbus32(in5, "00000000000000010000000000000000");
	setbus32(in6, "00000000000100000000000000000000");
	setbus32(in7, "00000001000000000000000000000000");
	setbus32(in8, "00010000000000000000000000000000");

	printf("      __      \n");
	printf(" 1 --|0 |     \n");
	printf(" 0 --|1 |-- %c\n", Mux2_1('1','0','0'));
	printf("     |__|     \n");
	printf("      |       \n");
	printf("      0       \n");

	printf("      __      \n");
	printf(" 1 --|0 |     \n");
	printf(" 0 --|1 |-- %c\n", Mux2_1('1','0','1'));
	printf("     |__|     \n");
	printf("      |       \n");
	printf("      1       \n");

	printf("      __      \n");
	printf(" 0 --|0 |     \n");
	printf(" 1 --|1 |     \n");
	printf(" 0 --|2 |-- %c\n", Mux4_1('0','1','0','1',"00"));
	printf(" 1 --|3 |     \n");
	printf("     |__|     \n");
	printf("      |       \n");
	printf("      0       \n");

	printf("      __      \n");
	printf(" 0 --|0 |     \n");
	printf(" 1 --|1 |     \n");
	printf(" 0 --|2 |-- %c\n", Mux4_1('0','1','0','1',"01"));
	printf(" 1 --|3 |     \n");
	printf("     |__|     \n");
	printf("      |       \n");
	printf("      1       \n");

	printf("      __      \n");
	printf(" 0 --|0 |     \n");
	printf(" 1 --|1 |     \n");
	printf(" 0 --|2 |-- %c\n", Mux4_1('0','1','0','1',"10"));
	printf(" 1 --|3 |     \n");
	printf("     |__|     \n");
	printf("      |       \n");
	printf("      2       \n");

	printf("      __      \n");
	printf(" 0 --|0 |     \n");
	printf(" 1 --|1 |     \n");
	printf(" 0 --|2 |-- %c\n", Mux4_1('0','1','0','1',"11"));
	printf(" 1 --|3 |     \n");
	printf("     |__|     \n");
	printf("      |       \n");
	printf("      3       \n");

	printf("      __      \n");
	printf(" 0 --|0 |     \n");
	printf(" 1 --|1 |     \n");
	printf(" 0 --|2 |     \n");
	printf(" 1 --|3 |     \n");
	printf(" 0 --|4 |-- %c\n", Mux8_1('0','1','0','1','0','1','0','1',"000"));
	printf(" 1 --|5 |     \n");
	printf(" 0 --|6 |     \n");
	printf(" 1 --|7 |     \n");
	printf("     |__|     \n");
	printf("      |       \n");
	printf("      0       \n");

	printf("      __      \n");
	printf(" 0 --|0 |     \n");
	printf(" 1 --|1 |     \n");
	printf(" 0 --|2 |     \n");
	printf(" 1 --|3 |     \n");
	printf(" 0 --|4 |-- %c\n", Mux8_1('0','1','0','1','0','1','0','1',"001"));
	printf(" 1 --|5 |     \n");
	printf(" 0 --|6 |     \n");
	printf(" 1 --|7 |     \n");
	printf("     |__|     \n");
	printf("      |       \n");
	printf("      1       \n");

	printf("      __      \n");
	printf(" 0 --|0 |     \n");
	printf(" 1 --|1 |     \n");
	printf(" 0 --|2 |     \n");
	printf(" 1 --|3 |     \n");
	printf(" 0 --|4 |-- %c\n", Mux8_1('0','1','0','1','0','1','0','1',"010"));
	printf(" 1 --|5 |     \n");
	printf(" 0 --|6 |     \n");
	printf(" 1 --|7 |     \n");
	printf("     |__|     \n");
	printf("      |       \n");
	printf("      2       \n");

	printf("      __      \n");
	printf(" 0 --|0 |     \n");
	printf(" 1 --|1 |     \n");
	printf(" 0 --|2 |     \n");
	printf(" 1 --|3 |     \n");
	printf(" 0 --|4 |-- %c\n", Mux8_1('0','1','0','1','0','1','0','1',"011"));
	printf(" 1 --|5 |     \n");
	printf(" 0 --|6 |     \n");
	printf(" 1 --|7 |     \n");
	printf("     |__|     \n");
	printf("      |       \n");
	printf("      3       \n");

	printf("      __      \n");
	printf(" 0 --|0 |     \n");
	printf(" 1 --|1 |     \n");
	printf(" 0 --|2 |     \n");
	printf(" 1 --|3 |     \n");
	printf(" 0 --|4 |-- %c\n", Mux8_1('0','1','0','1','0','1','0','1',"100"));
	printf(" 1 --|5 |     \n");
	printf(" 0 --|6 |     \n");
	printf(" 1 --|7 |     \n");
	printf("     |__|     \n");
	printf("      |       \n");
	printf("      4       \n");

	printf("      __      \n");
	printf(" 0 --|0 |     \n");
	printf(" 1 --|1 |     \n");
	printf(" 0 --|2 |     \n");
	printf(" 1 --|3 |     \n");
	printf(" 0 --|4 |-- %c\n", Mux8_1('0','1','0','1','0','1','0','1',"101"));
	printf(" 1 --|5 |     \n");
	printf(" 0 --|6 |     \n");
	printf(" 1 --|7 |     \n");
	printf("     |__|     \n");
	printf("      |       \n");
	printf("      5       \n");

	printf("      __      \n");
	printf(" 0 --|0 |     \n");
	printf(" 1 --|1 |     \n");
	printf(" 0 --|2 |     \n");
	printf(" 1 --|3 |     \n");
	printf(" 0 --|4 |-- %c\n", Mux8_1('0','1','0','1','0','1','0','1',"110"));
	printf(" 1 --|5 |     \n");
	printf(" 0 --|6 |     \n");
	printf(" 1 --|7 |     \n");
	printf("     |__|     \n");
	printf("      |       \n");
	printf("      6       \n");

	printf("      __      \n");
	printf(" 0 --|0 |     \n");
	printf(" 1 --|1 |     \n");
	printf(" 0 --|2 |     \n");
	printf(" 1 --|3 |     \n");
	printf(" 0 --|4 |-- %c\n", Mux8_1('0','1','0','1','0','1','0','1',"111"));
	printf(" 1 --|5 |     \n");
	printf(" 0 --|6 |     \n");
	printf(" 1 --|7 |     \n");
	printf("     |__|     \n");
	printf("      |       \n");
	printf("      7       \n");

	Mux2_32(out, in1, in2, '0'); out[2] = '\0';
	printf("               __      \n");
	printf(" 0x00000001 --|0 |     \n");
	printf(" 0x00000010 --|1 |-- %#8.8x\n", busntoint(32, out));
	printf("              |__|     \n");
	printf("               |       \n");
	printf("               0       \n");

	Mux2_32(out, in1, in2, '1'); out[2] = '\0';
	printf("               __      \n");
	printf(" 0x00000001 --|0 |     \n");
	printf(" 0x00000010 --|1 |-- %#8.8x\n", busntoint(32, out));
	printf("              |__|     \n");
	printf("               |       \n");
	printf("               1       \n");

	Mux4_32(out, in1, in2, in3, in4, "00"); out[32] = '\0';
	printf("               __      \n");
	printf(" 0x00000001 --|0 |     \n");
	printf(" 0x00000010 --|1 |     \n");
	printf(" 0x00000100 --|2 |-- %#8.8x\n", busntoint(32, out));
	printf(" 0x00001000 --|3 |     \n");
	printf("              |__|     \n");
	printf("               |       \n");
	printf("               0       \n");

	Mux4_32(out, in1, in2, in3, in4, "01"); out[32] = '\0';
	printf("               __      \n");
	printf(" 0x00000001 --|0 |     \n");
	printf(" 0x00000010 --|1 |     \n");
	printf(" 0x00000100 --|2 |-- %#8.8x\n", busntoint(32, out));
	printf(" 0x00001000 --|3 |     \n");
	printf("              |__|     \n");
	printf("               |       \n");
	printf("               1       \n");

	Mux4_32(out, in1, in2, in3, in4, "10"); out[32] = '\0';
	printf("               __      \n");
	printf(" 0x00000001 --|0 |     \n");
	printf(" 0x00000010 --|1 |     \n");
	printf(" 0x00000100 --|2 |-- %#8.8x\n", busntoint(32, out));
	printf(" 0x00001000 --|3 |     \n");
	printf("              |__|     \n");
	printf("               |       \n");
	printf("               2       \n");

	Mux4_32(out, in1, in2, in3, in4, "11"); out[32] = '\0';
	printf("               __      \n");
	printf(" 0x00000001 --|0 |     \n");
	printf(" 0x00000010 --|1 |     \n");
	printf(" 0x00000100 --|2 |-- %#8.8x\n", busntoint(32, out));
	printf(" 0x00001000 --|3 |     \n");
	printf("              |__|     \n");
	printf("               |       \n");
	printf("               3       \n");

	Mux8_32(out, in1, in2, in3, in4, in5, in6, in7, in8, "000"); out[32] = '\0';
	printf("               __      \n");
	printf(" 0x00000001 --|0 |     \n");
	printf(" 0x00000010 --|1 |     \n");
	printf(" 0x00000100 --|2 |     \n");
	printf(" 0x00001000 --|3 |     \n");
	printf(" 0x00010000 --|4 |-- %#8.8x\n", busntoint(32, out));
	printf(" 0x00100000 --|5 |     \n");
	printf(" 0x01000000 --|6 |     \n");
	printf(" 0x10000000 --|7 |     \n");
	printf("              |__|     \n");
	printf("               |       \n");
	printf("               0       \n");

	Mux8_32(out, in1, in2, in3, in4, in5, in6, in7, in8, "001"); out[32] = '\0';
	printf("               __      \n");
	printf(" 0x00000001 --|0 |     \n");
	printf(" 0x00000010 --|1 |     \n");
	printf(" 0x00000100 --|2 |     \n");
	printf(" 0x00001000 --|3 |     \n");
	printf(" 0x00010000 --|4 |-- %#8.8x\n", busntoint(32, out));
	printf(" 0x00100000 --|5 |     \n");
	printf(" 0x01000000 --|6 |     \n");
	printf(" 0x10000000 --|7 |     \n");
	printf("              |__|     \n");
	printf("               |       \n");
	printf("               1       \n");

	Mux8_32(out, in1, in2, in3, in4, in5, in6, in7, in8, "010"); out[32] = '\0';
	printf("               __      \n");
	printf(" 0x00000001 --|0 |     \n");
	printf(" 0x00000010 --|1 |     \n");
	printf(" 0x00000100 --|2 |     \n");
	printf(" 0x00001000 --|3 |     \n");
	printf(" 0x00010000 --|4 |-- %#8.8x\n", busntoint(32, out));
	printf(" 0x00100000 --|5 |     \n");
	printf(" 0x01000000 --|6 |     \n");
	printf(" 0x10000000 --|7 |     \n");
	printf("              |__|     \n");
	printf("               |       \n");
	printf("               2       \n");


	Mux8_32(out, in1, in2, in3, in4, in5, in6, in7, in8, "011"); out[32] = '\0';
	printf("               __      \n");
	printf(" 0x00000001 --|0 |     \n");
	printf(" 0x00000010 --|1 |     \n");
	printf(" 0x00000100 --|2 |     \n");
	printf(" 0x00001000 --|3 |     \n");
	printf(" 0x00010000 --|4 |-- %#8.8x\n", busntoint(32, out));
	printf(" 0x00100000 --|5 |     \n");
	printf(" 0x01000000 --|6 |     \n");
	printf(" 0x10000000 --|7 |     \n");
	printf("              |__|     \n");
	printf("               |       \n");
	printf("               3       \n");

	Mux8_32(out, in1, in2, in3, in4, in5, in6, in7, in8, "100"); out[32] = '\0';
	printf("               __      \n");
	printf(" 0x00000001 --|0 |     \n");
	printf(" 0x00000010 --|1 |     \n");
	printf(" 0x00000100 --|2 |     \n");
	printf(" 0x00001000 --|3 |     \n");
	printf(" 0x00010000 --|4 |-- %#8.8x\n", busntoint(32, out));
	printf(" 0x00100000 --|5 |     \n");
	printf(" 0x01000000 --|6 |     \n");
	printf(" 0x10000000 --|7 |     \n");
	printf("              |__|     \n");
	printf("               |       \n");
	printf("               4       \n");

	Mux8_32(out, in1, in2, in3, in4, in5, in6, in7, in8, "101"); out[32] = '\0';
	printf("               __      \n");
	printf(" 0x00000001 --|0 |     \n");
	printf(" 0x00000010 --|1 |     \n");
	printf(" 0x00000100 --|2 |     \n");
	printf(" 0x00001000 --|3 |     \n");
	printf(" 0x00010000 --|4 |-- %#8.8x\n", busntoint(32, out));
	printf(" 0x00100000 --|5 |     \n");
	printf(" 0x01000000 --|6 |     \n");
	printf(" 0x10000000 --|7 |     \n");
	printf("              |__|     \n");
	printf("               |       \n");
	printf("               5       \n");

	Mux8_32(out, in1, in2, in3, in4, in5, in6, in7, in8, "110"); out[32] = '\0';
	printf("               __      \n");
	printf(" 0x00000001 --|0 |     \n");
	printf(" 0x00000010 --|1 |     \n");
	printf(" 0x00000100 --|2 |     \n");
	printf(" 0x00001000 --|3 |     \n");
	printf(" 0x00010000 --|4 |-- %#8.8x\n", busntoint(32, out));
	printf(" 0x00100000 --|5 |     \n");
	printf(" 0x01000000 --|6 |     \n");
	printf(" 0x10000000 --|7 |     \n");
	printf("              |__|     \n");
	printf("               |       \n");
	printf("               6       \n");

	Mux8_32(out, in1, in2, in3, in4, in5, in6, in7, in8, "111"); out[32] = '\0';
	printf("               __      \n");
	printf(" 0x00000001 --|0 |     \n");
	printf(" 0x00000010 --|1 |     \n");
	printf(" 0x00000100 --|2 |     \n");
	printf(" 0x00001000 --|3 |     \n");
	printf(" 0x00010000 --|4 |-- %#8.8x\n", busntoint(32, out));
	printf(" 0x00100000 --|5 |     \n");
	printf(" 0x01000000 --|6 |     \n");
	printf(" 0x10000000 --|7 |     \n");
	printf("              |__|     \n");
	printf("               |       \n");
	printf("               7       \n");

}
