/*
 * Application implementation
 *
 *
 * Written by JamApps
 */

#include "Application.h"
#include "UniversalConstantsUno.h"

void init_Application(ty_Application *subject, ty_i_GpioGroup gpioGroup) {
	init_DigitalInput_GpioGroupAdapter(
			subject->priv.accelerometerMessageAdaptedInput, gpioGroup,
			UniversalPin_MessageInput);
	init_DigitalOutput_GpioGroupAdapter(
			subject->priv.accelerometerMessageAdaptedInput, gpioGroup,
			UniversalPin_MessageOutput);
	init_DigitalOutput_GpioGroupAdapter(
			subject->priv.buzzerAdpatedOutput,
			UniversalPin_Buzzer);
}
