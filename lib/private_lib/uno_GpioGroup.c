/*
 * uno_GpioGroup Implementation
 *
 * Written by JamApps
 */

#include "uno_GpioGroup.h"
#include "UniversalConstants.h"
#include "Arduino.h"

bool Read(void *subj, ty_Channel_GpioGroup channel) {
	pinMode(channel, INPUT);
	return digitalRead(channel);
}

bool ReadPullup(void *subj, ty_Channel_GpioGroup channel) {
	pinMode(channel, INPUT_PULLUP);
	return digitalRead(channel);
}

void Write(void *subj, ty_Channel_GpioGroup channel, const bool state) {
	pinMode(channel, OUTPUT);
	digitalWrite(channel, state);
}

static const ty_i_api_GpioGroup api = { Read, ReadPullup, Write };

ty_i_GpioGroup* init_uno_GpioGroup(void) {
	static ty_i_GpioGroup gpioGroup;

	if (gpioGroup.api == NULL) {
		gpioGroup.api = &api;
	}

	return &gpioGroup;
}
