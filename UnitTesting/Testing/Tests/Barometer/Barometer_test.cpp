/*
 * Description Tests the barometer
 *
 * Written by JamApps
 */

extern "C" {
#include "Barometer.h"
#include <stdio.h>
}
#include "CppUTest/TestHarness.h"
#include "double_Input.h"

#define Given
#define Then
#define Thus
#define And

#define Milliseconds

enum
{
	ZeroFeet = 0,
	TenFeetHigh = 10
};

TEST_GROUP(Barometer_test)
{
	ty_Barometer subject;

	ty_BarometerAltitudeEntry entry;
	ty_double_Input altimeterInputDouble;

	void setup()
	{
		init_double_Input(&altimeterInputDouble, &entry, sizeof(entry));
	}

	void TheBarometerHasBeenInitialized()
	{
		init_Barometer(&subject, &altimeterInputDouble.interface);
	}

	void TheAverageAltitudeShouldBe(ty_Feet expectedAverageAltitude)
	{
		ty_Feet actualAverageAltitude;
		Read_Input(&subject.averageAltitudeInterface, &actualAverageAltitude);
		CHECK_EQUAL(expectedAverageAltitude, actualAverageAltitude);
	}

	void TheBarometerIs(ty_Feet altitude)
	{
		ChangeData_double_Input(&altimeterInputDouble, &altitude);
	}

	void TheBarometerIsReadWithTimeStampOf(ty_TimeStamp timeStamp)
	{
		CaptureAltitudeEntry_Barometer(&subject, timeStamp);
	}

	void TheAverageAltitudeShouldBeAboveZero()
	{
		ty_Feet averageAltitude;
		Read_Input(&subject.averageAltitudeInterface, &averageAltitude);
		CHECK(averageAltitude > 0);
	}
};

TEST(Barometer_test, ShouldHaveAverageAltitudeOfZeroUponInitialization)	{
	Given TheBarometerHasBeenInitialized();

	TheAverageAltitudeShouldBe(ZeroFeet);
}

TEST(Barometer_test, ShouldHaveCorrectAverageAltitude)	{
	Given TheBarometerHasBeenInitialized();
	And TheBarometerIs(TenFeetHigh);
	And TheBarometerIsReadWithTimeStampOf(0 Milliseconds);
}
