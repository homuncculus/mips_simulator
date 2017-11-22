#ifndef __REGFILEACCESS_H__
#define __REGFILEACCESS_H__

void InitializeRegisterFileAccess(void);

void RegisterFileAccess(bus32 * read_out1, bus32 * read_out2, 
						 		bus5 read_addr1, bus5 read_addr2, 
								bus5 write_addr, bus32 write_in, wire reg_write);

void RegisterFileAccessDriver(void);

#endif

