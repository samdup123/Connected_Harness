///*
// * Description Tests the barometer
// *
// * Written by JamApps
// */
//
//extern "C" {
//#include "Barometer.h"
//#include <stdio.h>
//}
//#include "CppUTest/TestHarness.h"
//#include "double_Input.h"
//
//#define Given
//#define Then
//#define Thus
//#define And
//
//enum
//{
//	Zero = 0,
//	NumberOfEntries = 50,
//
//	EightyFeetOffTheGround = 80,
//	EightyFeet = EightyFeetOffTheGround,
//	SeventyFeet = 70
//};
//
//TEST_GROUP(Barometer_test)
//{
//	ty_Barometer subject;
//	ty_entry_AltitudeAnalysisArray entryTable[NumberOfEntries];
//
//	ty_double_Input altimeterInputDouble;
//	ty_Feet altitude;
//
//	void setup()
//	{
//		init_double_Input(&altimeterInputDouble, &altitude, sizeof(altitude));
//	}
//
//	void TheBarometerIsInitialized()
//	{
//		init_Barometer(&subject, &entryTable, NumberOfEntries, &altimeterInputDouble.interface);
//	}
//
//	void TheAverageAltitudeShouldBe(ty_Feet expectedAverageAltitude)
//	{
//		ty_Feet totalAltitudeCounts;
//		for(uint32_t index = 0; index < NumberOfEntries; index++)
//		{
//			totalAltitudeCounts += entryTable[index].altitude;
//		}
//		ty_Feet actualAverageAltitude = totalAltitudeCounts / NumberOfEntries;
//		CHECK_EQUAL(expectedAverageAltitude, actualAverageAltitude);
//	}
//
//	void TheAverageTimeStampShouldBe(ty_Feet expectedAverageTimeStamp)
//	{
//		ty_Feet totalTimeCounts;
//		for(uint32_t index = 0; index < NumberOfEntries; index++)
//		{
//			totalTimeCounts += entryTable[index].timeStamp;
//		}
//		ty_Feet actualAverageTimeStamp = totalTimeCounts/ NumberOfEntries;
//		CHECK_EQUAL(expectedAverageTimeStamp, actualAverageTimeStamp);
//	}
//
//	void TheBarometerHasBeen(ty_Feet altitude)
//	{
//		ChangeData_double_Input(&altimeterInputDouble, &altitude);
//		for(uint8_t index = 0; index < NumberOfEntries; index++)
//		{
//			CaptureAltitudeEntry_Barometer(&subject, 0);
//			printf("poot\n");
//		}
//	}
//
//	void TheAltitudeThresholdIsSetTo(ty_Feet threshold)
//	{
//		Write_Output(&subject.thresholdUpdateOutput, &threshold);
//	}
//
//	void TheBarometerShouldReportThatItIsAboveItsThreshold()
//	{
//		bool aboveThreshold = Read_DigitalInput(&subject.aboveThresholdAltitudeInput);
//		CHECK_EQUAL(true, aboveThreshold);
//	}
//};
//
////TEST(Barometer_test, ShouldHaveEmptyEntryTableponInitialization)	{
////	Given TheBarometerIsInitialized();
////	TheAverageAltitudeShouldBe(Zero);
////	TheAverageTimeStampShouldBe(Zero);
////}
////
////TEST(Barometer_test, ShouldCorrectlyFillTheArrayWithAltitudes)	{
////	Given TheBarometerIsInitialized();
////	And TheBarometerHasBeen(EightyFeetOffTheGround);
////
////	TheAverageAltitudeShouldBe(EightyFeet);
////}
//
//TEST(Barometer_test, ShouldCorrectlyIdentifyThatTheBarometerIsAboveAThreshold)	{
//	Given TheBarometerIsInitialized();
//	And TheBarometerHasBeen(EightyFeetOffTheGround);
//	And TheAltitudeThresholdIsSetTo(SeventyFeet);
//
//	TheBarometerShouldReportThatItIsAboveItsThreshold();
//}
