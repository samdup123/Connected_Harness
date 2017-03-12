/*
 * DigitalOutput_GpioGroupAdapter Implementation
 *
 * Written by JamApps
 */

#include "DigitalOutput_GpioGroupAdapter.h"
#include "utilities.h"

static void Write(void *subj, bool state)
{
	RECAST(subject, subj, ty_DigitalOutput_GpioGroupAdapter *);
	Write_GpioGroup(subject->priv.gpio, subject->priv.channel, state);
}

static const ty_i_api_DigitalOutput api =
{
		Write
};

void init_DigitalOutput_GpioGroupAdapter(
		ty_DigitalOutput_GpioGroupAdapter *subject,
		ty_i_GpioGroup *gpioGroup,
		ty_Channel_GpioGroup channel)
{
	subject->priv.gpio = gpioGroup;
	subject->priv.channel = channel;

	subject->interface.api = &api;
}
