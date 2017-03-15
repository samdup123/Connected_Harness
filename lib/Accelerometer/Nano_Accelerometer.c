/*
 * Nano_Accelerometer implementation
 *
 *
 * Written by JamApps
 */

#include "Nano_Accelerometer.h"
#include "utilities.h"
#include <stdio.h>

static bool HasFallen(void *subj)
{
	RECAST(subject, subj, ty_Nano_Accelerometer *);
	if (subject->priv.hasFallen)
	{
		Write_DigitalOutput(subject->priv.output, OFF);
		subject->priv.hasFallen = false;
		return false;
	}
	else if( Read_DigitalInput(subject->priv.input) )
	{
		Write_DigitalOutput(subject->priv.output, ON);
		subject->priv.hasFallen = true;
		return true;
	}
	return false;
}

static const ty_i_api_Accelerometer api = { HasFallen };

void init_Nano_Accelerometer(
		ty_Nano_Accelerometer *subject,
		ty_i_DigitalOutput *output,
		ty_i_DigitalInput *input)
{
	subject->priv.input = input;
	subject->priv.output = output;

	subject->interface.api = &api;
}
