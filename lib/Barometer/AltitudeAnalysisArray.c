///*
// * AltitudeAnalysisArray implementation
// *
// *
// * Written by JamApps
// */
//
//#include "AltitudeAnalysisArray.h"
//#include "utilities.h"
//#include <stdio.h>
//
//static void UpdateArray(void *subj, void *data)
//{
//	RECAST(subject, subj, ty_AltitudeAnalysisArray *);
//
//
//	ty_entry_AltitudeAnalysisArray *entryPointer = subject->priv.altitudeTable;
//	for(uint8_t i = 0; i < subject->priv.tableSize; i++)
//	{
//		printf("%d", entryPointer->altitude);
//	}
//
//	printf("faaaaaaaaaaaarts");
//
//	for(uint8_t index = 1; index < subject->priv.tableSize; index++)
//	{
//		subject->priv.altitudeTable[index - 1] = subject->priv.altitudeTable[index];
//	}
//	subject->priv.altitudeTable[ subject->priv.tableSize - 1] = *(ty_entry_AltitudeAnalysisArray *)data;
//}
//
//static const ty_i_api_Output api =
//{
//		UpdateArray
//};
//
//void init_AltitudeAnalysisArray(
//		ty_AltitudeAnalysisArray *subject,
//		void *altitudeTable,
//		uint8_t numberOfEntries)
//{
//	subject->interface.api = &api;
//
//	subject->priv.altitudeTable = (ty_entry_AltitudeAnalysisArray )altitudeTable;
//
//
////	subject->priv.altitudeTable[0].altitude = 5466;
////	subject->priv.altitudeTable[1].altitude = 54466;
//	volatile uint32_t test1 = subject->priv.altitudeTable[0].altitude;
//	volatile uint32_t test2 = subject->priv.altitudeTable[1].altitude;
//	(void)test1;
//	(void)test2;
//
//	subject->priv.tableSize = numberOfEntries;
//}
//
//bool AverageAltitudeAboveThreshold_AltitudeAnalysisArray(
//		ty_AltitudeAnalysisArray *subject,
//		ty_AltitudeUnits threshold)
//{
//	uint32_t totalOfArray = 0;
//
//	subject->priv.averageAltitude = totalOfArray / subject->priv.tableSize;
//
//	return subject->priv.averageAltitude >= threshold;
//}
//
//ty_AltitudeUnitsPerUnitOfTime DownwardVelocity_AltitudeAnalysisArray(ty_AltitudeAnalysisArray *subject)
//{
//	ty_AltitudeUnits leastRecentAltitudeReading = subject->priv.altitudeTable[0].altitude;
//	uint32_t leastRecentTimeStamp = subject->priv.altitudeTable[0].timeStamp;
//
//	ty_AltitudeUnits mostRecentAltitudeReading = subject->priv.altitudeTable[ subject->priv.tableSize - 1 ].altitude;
//	uint32_t mostRecentTimeStamp = subject->priv.altitudeTable[ subject->priv.tableSize - 1 ].timeStamp;
//
//	if (mostRecentAltitudeReading < leastRecentAltitudeReading)
//	{
//		double altitudeDifference = leastRecentAltitudeReading - mostRecentAltitudeReading;
//		double timeDifference = mostRecentTimeStamp - leastRecentTimeStamp;
//		return altitudeDifference / timeDifference;
//	}
//	else
//	{
//		return 0;
//	}
//}
