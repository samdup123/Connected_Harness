///*
// * AltitudeAnalysisArray Header File
// *
// * Description analyzes an array of altitudes
// *
// * Written by JamApps
// */
//
//#ifndef AltitudeAnalysisArray
//#define AltitudeAnalysisArray
//
//#include <stdint.h>
//#include <stdbool.h>
//#include "i_Output.h"
//
//typedef uint32_t ty_AltitudeUnits;
//typedef uint16_t ty_AltitudeUnitsPerUnitOfTime;
//
//typedef struct
//{
//	ty_AltitudeUnits altitude;
//	uint32_t timeStamp;
//} ty_entry_AltitudeAnalysisArray;
//
//typedef struct
//{
//
//} ty_altitude;
//
//typedef struct
//{
//	ty_i_Output interface;
//	struct
//	{
//		ty_entry_AltitudeAnalysisArray *altitudeTable;
//		uint8_t tableSize;
//
//		ty_AltitudeUnits averageAltitude;
//	} priv;
//} ty_AltitudeAnalysisArray;
//
//void init_AltitudeAnalysisArray(
//		ty_AltitudeAnalysisArray *subject,
//		void *altitudeTable,
//		uint8_t numberOfEntries);
//
//bool AverageAltitudeAboveThreshold_AltitudeAnalysisArray(
//		ty_AltitudeAnalysisArray *subject,
//		ty_AltitudeUnits threshold);
//
//ty_AltitudeUnitsPerUnitOfTime DownwardVelocity_AltitudeAnalysisArray(
//		ty_AltitudeAnalysisArray *subject);
//
//#endif
