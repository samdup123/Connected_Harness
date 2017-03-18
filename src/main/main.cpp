
extern "C"
{
#include "uno_GpioGroup.h"
}
#include "Input_RadioFrequencyReceiver.h"
#include "Arduino.h"

static ty_i_GpioGroup *gpio;
static ty_Input_RadioFrequencyReciever receiver;

void setup() {
	gpio = init_uno_GpioGroup();
	Serial.begin(9600);

	init_Input_RadioFrequencyReceiver(&receiver, 12);
}

void loop() {
	bool state = Read_DigitalInput(&receiver.interface);
	if (state)
	{
		Serial.println("good!!!!");
	}
	else
	{
		Serial.println("shit");
	}
}
