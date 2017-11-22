#include <stdio.h>

#include "gate.h"
#include "signal.h"

wire RCAdder_1(wire * sum, wire * cout, wire a, wire b, wire cin)
{
	*cout = OR3_1(AND2_1(a, b), AND2_1(a, cin), AND2_1(b, cin));
	*sum = XOR3_1(a, b, cin);
	return *sum;
}
void RCAdder_8(bus8 sum, wire * cout, bus8 a, bus8 b, wire cin)
{
	RCAdder_1(&sum[7], cout, a[7], b[7], cin);
	RCAdder_1(&sum[6], cout, a[6], b[6], *cout);
	RCAdder_1(&sum[5], cout, a[5], b[5], *cout);
	RCAdder_1(&sum[4], cout, a[4], b[4], *cout);
	RCAdder_1(&sum[3], cout, a[3], b[3], *cout);
	RCAdder_1(&sum[2], cout, a[2], b[2], *cout);
	RCAdder_1(&sum[1], cout, a[1], b[1], *cout);
	RCAdder_1(sum, cout, a[0], b[0], *cout);
}
void RCAdder_16(bus16 sum, wire * cout, bus16 a, bus16 b, wire cin)
{
	RCAdder_8(&sum[8], cout, &a[8], &b[8], cin);
	RCAdder_8(sum, cout, a, b, *cout);
}
void RCAdder_32(bus32 sum, wire * cout, bus32 a, bus32 b, wire cin)
{
	RCAdder_16(&sum[16], cout, &a[16], &b[16], cin);
	RCAdder_16(sum, cout, a, b, *cout);
}

void RCAdderDriver(void)
{
	wire sum1, cout1;
	bus32 sum32, a1, a2, b1, b2;
	setbus32(a1, "01010101010101010101010101010101");
	setbus32(b1, "10101010101010101010101010101010");
	setbus32(a2, "00000000000000000000000000000001");
	setbus32(b2, "00000000000000000000000000000001");
	appendnull(32, sum32);

	printf(" a  b cin | sum cout\n--------------------\n");
	RCAdder_1(&sum1, &cout1, '0', '0', '0');
	printf(" 0  0  0  |  %c  %c\n", sum1, cout1);
	RCAdder_1(&sum1, &cout1, '0', '0', '1');
	printf(" 0  0  1  |  %c  %c\n", sum1, cout1);
	RCAdder_1(&sum1, &cout1, '0', '1', '0');
	printf(" 0  1  0  |  %c  %c\n", sum1, cout1);
	RCAdder_1(&sum1, &cout1, '0', '1', '1');
	printf(" 0  1  1  |  %c  %c\n", sum1, cout1);
	RCAdder_1(&sum1, &cout1, '1', '0', '0');
	printf(" 1  0  0  |  %c  %c\n", sum1, cout1);
	RCAdder_1(&sum1, &cout1, '1', '0', '1');
	printf(" 1  0  1  |  %c  %c\n", sum1, cout1);
	RCAdder_1(&sum1, &cout1, '1', '1', '0');
	printf(" 1  1  0  |  %c  %c\n", sum1, cout1);
	RCAdder_1(&sum1, &cout1, '1', '1', '1');
	printf(" 1  1  1  |  %c  %c\n\n", sum1, cout1);

	RCAdder_32(sum32, &cout1, a1, b1, '1');
	printf("                                  1\n");
	printf("   %s\n", a1);
	printf(" + %s\n", b1);
	printf("------------------------------------\n");
	printf("   %s cout = %c\n\n", sum32, cout1);

	cout1 = 0;
	RCAdder_32(sum32, &cout1, a2, b2, '0');
	printf("   %s\n", a2);
	printf(" + %s\n", b2);
	printf("------------------------------------\n");
	printf("   %s cout = %c\n", sum32, cout1);
}

