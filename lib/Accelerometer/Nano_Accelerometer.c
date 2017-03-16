/*
 * Nano_Accelerometer implementation
 *
 *
 * Written by JamApps
 */

#include "Nano_Accelerometer.h"
#include "utilities.h"

static bool HasFallen(void *subj) {
	RECAST(subject, subj, ty_Nano_Accelerometer *);
	if (!subject->priv.hasReported && Read_DigitalInput(subject->priv.input)) {
		subject->priv.hasReported = ON;
		Write_DigitalOutput(subject->priv.output, ON);
		return true;
	} else {
		return false;
	}
}

static void Reset(void *subj) {
	RECAST(subject, subj, ty_Nano_Accelerometer *);
	subject->priv.hasReported = OFF;
	Write_DigitalOutput(subject->priv.output, OFF);
}

static const ty_i_api_Accelerometer api = { HasFallen, Reset };

void init_Nano_Accelerometer(ty_Nano_Accelerometer *subject,
		ty_i_DigitalOutput *output, ty_i_DigitalInput *input) {
	subject->priv.input = input;
	subject->priv.output = output;

	subject->interface.api = &api;
}
