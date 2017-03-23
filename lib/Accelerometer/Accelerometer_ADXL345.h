/*
 * Accelerometer_ADXL345 Header File
 *
 * Description accelerometer driver for the ADXL345
 *
 * Written by JamApps
 */

#ifndef Accelerometer_ADXL345
#define Accelerometer_ADXL345

#include "i_Accelerometer.h"
#include "utilities.h"

typedef struct
{
	ty_i_Accelerometer interface;

	struct
	{
		bool hasFallen;
	} priv;
} ty_Accelerometer_ADXL345;

void init_Accelerometer_ADXL345(ty_Accelerometer_ADXL345 *subject);

#endif
