#ifndef __SIGNAL_H__
#define __SIGNAL_H__

typedef char wire;
typedef char bus2[3];
typedef char bus3[4];
typedef char bus5[6];
typedef char bus6[7];
typedef char bus8[9];
typedef char bus16[17];
typedef char bus32[33];

typedef char * busn;

void appendnull(int n, busn bus);
unsigned int busntoint(int n, busn bus);
unsigned int bus2toint(bus2 bus);
unsigned int bus32toint(bus32 bus);
void bw_extend1_8(bus8 extended, wire orig);
void inttobusn(int val, int n, busn bus);
void setbus8(bus8 dest, bus8 source);
void setbus16(bus16 dest, bus16 source);
void setbus32(bus32 dest, bus32 source);
void shiftleft2x(bus32 dest, bus32 source);
void signextend(bus32 dest, bus16 source);

void SignalDriver(void);

#endif

