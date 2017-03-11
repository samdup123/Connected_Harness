extern "C"
{
#include <uno_GpioGroup.h>
#include "DigitalOutput_GpioGroupAdapter.h"
#include "utilities.h"
}
#include "Arduino.h"

static ty_i_GpioGroup *gpio;
static ty_DigitalOutput_GpioGroupAdapter digOut;

void setup() {
//	gpio = init_uno_GpioGroup();
//	Serial.begin(9600);
//
//	init_DigitalInputPullup_GpioGroupAdapter(&digitalInputPullupAdapter, gpio, 4);
}

void loop() {
//	bool state = Read_DigitalInputPullup(&digitalInputPullupAdapter.interface);
//	Write_GpioGroup(gpio, 2, state);
//	delay(1);
}
