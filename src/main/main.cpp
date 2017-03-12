extern "C"
{
#include <uno_GpioGroup.h>
#include "DigitalInput_GpioGroupAdapter.h"
#include "DigitalInputPullup_GpioGroupAdapter.h"
#include "utilities.h"
}
#include "Arduino.h"

static ty_i_GpioGroup *gpio;
static ty_DigitalInput_GpioGroupAdapter digIn;
static ty_DigitalInputPullup_GpioGroupAdapter digInPullup;

void setup() {
	gpio = init_uno_GpioGroup();
	Serial.begin(9600);

	init_DigitalInputPullup_GpioGroupAdapter(&digInPullup, gpio, 4);
	init_DigitalInput_GpioGroupAdapter(&digIn, gpio, 4);
}

void loop() {
	bool state = Read_DigitalInputPullup(&digInPullup.interface);
	Serial.print("\npullup");
	Serial.println(state);

    state = Read_DigitalInputPullup(&digIn.interface);
	Serial.print("\nnotpullup");
	Serial.println(state);
	delay(700);
}
