#include "Arduino.h"
#include <Wire.h>
#include "SparkFunMPL3115A2.h"

MPL3115A2 myPressure;

#define ARRAY_SIZE (35)

uint16_t altitudeArray[ARRAY_SIZE];
uint16_t timeStampArray[ARRAY_SIZE];

uint32_t oldTimeReadingInMillis;
uint32_t newTimeReadingInMillis;

void printDouble(double val, unsigned int precision) {
// prints val with number of decimal places determine by precision
// NOTE: precision is 1 followed by the number of zeros for the desired number of decimial places
// example: printDouble( 3.1415, 100); // prints 3.14 (two decimal places)

	Serial.print(int(val));  //prints the int part
	Serial.print("."); // print the decimal point
	unsigned int frac;
	if (val >= 0)
		frac = (val - int(val)) * precision;
	else
		frac = (int(val) - val) * precision;
	Serial.println(frac, DEC);
}

void takeAltitudeReading(uint32_t newTimeStamp) {
	// altitude array
	for (uint8_t index = 1; index < ARRAY_SIZE; index++) {
		altitudeArray[index - 1] = altitudeArray[index];
	}
	altitudeArray[ ARRAY_SIZE - 1] = myPressure.readAltitudeFt();

	// time array
	for (uint8_t index = 1; index < ARRAY_SIZE; index++) {
		timeStampArray[index - 1] = timeStampArray[index];
	}
	timeStampArray[ ARRAY_SIZE - 1] = newTimeStamp;
}

void catchUpOldTimeReading() {
	oldTimeReadingInMillis = newTimeReadingInMillis;
}

uint32_t getTotalTimeThatHasPassedInArrays() {
	uint32_t totalTime = 0;
	for (uint8_t index = 0; index < ARRAY_SIZE; index++) {
		totalTime += timeStampArray[index];
	}
	return totalTime;
}

uint16_t getDownwardVelocity() {
	uint16_t mostRecentAltitude = altitudeArray[ARRAY_SIZE - 1];
	uint16_t leastRecentAltitude = altitudeArray[0];
	if (mostRecentAltitude < leastRecentAltitude) {

		double altitudeDifference = leastRecentAltitude - mostRecentAltitude;
		double timeDifferenceInHundos = getTotalTimeThatHasPassedInArrays();

		double velocity = (altitudeDifference * 1000) / timeDifferenceInHundos;

		return velocity;
	} else {
		return 0;
	}

}

void setup() {
	Serial.begin(9600);
	Wire.begin();
	myPressure.begin();

	myPressure.setModeAltimeter();

	myPressure.setOversampleRate(7); // Set Oversample to the recommended 128
	myPressure.enableEventFlags();

	oldTimeReadingInMillis = 0;
}

void loop() {
	newTimeReadingInMillis = millis();
	uint16_t timeDiff = newTimeReadingInMillis - oldTimeReadingInMillis;

	if (timeDiff > 5) {
		takeAltitudeReading(timeDiff);
		catchUpOldTimeReading();
	}

	Serial.print("-");
	Serial.print(getDownwardVelocity());
	Serial.print("-");
}

