extern "C"
{
#include "uno_GpioGroup.h"
#include "DigitalInput_GpioGroupAdapter.h"
#include "DigitalOutput_GpioGroupAdapter.h"
#include "utilities.h"
}
#include "Arduino.h"

static ty_i_GpioGroup *gpio;
static ty_DigitalInput_GpioGroupAdapter accelerometerInputAdapter;
static ty_DigitalOutput_GpioGroupAdapter messageAcceptanceOutputAdapter;
static ty_DigitalOutput_GpioGroupAdapter ledOutputAdapter;
static bool hasFallen;

void setup() {
	gpio = init_uno_GpioGroup();
	Serial.begin(9600);

	init_DigitalInput_GpioGroupAdapter(&accelerometerInputAdapter, gpio, 7);
	init_DigitalOutput_GpioGroupAdapter(&messageAcceptanceOutputAdapter, gpio, 8);
	init_DigitalOutput_GpioGroupAdapter(&ledOutputAdapter, gpio, LED_BUILTIN);
}

void loop() {
	if (Read_DigitalInput(&accelerometerInputAdapter.interface))
	{
		Write_DigitalOutput(&ledOutputAdapter.interface, ON);
		hasFallen = true;
	}

	delay(500);

	if (hasFallen)
	{
		Write_DigitalOutput(&ledOutputAdapter.interface, OFF);
	}
}
