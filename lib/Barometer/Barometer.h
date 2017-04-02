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
#include "i_Output.h"
#include "i_InputToOutputMapper.h"
#include "i_DigitalInput.h"
#include "AltitudeAnalysisArray.h"
#include "AddTimeStamp_InputToOutputMapper.h"

typedef uint32_t ty_Velocity;
typedef uint32_t ty_Feet;
typedef uint32_t ty_TimeStamp;

typedef struct
{
	ty_Feet altitude;
	ty_TimeStamp timeStamp;
} ty_BarometerAltitudeEntry;

#define SIZE_OF_BAROMETER_ALTITUDE_ARRAY (60)

typedef struct
{
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
