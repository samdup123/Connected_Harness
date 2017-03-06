/*
 * DigitalInputPullup_GpioGroupAdapter Header File
 *
 * Description makes one input from a certain channel of a gpiogroup
 *
 * Written by JamApps
 */

#ifndef DigitalInputPullup_GpioGroupAdapter
#define DigitalInputPullup_GpioGroupAdapter

#include "i_DigitalInputPullup.h"
#include "i_GpioGroup.h"

typedef struct
{
	ty_i_DigitalInputPullup interface;

	struct
	{
		ty_i_GpioGroup *gpioGroup;
		ty_Channel_GpioGroup channel;
	} priv;
} ty_DigitalInputPullup_GpioGroupAdapter;

void init_DigitalInputPullup_GpioGroupAdapter(
		ty_DigitalInputPullup_GpioGroupAdapter *subject,
		ty_i_GpioGroup *gpioGroup,
		ty_Channel_GpioGroup channel);

#endif
