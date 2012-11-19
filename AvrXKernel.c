/*
 	AvrXKernel.c

 	This file defines the primary AvrX data structures in C
 	so the Avr-gcc debuggers can examine, trace and modify kernel
 	data.

 	Small, inconsequential, AvrX kernel routines are also included
 	here for fun.
 */

#include "avrx.h"

struct AvrXKernelData AvrXKernelData;
pTimerControlBlock _TimerQueue;
unsigned char _TimQLevel;

/*
 AvrXHalt() is included here since it is the end point of error
 catching in the kernel, so I thought it would be nice if the break-
 point was in some thing recognizable by the debugger.
*/
void AvrXHalt(void)
{
	asm ("cli\r");
	while(1);
}

#if 0
// These routines still supplied by assembly code although these
// versions are no bigger than the original ones.
// These routines are not intended to be called from interrupt handlers.
unsigned char AvrXChangePriority(pProcessID p, unsigned char priority)
{
	unsigned char t = p->priority;
	p->priority = priority;
	return t;
}

pProcessID AvrXSelf(void)
{
	return AvrXKernelData.RunQueue;
}

unsigned char AvrXPriority(pProcessID p)
{
	return p->priority;
}
#endif
