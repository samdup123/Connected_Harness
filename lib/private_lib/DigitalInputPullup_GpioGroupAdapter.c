/*
 * DigitalInputPullup_GpioGroupAdapter Implementation
 *
 * Written by JamApps
 */

#include "DigitalInputPullup_GpioGroupAdapter.h"

#include "DigitalInputPullup_GpioGroupAdapter.h"
#include "utilities.h"

static bool digital_read(void *subj)
{
	REINTERPRET(subject, subj, ty_DigitalInputPullup_GpioGroupAdapter *);
	return Read_GpioGroup(subject->priv.gpioGroup, subject->priv.channel);
}

static const ty_i_api_DigitalInputPullup api =
{
		digital_read
};

void init_DigitalInputPullup_GpioGroupAdapter(
		ty_DigitalInputPullup_GpioGroupAdapter *subject,
		ty_i_GpioGroup *gpioGroup,
		ty_Channel_GpioGroup channel)
{
	subject->priv.gpioGroup = gpioGroup;
	subject->priv.channel = channel;

	subject->interface.api = &api;
}
