/*
 * ADXL345_Accelerometer Implementation
 *
 * Written by JamApps
 */

#include "ADXL345_Accelerometer.h"
#include <stdint.h>

static ADXL345 adxl = ADXL345();
static bool hasBeenInitialized;

static bool hasFallen;
static bool hasCompletedFall;

void ResetMembers() {
	hasFallen = false;
	hasCompletedFall = false;
}

void UpdateMembers(bool experiencingActivity, bool experiencingFreeFall) {
	if (experiencingActivity == true && hasFallen == false) {
		ResetMembers();
	}
	else if (experiencingActivity == true && hasFallen == true)
	{
		hasCompletedFall = true;
	}
	else if (experiencingFreeFall == true && hasFallen == false)
	{
		hasFallen = true;
	}
}

void SetTriggers_ADXL345_Accelerometer(void) {
	if (hasBeenInitialized) {
		uint8_t interrupts = adxl.getInterruptSource();

		UpdateMembers(
				adxl.triggered(interrupts, ADXL345_ACTIVITY),
				adxl.triggered(interrupts, ADXL345_FREE_FALL));
	}
}

bool CheckStatus_ADXL345_Accelerometer(void)
{
	return hasCompletedFall;
}


void init_ADXL345_Accelerometer(void) {
	if (!hasBeenInitialized) {
		hasFallen = true;
		hasCompletedFall = true;

		adxl.powerOn();

		//set activity/ inactivity thresholds (0-255)
		adxl.setActivityThreshold(75); //62.5mg per increment
		adxl.setInactivityThreshold(75); //62.5mg per increment

		//look of activity movement on this axes - 1 == on; 0 == off
		adxl.setActivityX(1);
		adxl.setActivityY(1);
		adxl.setActivityZ(1);

		//look of inactivity movement on this axes - 1 == on; 0 == off
		adxl.setInactivityX(1);
		adxl.setInactivityY(1);
		adxl.setInactivityZ(1);

		//look of tap movement on this axes - 1 == on; 0 == off
		adxl.setTapDetectionOnX(0);
		adxl.setTapDetectionOnY(0);
		adxl.setTapDetectionOnZ(1);

		//set values for what is a tap, and what is a double tap (0-255)
		adxl.setTapThreshold(50); //62.5mg per increment
		adxl.setTapDuration(15); //625μs per increment
		adxl.setDoubleTapLatency(80); //1.25ms per increment
		adxl.setDoubleTapWindow(200); //1.25ms per increment

		//set values for what is considered freefall (0-255)
		adxl.setFreeFallThreshold(7); //(5 - 9) recommended - 62.5mg per increment
		adxl.setFreeFallDuration(10); //(20 - 70) recommended - 5ms per increment

		//setting all interupts to take place on int pin 1
		//I had issues with int pin 2, was unable to reset it
		adxl.setInterruptMapping( ADXL345_INT_SINGLE_TAP_BIT, ADXL345_INT1_PIN);
		adxl.setInterruptMapping( ADXL345_INT_DOUBLE_TAP_BIT, ADXL345_INT1_PIN);
		adxl.setInterruptMapping( ADXL345_INT_FREE_FALL_BIT, ADXL345_INT1_PIN);
		adxl.setInterruptMapping( ADXL345_INT_ACTIVITY_BIT, ADXL345_INT1_PIN);
		adxl.setInterruptMapping( ADXL345_INT_INACTIVITY_BIT, ADXL345_INT1_PIN);

		//register interupt actions - 1 == on; 0 == off
		adxl.setInterrupt( ADXL345_INT_SINGLE_TAP_BIT, 1);
		adxl.setInterrupt( ADXL345_INT_DOUBLE_TAP_BIT, 1);
		adxl.setInterrupt( ADXL345_INT_FREE_FALL_BIT, 1);
		adxl.setInterrupt( ADXL345_INT_ACTIVITY_BIT, 1);
		adxl.setInterrupt( ADXL345_INT_INACTIVITY_BIT, 0);
		hasBeenInitialized = true;
	}

}
