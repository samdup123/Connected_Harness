#include <Wire.h>
#include "SparkFunMPL3115A2.h"
#include "Altimeter_MPL3115A2.h"

//MPL3115A2 myPressure;

ty_Altimeter_MPL3115A2 altimeter;

void setup() {
	init_AltimeterMPL3115A2(&altimeter);
	Serial.begin(9600);  // Start serial for output
}

void loop() {
	Serial.print("farts");
	uint16_t altitude;
	Read_Input(&altimeter.interface, &altitude);
	Serial.print(altitude);
	Serial.println();
}
