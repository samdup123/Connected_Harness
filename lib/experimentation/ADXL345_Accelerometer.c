/*
 * ADXL345_Accelerometer Implementation
 *
 * Written by JamApps
 */

#include "ADXL345_Accelerometer.h"
#include "utilities.h"

static void CollectTrigger(void subj*)
{
	RECAST(subject, subj, ty_ADXL345_Accelerometer*);

byte interrupts = adxl.getInterruptSource();

if (subject->hasFallen)
{
	if(adxl.triggered(interrupts, ADXL345_ACTIVITY)) {
		subject->hasCompletedFall = true;
	}
}
else
{
	if(adxl.triggered(interrupts, ADXL345_FREE_FALL)) {
		subject->hasFallen = true;
	}
	else
	{
		//reset variables
		subject->hasFallen = false;
		subject->hasCompletedFall = false;
	}
}
}

static bool HasFallen(void *subj) {
	RECAST(subject, subj, ty_ADXL345_Accelerometer*);
	return subject->hasFallen && subject->HasCompletedFall;
}

void init_ADXL345_Accelerometer(ty_ADXL345_Accelerometer *subject) {
	subject->hasFallen = false;

	static ADXL345 adxl;

	subject->adxl = adxl;

	adxl.powerOn();

//set activity/ inactivity thresholds (0-255)
	adxl.setActivityThreshold(75); //62.5mg per increment
	adxl.setInactivityThreshold(75); //62.5mg per increment

//look of activity movement on this axes - 1 == on; 0 == off
	adxl.setActivityX(1);
	adxl.setActivityY(1);
	adxl.setActivityZ(1);

//set values for what is considered freefall (0-255)
	adxl.setFreeFallThreshold(7); //(5 - 9) recommended - 62.5mg per increment
	adxl.setFreeFallDuration(10); //(20 - 70) recommended - 5ms per increment

//setting all interupts to take place on int pin 1
//I had issues with int pin 2, was unable to reset it
	adxl.setInterruptMapping(ADXL345_INT_SINGLE_TAP_BIT, ADXL345_INT1_PIN);
	adxl.setInterruptMapping(ADXL345_INT_DOUBLE_TAP_BIT, ADXL345_INT1_PIN);
	adxl.setInterruptMapping(ADXL345_INT_FREE_FALL_BIT, ADXL345_INT1_PIN);
	adxl.setInterruptMapping(ADXL345_INT_ACTIVITY_BIT, ADXL345_INT1_PIN);
	adxl.setInterruptMapping(ADXL345_INT_INACTIVITY_BIT, ADXL345_INT1_PIN);

//register interupt actions - 1 == on; 0 == off
	adxl.setInterrupt(ADXL345_INT_SINGLE_TAP_BIT, 1);
	adxl.setInterrupt(ADXL345_INT_DOUBLE_TAP_BIT, 1);
	adxl.setInterrupt(ADXL345_INT_FREE_FALL_BIT, 1);
	adxl.setInterrupt(ADXL345_INT_ACTIVITY_BIT, 1);
	adxl.setInterrupt(ADXL345_INT_INACTIVITY_BIT, 0);
}
