/*
 * Accelerometer_ADXL345 implementation
 *
 *
 * Written by JamApps
 */

#include "ADXL345.h"
#include "Accelerometer_ADXL345.h"
#include "utilities.h"
static ADXL345 adxl;

void Reset(void *subj) {
	RECAST(subject, subj, ty_Accelerometer_ADXL345 *);

	subject->priv.hasFallen = false;
}

bool CheckHasFallen(void *subj) {
	RECAST(subject, subj, ty_Accelerometer_ADXL345 *);
	uint8_t interrupts = adxl.getInterruptSource();

	if (adxl.triggered(interrupts, ADXL345_FREE_FALL)) {
		subject->priv.hasFallen = true;
	}

	return subject->priv.hasFallen;
}

static const ty_i_api_Accelerometer api = { Reset, CheckHasFallen };

void init_Accelerometer_ADXL345(ty_Accelerometer_ADXL345 *subject) {

	subject->priv.hasFallen = false;
	subject->interface.api = &api;

	adxl.powerOn();

	adxl.setFreeFallThreshold(10);
	adxl.setFreeFallDuration(40);

	adxl.setInterrupt(ADXL345_INT_FREE_FALL_BIT, 1);

	adxl.setInterrupt(ADXL345_INT_ACTIVITY_BIT, 0);
	adxl.setInterrupt(ADXL345_INT_DOUBLE_TAP_BIT, 0);
	adxl.setInterrupt(ADXL345_INT_SINGLE_TAP_BIT, 0);
	adxl.setInterrupt(ADXL345_INT_INACTIVITY_BIT, 0);
}
