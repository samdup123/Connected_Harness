/*
 * DigitalOutput_GpioGroupAdapter Header File
 *
 * Description Creats a digital output for a pin in a GpioGroup
 *
 * Written by JamApps
 */

#ifndef DigitalOutput_GpioGroupAdapter
#define DigitalOutput_GpioGroupAdapter

#include "i_DigitalOutput.h"
#include "i_GpioGroup.h"

typedef struct
{
	ty_i_DigitalOutput interface;

	struct
	{
		ty_i_GpioGroup *gpio;
		ty_Channel_GpioGroup channel;
	} priv;
} ty_DigitalOutput_GpioGroupAdapter;

void init_DigitalOutput_GpioGroupAdapter(
		ty_DigitalOutput_GpioGroupAdapter *subject,
		ty_i_GpioGroup *gpioGroup,
		ty_Channel_GpioGroup channel);

#endif
