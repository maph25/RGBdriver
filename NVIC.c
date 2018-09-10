/*
 * NVIC.c
 *
 *  Created on: Sep 10, 2018
 *      Author: Andy
 */

#include "NVIC.h"

void NVIC_enableInterruptAndPriotity(InterruptType interruptNumber, PriorityLevelType priority)
{
	/**This functions are part of CMSIS Core functions*/
	/**It enables the IRQ*/
	NVIC_EnableIRQ(interruptNumber);
	/**It Sets the priority of the IRQ*/
	NVIC_SetPriority(interruptNumber, priority);
}


void NVIC_setBASEPRI_threshold(PriorityLevelType priority)
{
	/**Sets the threshold level to attend interrupts*/
	/**A shift is needed to align in a correct manner the data in priority inside BASEPRI register*/
	__set_BASEPRI(priority << (8 - __NVIC_PRIO_BITS));
}
