/*
 * DigitalInput_GpioGroupAdapter Implementation
 *
 * Written by JamApps
 */

#include "DigitalInput_GpioGroupAdapter.h"
#include "utilities.h"

static bool Read(void *subj)
{
	RECAST(subject, subj, ty_DigitalInput_GpioGroupAdapter *);
	return Read_GpioGroup(subject->priv.gpio, subject->priv.channel);
}

static const ty_i_api_DigitalInput api = { Read };

void init_DigitalInput_GpioGroupAdapter(
		ty_DigitalInput_GpioGroupAdapter *subject,
		ty_i_GpioGroup *gpio,
		ty_Channel_GpioGroup channel)
{
	subject->priv.gpio = gpio;
	subject->priv.channel = channel;

	subject->interface.api = &api;
}
