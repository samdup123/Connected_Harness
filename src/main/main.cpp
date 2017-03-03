/**
 * Blink
 *
 * Turns on an ONBOARD_LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"
#include "uno_GpioGroup.h"
#include "uno_GpioGroup.c"
#include "i_GpioGroup.h"
#include "UniversalPins.h"

static const ty_i_GpioGroup* gpio;

enum
{
	LED = UniversalPin_Led,
	ONBOARD_LED = UniversalPin_OnBoardLed
};

void setup() {
	//pinMode(uno_DigitalPin_NonPwm_2, HIGH);
	gpio = init_uno_GpioGroup();
	Serial.begin(9600);
}

void loop() {
	// turn the ONBOARD_LED on (HIGH is the voltage level)
	//digitalWrite(uno_DigitalPin_NonPwm_2, HIGH);

	Write_GpioGroup(gpio, ONBOARD_LED, HIGH);

	delay(300);
	//Serial.print(Read_GpioGroup(gpio, ONBOARD_LED));

	// turn the ONBOARD_LED off by making the voltage LOW
	Write_GpioGroup(gpio, ONBOARD_LED, LOW);

	// wait for a second
	delay(300);
}
