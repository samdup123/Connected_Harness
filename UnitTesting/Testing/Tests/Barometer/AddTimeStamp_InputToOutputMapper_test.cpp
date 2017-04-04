///*
// * Description
// *
// * Written by JamApps
// */
//
//extern "C" {
//#include "AddTimeStamp_InputToOutputMapper.h"
//#include "AltitudeAnalysisArray.h"
//#include <stdint.h>
//#include <stdio.h>
//}
//#include "CppUTest/TestHarness.h"
//#include "double_Output.h"
//#include "double_Input.h"
//
//#define Given
//#define Then
//#define Thus
//#define And
//
//enum
//{
//	ArbitraryData = 43,
//	ArbitraryTimeStamp = 4000
//};
//
//TEST_GROUP(AddTimeStamp_InputToOutputMapper_test)
//{
//	ty_AddTimeStamp_InputToOutputMapper subject;
//
//	uint32_t data;
//	ty_entry_AltitudeAnalysisArray entry;
//
//	ty_double_Input dataInputDouble;
//	ty_double_Output mappedOutputDouble;
//
//	void setup()
//	{
//		init_double_Input(&dataInputDouble, &data, sizeof(data));
//		init_double_Output(&mappedOutputDouble, &entry, sizeof(entry));
//	}
//
//	void TheMapperIsInitialized()
//	{
//		init_AddTimeStamp_InputToOutputMapper(
//			&subject,
//			&dataInputDouble.interface,
//			&mappedOutputDouble.interface);
//	}
//
//	void TheMapperIsMappedWithTimeStampOf(uint32_t timeStamp)
//	{
//		Map_InputToOutputMapper(&subject.interface, &timeStamp);
//	}
//
//	void TheDataToBeReadFromInputIs(uint32_t data)
//	{
//		ChangeData_double_Input(&dataInputDouble, &data);
//	}
//
//	void TheOutputDataShouldHaveTimeStampOf(uint32_t expectedTimeStamp)
//	{
//		CHECK_EQUAL(expectedTimeStamp, entry.timeStamp);
//	}
//
//	void TheOutputDataShouldHaveDataOf(uint32_t expectedAltitude)
//	{
//		CHECK_EQUAL(expectedAltitude, entry.altitude);
//	}
//};
//TEST(AddTimeStamp_InputToOutputMapper_test, shouldMapInput)	{
//	Given TheMapperIsInitialized();
//	And TheDataToBeReadFromInputIs(ArbitraryData);
//	And TheMapperIsMappedWithTimeStampOf(ArbitraryTimeStamp);
//
//	Thus TheOutputDataShouldHaveDataOf(ArbitraryData);
//	And TheOutputDataShouldHaveTimeStampOf(ArbitraryTimeStamp);
//}
//
