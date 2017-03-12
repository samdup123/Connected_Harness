/*
 * double_GpioGroup Implementation
 *
 * Written by JamApps
 */

#include "d_GpioGroup.h"
#include "utilities.h"

bool Read(void *subj, ty_Channel_GpioGroup channel)
{
	RECAST(subject, subj, ty_double_GpioGroup *);
	return subject->priv.channels[channel];
}

bool Read_InputPullUp(void *subj, ty_Channel_GpioGroup channel)
{
	//todo
	return false;
}

void Write(void *subj, ty_Channel_GpioGroup channel, const bool state)
{
	RECAST(subject, subj, ty_double_GpioGroup *);
	subject->priv.channels[channel] = state;
}

static const ty_i_api_GpioGroup api =
{
		Read, Read_InputPullUp, Write
};

void init_double_GpioGroup(
		ty_double_GpioGroup *subject,
		bool *channels)
{
	subject->priv.channels = channels;
	subject->interface.api = &api;
}
