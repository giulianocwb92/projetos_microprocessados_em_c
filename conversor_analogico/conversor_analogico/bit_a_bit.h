#ifndef BIT_A_BIT_H_
#define BIT_A_BIT_H_

#define setbit(porta, b)		porta |= (1 << b)
#define clrbit(porta, b)		porta &= ~(1 << b)
#define getbit(porta, b)		((porta>>b) & 1)

#endif