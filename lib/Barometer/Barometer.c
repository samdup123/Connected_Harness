/*
 * Barometer implementation
 *
 *
 * Written by JamApps
 */

#include "Barometer.h"
#include "utilities.h"
#include <stdio.h>

static void ReadDownwardVelociy(void *subj, void *data)
{
	RECAST(subject, subj, ty_Barometer *);
	RECAST(downwardVelocity, data, double *);

	ty_BarometerAltitudeEntry mostRecentEntry =
			subject->priv.entryTable[SIZE_OF_BAROMETER_ALTITUDE_ARRAY - 1];

	ty_BarometerAltitudeEntry leastRecentEntry =
			subject->priv.entryTable[0];

	if(mostRecentEntry.altitude < leastRecentEntry.altitude)
	{
		double altitudeDifference = leastRecentEntry.altitude - mostRecentEntry.altitude;
		double timeDifference = mostRecentEntry.timeStamp - leastRecentEntry.timeStamp;
	    *downwardVelocity = altitudeDifference / timeDifference;
	}
	else
	{
		*downwardVelocity = 0;
	}
}

static const ty_i_api_Input downWardVelocityInterfaceApi = { ReadDownwardVelociy };

static void ReadAverageAltitude(void *subj, void *data)
{
	RECAST(subject, subj, ty_Barometer *);
	RECAST(averageAltitude, data, double *);

	ty_Feet totalAltitudeCounts = 0;
	for(uint8_t index = 0; index < SIZE_OF_BAROMETER_ALTITUDE_ARRAY; index++)
	{
		totalAltitudeCounts += subject->priv.entryTable[index].altitude;
	}

	*averageAltitude = ((totalAltitudeCounts+0.0) / SIZE_OF_BAROMETER_ALTITUDE_ARRAY);
}

static const ty_i_api_Input averageAltitudeInterfaceApi = { ReadAverageAltitude };

void init_Barometer(ty_Barometer *subject, ty_i_Input *altimeterInput)
{
	subject->averageAltitudeInterface.api = &averageAltitudeInterfaceApi;
	subject->downwardVelocityInterface.api = &downWardVelocityInterfaceApi;

	subject->priv.altimeterInput = altimeterInput;
}

void CaptureAltitudeEntry_Barometer(ty_Barometer *subject, ty_TimeStamp timeStamp)
{
	ty_Feet newAltitude;
	Read_Input(subject->priv.altimeterInput, &newAltitude);

	for (uint8_t index = 1; index < SIZE_OF_BAROMETER_ALTITUDE_ARRAY; index++)
	{
		memcpy(
				&subject->priv.entryTable[index - 1],
				&subject->priv.entryTable[index],
				sizeof(ty_BarometerAltitudeEntry));
	}

	subject->priv.entryTable[SIZE_OF_BAROMETER_ALTITUDE_ARRAY - 1].altitude = newAltitude;
	subject->priv.entryTable[SIZE_OF_BAROMETER_ALTITUDE_ARRAY - 1].timeStamp = timeStamp;
}

