#include <math.h>
#include <stdio.h>

#include "signal.h"
#include "regfileaccess.h"

static bus32 regs[32];

void InitializeRegisterFileAccess(void)
{
	bus32 gnd, low;
	setbus32(low, "00000000000000000000000000000000");
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "00000", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "00001", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "00010", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "00011", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "00100", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "00101", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "00110", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "00111", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "01000", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "01001", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "01010", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "01011", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "01100", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "01101", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "01110", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "01111", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "10000", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "10001", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "10010", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "10011", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "10100", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "10101", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "10110", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "10111", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "11000", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "11001", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "11010", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "11011", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "11100", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "11101", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "11110", low, '1');
	RegisterFileAccess(&gnd, &gnd, "00000", "00000", "11111", low, '1');
}

void RegisterFileAccess(bus32 * read_out1, bus32 * read_out2, 
						 		bus5 read_addr1, bus5 read_addr2, 
						 		bus5 write_addr, bus32 write_in, wire reg_write)
{
	setbus32(*read_out1, regs[busntoint(5, read_addr1)]);
	setbus32(*read_out2, regs[busntoint(5, read_addr2)]);
	if (reg_write == '1') setbus32(regs[busntoint(5, write_addr)], write_in);
}

void RegisterFileAccessDriver(void)
{
	bus32 out1, out2;
	
	RegisterFileAccess(&out1, &out2, "00000", "00000", "00000", "00000000000000000000000000000000", '1');
	printf("write_in[0] = %#4.4x\n", 0);
	RegisterFileAccess(&out1, &out2, "00000", "00000", "00001", "00000000000000000000000000000001", '1');
	printf("write_in[1] = %#4.4x\n", 1);
	RegisterFileAccess(&out1, &out2, "00000", "00000", "00010", "00000000000000000000000000000010", '1');
	printf("write_in[2] = %#4.4x\n", 2);
	RegisterFileAccess(&out1, &out2, "00000", "00000", "00011", "00000000000000000000000000000011", '1');
	printf("write_in[3] = %#4.4x\n", 3);

	RegisterFileAccess(&out1, &out2, "00000", "00000", "00000", "00000000000000000000000000000000", '0');
	printf("read_out1[0] = %#4.4x\n", bus32toint(out1));
	RegisterFileAccess(&out1, &out2, "00001", "00001", "00000", "00000000000000000000000000000000", '0');
	printf("read_out1[1] = %#4.4x\n", bus32toint(out1));
	RegisterFileAccess(&out1, &out2, "00000", "00010", "00000", "00000000000000000000000000000000", '0');
	printf("read_out2[2] = %#4.4x\n", bus32toint(out2));
	RegisterFileAccess(&out1, &out2, "00000", "00011", "00000", "00000000000000000000000000000000", '0');
	printf("read_out2[3] = %#4.4x\n\n", bus32toint(out2));

	RegisterFileAccess(&out1, &out2, "00000", "00000", "00000", "00000000000000000000000000000100", '1');
	printf("read_out1[0] = %#4.4x, write_in[0] = %#4.4x\n", bus32toint(out1), 4);
}

