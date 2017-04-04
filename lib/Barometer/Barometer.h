/*
 * Barometer Header File
 *
 * Description Barometer object
 *
 * Written by JamApps
 */

#ifndef Barometer
#define Barometer

#include <stdint.h>
#include "i_Input.h"
#include "Feet.h"

typedef uint32_t ty_Velocity;
typedef uint32_t ty_TimeStamp;

//#define NEW_ENTRY(number)
//	ty_BarometerAltitudeEntry entry##number ;
//
//typedef struct
//{
//	NEW_ENTRY(1)
//	NEW_ENTRY(2)
//	NEW_ENTRY(3)
//	NEW_ENTRY(4)
//	NEW_ENTRY(5)
//	NEW_ENTRY(6)
//	NEW_ENTRY(7)
//	NEW_ENTRY(8)
//	NEW_ENTRY(9)
//	NEW_ENTRY(10)
//} ty_BarometerArrayStruct;

typedef struct
{
	ty_Feet altitude;
	ty_TimeStamp timeStamp;
} ty_BarometerAltitudeEntry;

#define SIZE_OF_BAROMETER_ALTITUDE_ARRAY (10)

typedef struct
{
	ty_i_Input downwardVelocityInterface;
	ty_i_Input averageAltitudeInterface;
	struct
	{
		ty_i_Input *altimeterInput;
		ty_Feet altitudeThreshold;
		ty_Velocity fallenThresholdSpeed;

		ty_BarometerAltitudeEntry entryTable[SIZE_OF_BAROMETER_ALTITUDE_ARRAY];

	} priv;
} ty_Barometer;

void init_Barometer(ty_Barometer *subject, ty_i_Input *altimeterInput);

void CaptureAltitudeEntry_Barometer(ty_Barometer *subject, ty_TimeStamp timeStamp);

#endif
