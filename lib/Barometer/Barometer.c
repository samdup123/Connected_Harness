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
		printf("index%d ", index);
		printf("alt%d ",subject->priv.entryTable[index].altitude);
		printf("time%d\n", subject->priv.entryTable[index].timeStamp);
	}

	for(uint8_t index = 0; index < SIZE_OF_BAROMETER_ALTITUDE_ARRAY; index++)
	{
		totalAltitudeCounts += subject->priv.entryTable[index].altitude;
	}

	*averageAltitude = totalAltitudeCounts / SIZE_OF_BAROMETER_ALTITUDE_ARRAY;
}

static const ty_i_api_Input averageAltitudeInterfaceApi = { ReadAverageAltitude };

void init_Barometer(
		ty_Barometer *subject,
		ty_i_Input *altimeterInput)
{
	subject->averageAltitudeInterface.api = &averageAltitudeInterfaceApi;
	subject->priv.altimeterInput = altimeterInput;

//	ty_BarometerAltitudeEntry zeroEntry;
//	zeroEntry.altitude = 0;
//	zeroEntry.timeStamp = 0;
//	ty_BarometerAltitudeEntry *entryPointer = subject->priv.entryTable;
//	for(uint8_t index = 0; index < SIZE_OF_BAROMETER_ALTITUDE_ARRAY; index++)
//	{
//		memcpy(entryPointer, &zeroEntry, sizeof(zeroEntry));
//	}

	for(uint8_t index = 0; index < SIZE_OF_BAROMETER_ALTITUDE_ARRAY; index++)
	{
		printf("alt%d ",subject->priv.entryTable[index].altitude);
		printf("time%d\n", subject->priv.entryTable[index].timeStamp);
	}
}

