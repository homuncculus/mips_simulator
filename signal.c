#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "signal.h"

extern wire AND2_1(wire in1, wire in2);
extern void NOT_16(bus16 out, bus16 in);

void appendnull(int n, busn bus)
{
	bus[n] = '\0';
}

unsigned int busntoint(int n, busn bus)
{
	unsigned int value = 0;
	int i;
	for (i=0; i < n; i++) {
		if (bus[i] == '1') value += (unsigned int)pow(2,(n-1-i));
	}
	return value;
}
unsigned int bus2toint(bus2 bus) 
{
	return busntoint(2, bus);
}
unsigned int bus32toint(bus32 bus) 
{
	return busntoint(32, bus);
}

void bw_extend1_8(bus8 extended, wire orig)
{
	extended[0] = orig;
	extended[1] = orig;
	extended[2] = orig;
	extended[3] = orig;
	extended[4] = orig;
	extended[5] = orig;
	extended[6] = orig;
	extended[7] = orig;
	extended[8] = '\0';
}

void inttobusn(int val, int n, busn bus)
{
	int i;
	unsigned int digit;

	for (i=0; i < n; i++) {
		digit = pow(2, (n-1-i));
		if (digit <= val) {
			val -= digit;
			bus[i] = '1';
		} else {
			bus[i] = '0';
		}	
	}	
	bus[n] = '\0';
}

void setbus8(bus8 dest, bus8 source)
{
	dest[0] = source[0];
	dest[1] = source[1];
	dest[2] = source[2];
	dest[3] = source[3];
	dest[4] = source[4];
	dest[5] = source[5];
	dest[6] = source[6];
	dest[7] = source[7];
	dest[8] = '\0';
}

void setbus16(bus16 dest, bus16 source)
{
	dest[0] = source[0];
	dest[1] = source[1];
	dest[2] = source[2];
	dest[3] = source[3];
	dest[4] = source[4];
	dest[5] = source[5];
	dest[6] = source[6];
	dest[7] = source[7];
	dest[8] = source[8];
	dest[9] = source[9];
	dest[10] = source[10];
	dest[11] = source[11];
	dest[12] = source[12];
	dest[13] = source[13];
	dest[14] = source[14];
	dest[15] = source[15];
	dest[16] = '\0';
}

void setbus32(bus32 dest, bus32 source) 
{
	setbus16(dest, source);
	setbus16(&dest[16], &source[16]);
	dest[32] = '\0';
}

void shiftleft2x(bus32 dest, bus32 source)
{
	dest[0] = source[2];
	dest[1] = source[3];
	dest[2] = source[4];
	dest[3] = source[5];
	dest[4] = source[6];
	dest[5] = source[7];
	dest[6] = source[8];
	dest[7] = source[9];
	dest[8] = source[10];
	dest[9] = source[11];
	dest[10] = source[12];
	dest[11] = source[13];
	dest[12] = source[14];
	dest[13] = source[15];
	dest[14] = source[16];
	dest[15] = source[17];
	dest[16] = source[18];
	dest[17] = source[19];
	dest[18] = source[20];
	dest[19] = source[21];
	dest[20] = source[22];
	dest[21] = source[23];
	dest[22] = source[24];
	dest[23] = source[25];
	dest[24] = source[26];
	dest[25] = source[27];
	dest[26] = source[28];
	dest[27] = source[29];
	dest[28] = source[30];
	dest[29] = source[31];
	dest[30] = '0';
	dest[31] = '0';
	dest[32] = '\0';
}

void signextend(bus32 dest, bus16 source)
{
	dest[0] = AND2_1(source[0], '1');
	dest[1] = AND2_1(source[0], '1');
	dest[2] = AND2_1(source[0], '1');
	dest[3] = AND2_1(source[0], '1');
	dest[4] = AND2_1(source[0], '1');
	dest[5] = AND2_1(source[0], '1');
	dest[6] = AND2_1(source[0], '1');
	dest[7] = AND2_1(source[0], '1');
	dest[8] = AND2_1(source[0], '1');
	dest[9] = AND2_1(source[0], '1');
	dest[10] = AND2_1(source[0], '1');
	dest[11] = AND2_1(source[0], '1');
	dest[12] = AND2_1(source[0], '1');
	dest[13] = AND2_1(source[0], '1');
	dest[14] = AND2_1(source[0], '1');
	dest[15] = AND2_1(source[0], '1');
	dest[16] = source[0];
	dest[17] = source[1];
	dest[18] = source[2];
	dest[19] = source[3];
	dest[20] = source[4];
	dest[21] = source[5];
	dest[22] = source[6];
	dest[23] = source[7];
	dest[24] = source[8];
	dest[25] = source[9];
	dest[26] = source[10];
	dest[27] = source[11];
	dest[28] = source[12];
	dest[29] = source[13];
	dest[30] = source[14];
	dest[31] = source[15];
	dest[32] = '\0';
}

void SignalDriver(void)
{
	bus32 unshifted, shifted, unext1, unext2, ext;

	setbus32(unshifted, "11110000111100001111000011110000");
	shiftleft2x(shifted, unshifted);
	printf("%s << 2 = %s\n\n", unshifted, shifted);		

	setbus32(unext1, "1000000000000001");
	signextend(ext, unext1);
	printf("%s SEXT = %s\n\n", unext1, ext);

	NOT_16(unext2, unext1);
	appendnull(16, unext2);
	signextend(ext, unext2);
	printf("%s SEXT = %s\n\n", unext2, ext);
}

