#include <math.h>
#include <stdio.h>

#include "signal.h"

void MemoryAccess(bus32 read_out, bus32 addr, bus32 write_in, wire write_enable, bus8 memory[4096])
{
	int intaddr = busntoint(12, &addr[20]);
	setbus8(read_out, memory[intaddr]);
	setbus8(&read_out[8], memory[intaddr+1]);
	setbus8(&read_out[16], memory[intaddr+2]);
	setbus8(&read_out[24], memory[intaddr+3]);
	if (write_enable == '1') {
		setbus8(memory[intaddr], write_in);
		setbus8(memory[intaddr+1], &write_in[8]);
		setbus8(memory[intaddr+2], &write_in[16]);
		setbus8(memory[intaddr+3], &write_in[24]);
	}
}

void MemoryAccessDriver(void)
{
	bus8 mem[4096];
	bus32 addr1, addr2, addr3, val1, val2, out;

	setbus32(addr1, "0000000000000000000000000000000");
	setbus32(addr2, "0000000000000000000000010000000");
	setbus32(addr3, "0000000000000000000100000000000");
	setbus32(val1, "1000001000000000000000100100011");
	setbus32(val2, "0000000000010001000100000000001");

	MemoryAccess(out, addr1, val1, '1', mem);
	MemoryAccess(out, addr1, val1, '0', mem);
	printf("M[%d] <- %d\n", bus32toint(addr1), bus32toint(val1));
	printf("M[%d] -> %d\n", bus32toint(addr1), bus32toint(val1));

	MemoryAccess(out, addr2, val2, '1', mem);
	MemoryAccess(out, addr2, val2, '0', mem);
	printf("M[%d] <- %d\n", bus32toint(addr2), bus32toint(val2));
	printf("M[%d] -> %d\n", bus32toint(addr2), bus32toint(val2));

	MemoryAccess(out, addr1, val1, '1', mem);
	MemoryAccess(out, addr1, val1, '0', mem);
	printf("M[%d] <- %d\n", bus32toint(addr3), bus32toint(val1));
	printf("M[%d] -> %d\n", bus32toint(addr3), bus32toint(val1));
}

