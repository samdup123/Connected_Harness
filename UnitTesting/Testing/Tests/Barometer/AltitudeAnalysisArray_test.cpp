///*
// * Description tests the Altitude Analysis Array
// *
// * Written by JamApps
// */
//
//extern "C" {
//#include "AltitudeAnalysisArray.h"
//#include <string.h>
//#include <stdio.h>
//}
//#include "CppUTest/TestHarness.h"
//
//#define Given
//#define Then
//#define Thus
//#define And
//
//enum
//{
//	ArbitraryThreshold = 50,
//	Zero = 0,
//	Ten = 10,
//
//	ArraySize = 30
//};
//
//TEST_GROUP(AltitudeAnalysisArray_test)
//{
//	ty_AltitudeAnalysisArray subject;
//	ty_entry_AltitudeAnalysisArray analysisEntryTable[ArraySize];
//
//	ty_entry_AltitudeAnalysisArray arbitraryEntry;
//
//	void TheAltitudeAnalysisArrayHasBeenInitialized()
//	{
//		init_AltitudeAnalysisArray(&subject, &analysisEntryTable, 30);
//	}
//
//	void AverageAltitudeShouldBeAtOrAbove(ty_AltitudeUnits threshold)
//	{
//		CHECK(AverageAltitudeAboveThreshold_AltitudeAnalysisArray(&subject, threshold));
//	}
//
//	void AverageAltitudeShouldBeBelow(ty_AltitudeUnits threshold)
//	{
//		CHECK_FALSE(AverageAltitudeAboveThreshold_AltitudeAnalysisArray(&subject, threshold));
//	}
//
//	void TheDownwardVelocityShouldBe( ty_AltitudeUnitsPerUnitOfTime expectedVelocity)
//	{
//		ty_AltitudeUnitsPerUnitOfTime actualVelocity = DownwardVelocity_AltitudeAnalysisArray(&subject);
//		CHECK_EQUAL( expectedVelocity, actualVelocity);
//	}
//
//	void TheArrayIsFilledWithValuesOfAltitude(ty_AltitudeUnits altitude)
//	{
//		ty_entry_AltitudeAnalysisArray *entryPointer = analysisEntryTable;
//		arbitraryEntry.altitude = altitude;
//		for( uint8_t i = 0; i < ArraySize; i++)
//		{
//			memcpy(entryPointer, &arbitraryEntry, sizeof(arbitraryEntry));
//			entryPointer += 1;
//		}
//	}
//
//	void TheArrayIsFilledWithEntriesThatIncreaseAtVelocityOf10()
//	{
//		ty_entry_AltitudeAnalysisArray *entryPointer = analysisEntryTable;
//		arbitraryEntry.altitude = 300;
//		arbitraryEntry.timeStamp = 1;
//		for( uint8_t i = 0; i < ArraySize; i++)
//		{
//			memcpy(entryPointer, &arbitraryEntry, sizeof(arbitraryEntry));
//			entryPointer += 1;
//
//			arbitraryEntry.altitude -= 10;
//			arbitraryEntry.timeStamp += 1;
//		}
//	}
//
//	void TheClimbersAltitudeAndTimeStampAre(ty_AltitudeUnits altitude, uint32_t timeStamp)
//	{
//		arbitraryEntry.altitude = altitude;
//		arbitraryEntry.timeStamp = timeStamp;
//	}
//
//	void ThisNewEntryIsAdded()
//	{
//		Write_Output(&subject.interface, &arbitraryEntry);
//	}
//
//	void TheClimberIsMovingDownAtAVelocity(ty_AltitudeUnitsPerUnitOfTime velocity)
//	{
//		for (uint16_t i = 0; i < ArraySize; i++)
//		{
//			arbitraryEntry.altitude -= velocity;
//			arbitraryEntry.timeStamp += 1;
//			ThisNewEntryIsAdded();
//		}
//	}
//
//	void TheFirstEntryInTheArrayShouldHaveAltitudeOf(ty_AltitudeUnits expectedAltitude)
//	{
//		ty_AltitudeUnits actualAltitude = analysisEntryTable[ ArraySize - 1 ].altitude;
//		CHECK_EQUAL(expectedAltitude, actualAltitude);
//	}
//
//	void TheFirstEntryInTheArrayShouldHaveATimeStampOf(uint32_t expectedTimeStamp)
//	{
//		ty_AltitudeUnits actualTimeStamp = analysisEntryTable[ ArraySize - 1 ].timeStamp;
//		CHECK_EQUAL(expectedTimeStamp, actualTimeStamp);
//	}
//};
//
//TEST(AltitudeAnalysisArray_test, ShouldInit)	{
//	TheAltitudeAnalysisArrayHasBeenInitialized();
//}
//
//TEST(AltitudeAnalysisArray_test, ShouldIdentifyThatAverageAltitudeIsBelowThresholdWhenAverageIsZero)	{
//	Given TheAltitudeAnalysisArrayHasBeenInitialized();
//
//	AverageAltitudeShouldBeBelow(ArbitraryThreshold);
//}
//
//TEST(AltitudeAnalysisArray_test, ShouldIdentifyThatAverageAltitudeIsAboveZero)	{
//	Given TheAltitudeAnalysisArrayHasBeenInitialized();
//
//	AverageAltitudeShouldBeAtOrAbove(Zero);
//}
//
//TEST(AltitudeAnalysisArray_test, ShouldIdentitfyThatAverageAltitudeIsAtOrAboveThreshold)	{
//	Given TheAltitudeAnalysisArrayHasBeenInitialized();
//	And TheArrayIsFilledWithValuesOfAltitude(ArbitraryThreshold);
//
//	AverageAltitudeShouldBeAtOrAbove(ArbitraryThreshold);
//}
//
//TEST(AltitudeAnalysisArray_test, ShouldIdentitfyThatAverageAltitudeIsBelowThreshold)	{
//	Given TheAltitudeAnalysisArrayHasBeenInitialized();
//	And TheArrayIsFilledWithValuesOfAltitude(ArbitraryThreshold - 1);
//
//	AverageAltitudeShouldBeBelow(ArbitraryThreshold);
//}
//
//TEST(AltitudeAnalysisArray_test, ShouldReportVelocityOfZeroAfterInitialization)	{
//	Given TheAltitudeAnalysisArrayHasBeenInitialized();
//
//	TheDownwardVelocityShouldBe(Zero);
//}
//
//TEST(AltitudeAnalysisArray_test, ShouldReportCorrectDownwardVelocity)	{
//	Given TheAltitudeAnalysisArrayHasBeenInitialized();
//	And TheArrayIsFilledWithEntriesThatIncreaseAtVelocityOf10();
//
//	TheDownwardVelocityShouldBe(Ten);
//}
//
//TEST(AltitudeAnalysisArray_test, ShouldUpdateCorrectly)	{
//	Given TheAltitudeAnalysisArrayHasBeenInitialized();
//	And TheClimbersAltitudeAndTimeStampAre(1000, 333);
//	And ThisNewEntryIsAdded();
//
//	Thus TheFirstEntryInTheArrayShouldHaveAltitudeOf(1000);
//	And TheFirstEntryInTheArrayShouldHaveATimeStampOf(333);
//}
//
//TEST(AltitudeAnalysisArray_test, ShouldUpdateWithASpecifiedVelocity)	{
//	Given TheAltitudeAnalysisArrayHasBeenInitialized();
//	And TheClimbersAltitudeAndTimeStampAre(1000, 333);
//	And TheClimberIsMovingDownAtAVelocity(25);
//
//	Thus TheDownwardVelocityShouldBe(25);
//}
