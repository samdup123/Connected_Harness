#include "Accelerometer_ADXL345.h"
#include "Arduino.h"
#include <Wire.h>

	static ty_Accelerometer_ADXL345 adxl;
	static ty_i_Accelerometer *accel;

void setup() {
	Serial.begin(9600);


	init_Accelerometer_ADXL345(&adxl);
	accel = &adxl.interface;
}

void loop() {
	bool state = CheckHasFallen_Accelerometer(accel);
	if (state)
	{
		Serial.println("good!!!!");
		delay(1000);
		Reset_Accelerometer(accel);
	}
	else
	{
		Serial.println("shit");
	}
	delay(8);
	Serial.println("");
}
