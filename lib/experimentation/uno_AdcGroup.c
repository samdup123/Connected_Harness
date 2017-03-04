/*
 * uno_AdcGroup Implementation
 *
 * Written by JamApps
 */

#include "Arduino.h"
#include "uno_AdcGroup.h"

static Read(ty_Channel_AdcGroup channel) {
	pinMode(channel, INPUT);
	analogRead(channel);
}

static const ty_i_api_AdcGroup api = { Read };

ty_i_AdcGroup* init_uno_AdcGroup(void)
{
	static ty_i_AdcGroup adc;

	if (adc->api == NULL)
	{
		adc->api = &api;
	}

	return &adc;
}
