extern "C"
{
#include "uno_GpioGroup.h"
#include "UniversalConstants.h"
#include "DigitalInputPullup_GpioGroupAdapter.h"
}
#include "Arduino.h"

static ty_i_GpioGroup *gpio;
static ty_DigitalInputPullup_GpioGroupAdapter digitalInputPullupAdapter;

void setup() {
	gpio = init_uno_GpioGroup();
	Serial.begin(9600);

	init_DigitalInputPullup_GpioGroupAdapter(&digitalInputPullupAdapter, gpio, 4);
}

void loop() {
	bool state = Read_DigitalInputPullup(&digitalInputPullupAdapter.interface);
	Write_GpioGroup(gpio, 2, state);
	delay(1);
}
