/*
 * DigitalInput_GpioGroupAdapter Header File
 *
 * Description Makes a single input for a channel from a GpioGroup
 *
 * Written by JamApps
 */

#ifndef DigitalInput_GpioGroupAdapter
#define DigitalInput_GpioGroupAdapter

#include "i_DigitalInput.h"
#include "i_GpioGroup.h"


typedef struct
{
	ty_i_DigitalInput interface;

	struct
	{
		ty_i_GpioGroup *gpioGroup;
		ty_Channel_GpioGroup channel;
	} priv;
} ty_DigitalInput_GpioGroupAdapter;

void init_DigitalInput_GpioGroupAdapter(
		ty_DigitalInput_GpioGroupAdapter *subject,
		ty_i_GpioGroup *gpioGroup,
		ty_Channel_GpioGroup channel);

#endif
