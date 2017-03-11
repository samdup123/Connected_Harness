/*
 * ADXL345_Accelerometer Header File
 *
 * Description Driver for ADXL345 Accelerometer
 *
 * Written by JamApps
 */

#ifndef ADXL345_Accelerometer
#define ADXL345_Accelerometer

#include "ADXL345.h"
#include "i_Accelerometer.h"
#include <stdbool.h>

typedef struct
{
	ty_i_Accelerometer interface;

	struct
	{
		ADXL345 *adxl;
		bool hasFallen;
		bool hasCompletedFall;
	} priv;
} ty_ADXL345_Accelerometer;

void init_ADXL345_Accelerometer(ty_ADXL345_Accelerometer *subject);

#endif
