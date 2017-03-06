/*
 * DigitalInput_GpioGroupAdapter Implementation
 *
 * Written by JamApps
 */

#include "DigitalInput_GpioGroupAdapter.h"
#include "utilities.h"

static bool digital_read(void *subj)
{
	REINTERPRET(subject, subj, ty_DigitalInput_GpioGroupAdapter *);
	return Read_GpioGroup(subject->priv.gpioGroup, subject->priv.channel);
}

static const ty_i_api_DigitalInput api =
{
		digital_read
};

void init_DigitalInput_GpioGroupAdapter(
		ty_DigitalInput_GpioGroupAdapter *subject,
		ty_i_GpioGroup *gpioGroup,
		ty_Channel_GpioGroup channel)
{
	subject->priv.gpioGroup = gpioGroup;
	subject->priv.channel = channel;

	subject->interface.api = &api;
}
