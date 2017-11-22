#include <stdio.h>

#include "signal.h"
#include "gate.h"
#include "rcadder.h"
#include "mux.h"
#include "alu.h"

wire ALU(bus32 * out, bus32 in1, bus32 in2, bus3 op)
{
	wire overflow;
	bus32 not_in1, not_in2;
	bus32 add_out;
	bus32 and_out;
	bus32 or_out;
	bus32 sub_out;
	bus32 slt_out;
	bus32 tco_out;
	bus32 ground;

	/* add 010 */
	RCAdder_32(add_out, &overflow, in1, in2, '0');

	/* and 000 */
	AND2_32(and_out, in1, in2);

	/* or 001 */
	OR2_32(or_out, in1, in2);

	/* sub 110 */
	NOT_32(not_in2, in2);
	RCAdder_32(sub_out, &overflow, in1, not_in2, '1');

	/* slt 111 */
	setbus32(slt_out, "00000000000000000000000000000000");
	RCAdder_32(ground, &overflow, sub_out, "11111111111111111111111111111111", '0');	
	slt_out[31] = OR3_1(
		AND2_1(in1[0], NOT_1(in2[0])),											/* -in1, +in2 */
		AND4_1(sub_out[0], NOT_1(in1[0]), NOT_1(in2[0]), overflow),		/* +in1, +in2, in1 != in2 */
		AND4_1(sub_out[0], in1[0], in2[0], overflow)							/* -in1, -in2, in1 != in2 */
		);

	/* tco 011 (two's complement) */
	setbus32(tco_out, "00000000000000000000000000000000");
	NOT_32(not_in1, in1);
	RCAdder_32(tco_out, &overflow, tco_out, not_in1, '1');

	/*            000      001     010      011      100     101     110     111 	*/
	Mux8_32(*out, and_out, or_out, add_out, tco_out, ground, ground, sub_out, slt_out, op);  	
	appendnull(32, *out);

	/* zero signal */
	RCAdder_32(ground, &overflow, *out, "11111111111111111111111111111111", '0');	
	return NOT_1(overflow);
}

void ALUDriver(void)
{
	bus32 a, b, c, d, e, out;
	wire zero;
	setbus32(a, "10101010101010101010101010101010");
	setbus32(b, "01010101010101010101010101010101");
	setbus32(c, "10000001000000000000000000001001");
	setbus32(d, "10000001000000000000000000001001");
	setbus32(e, "11111111111111111111111101101110");

	zero = ALU(&out, a, b, "010");
	printf("    %s\nADD %s\n------------------------------------\n    %s (zero = %c)\n\n", a, b, out, zero);

	zero = ALU(&out, a, b, "000");
	printf("    %s\nAND %s\n------------------------------------\n    %s (zero = %c)\n\n", a, b, out, zero);

	zero = ALU(&out, a, b, "001");
	printf("    %s\nOR  %s\n------------------------------------\n    %s (zero = %c)\n\n", a, b, out, zero);

	zero = ALU(&out, c, d, "110");
	printf("    %s\nSUB %s\n------------------------------------\n    %s (zero = %c)\n\n", c, d, out, zero);

	zero = ALU(&out, a, b, "111");
	printf("    %s\nSLT %s\n------------------------------------\n    %s (zero = %c)\n\n", a, b, out, zero);
	zero = ALU(&out, b, a, "111");
	printf("    %s\nSLT %s\n------------------------------------\n    %s (zero = %c)\n\n", b, a, out, zero);
	zero = ALU(&out, c, a, "111");
	printf("    %s\nSLT %s\n------------------------------------\n    %s (zero = %c)\n\n", c, a, out, zero);
	zero = ALU(&out, c, d, "111");
	printf("    %s\nSLT %s\n------------------------------------\n    %s (zero = %c)\n\n", c, d, out, zero);

	zero = ALU(&out, e, d, "011");
	printf("TCO %s\n------------------------------------\n    %s (two's complement)\n\n", e, out);

}

