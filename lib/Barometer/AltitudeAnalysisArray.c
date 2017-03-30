/*
 * AltitudeAnalysisArray implementation
 *
 *
 * Written by JamApps
 */

#include "AltitudeAnalysisArray.h"
#include <stdio.h>

void init_AltitudeAnalysisArray(
		ty_AltitudeAnalysisArray *subject,
		void*altitudeTable,
		uint8_t numberOfEntries)
{
	subject->priv.altitudeTable = (ty_entry_AltitudeAnalysisArray *)altitudeTable;
	subject->priv.tableSize = numberOfEntries;
}

bool AverageAltitudeAboveThreshold_AltitudeAnalysisArray(
		ty_AltitudeAnalysisArray *subject,
		ty_AltitudeUnits threshold)
{
	uint32_t totalOfArray = 0;
	for(uint8_t i = 0; i < subject->priv.tableSize; i++)
	{
		totalOfArray += subject->priv.altitudeTable[i].altitude;
	}

	subject->priv.averageAltitude = totalOfArray / subject->priv.tableSize;

	printf("%d %d %d", subject->priv.averageAltitude, threshold, subject->priv.averageAltitude >= threshold);

	return subject->priv.averageAltitude >= threshold;
}

ty_AltitudeUnitsPerUnitOfTime DownwardVelocity_AltitudeAnalysisArray(ty_AltitudeAnalysisArray *subject)
{
	ty_AltitudeUnits leastRecentAltitudeReading = subject->priv.altitudeTable[0].altitude;
	uint32_t leastRecentTimeStamp = subject->priv.altitudeTable[0].timeStamp;

	ty_AltitudeUnits mostRecentAltitudeReading = subject->priv.altitudeTable[ subject->priv.tableSize - 1 ].altitude;
	uint32_t mostRecentTimeStamp = subject->priv.altitudeTable[ subject->priv.tableSize - 1 ].timeStamp;


	printf("---%d---", mostRecentAltitudeReading < leastRecentAltitudeReading);
	if (mostRecentAltitudeReading < leastRecentAltitudeReading)
	{
		double altitudeDifference = leastRecentAltitudeReading - mostRecentAltitudeReading;
		double timeDifference = mostRecentTimeStamp - leastRecentTimeStamp;
		printf("altdiff%f timediff%f\n", altitudeDifference, timeDifference);
		return altitudeDifference / timeDifference;
	}
	else
	{
		return 0;
	}
}
