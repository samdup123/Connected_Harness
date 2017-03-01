/*
 * GpioCommunicator - Interfaces with gpio pins
 *
 * Written by Sam DuPlessis
 */

#ifndef GPIOCOMMUNICATOR
#define GPIOCOMMUNICATOR

typedef struct
{
	struct
	{

	} priv;
} ty_GpioCommunicator;

void init_GpioCommunicator(ty_GpioCommunicator *subject);

#endif
