/*
 * Barometer implementation
 *
 *
 * Written by JamApps
 */

#include "Barometer.h"
#include "utilities.h"
#include <stdio.h>

void ReadAverageAltitude(void *subj, void *data)
{
	RECAST(subject, subj, ty_Barometer *);
	RECAST(averageAltitude, data, ty_Feet *);

	ty_Feet totalAltitudeCounts = 0;
	for(uint8_t index = 0; index < SIZE_OF_BAROMETER_ALTITUDE_ARRAY; index++)
	{
		totalAltitudeCounts += subject->priv.entryTable[index].altitude;
	}

	*averageAltitude = totalAltitudeCounts / SIZE_OF_BAROMETER_ALTITUDE_ARRAY;
}

static const ty_i_api_Input averageAltitudeInterfaceApi = { ReadAverageAltitude };

void init_Barometer(ty_Barometer *subject, ty_i_Input *altimeterInput)
{
	subject->averageAltitudeInterface.api = &averageAltitudeInterfaceApi;
	subject->priv.altimeterInput = altimeterInput;
}

void CaptureAltitudeEntry_Barometer(ty_Barometer *subject, ty_TimeStamp timeStamp)
{
	ty_Feet newAltitude;
	Read_Input(subject->priv.altimeterInput, &newAltitude);

	for(uint8_t index = 1; index < SIZE_OF_BAROMETER_ALTITUDE_ARRAY; index++)
	{
		subject->priv.entryTable[index - 1].altitude = subject->priv.entryTable[index].altitude;
		subject->priv.entryTable[index - 1].timeStamp = subject->priv.entryTable[index].timeStamp;
	}

	subject->priv.entryTable[SIZE_OF_BAROMETER_ALTITUDE_ARRAY - 1].altitude = newAltitude;
	subject->priv.entryTable[SIZE_OF_BAROMETER_ALTITUDE_ARRAY - 1].timeStamp = timeStamp;
}

