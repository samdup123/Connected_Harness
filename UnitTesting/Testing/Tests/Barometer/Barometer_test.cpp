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

enum
{
	Zero = 0,
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
};

TEST(Barometer_test, ShouldHaveAverageAltitudeOfZeroUponInitialization)	{
	Given TheBarometerHasBeenInitialized();

	TheAverageAltitudeShouldBe(Zero);
}
