#ifndef __MEMORY_H__
#define __MEMORY_H__

void MemoryAccess(bus32 read_out, bus32 addr, bus32 write_in, wire write_enable, bus8 memory[4096]);
void MemoryAccessDriver(void);

#endif

