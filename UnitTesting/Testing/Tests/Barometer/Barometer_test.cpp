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
#define Millisecond

enum
{
	ZeroFeet = 0,
	TenFeetHigh = 10,

	ALot = SIZE_OF_BAROMETER_ALTITUDE_ARRAY + 10
};

TEST_GROUP(Barometer_test)
{
	ty_Barometer subject;

	ty_Feet altitude;
	ty_double_Input altimeterInputDouble;

	void setup()
	{
		init_double_Input(&altimeterInputDouble, &altitude, sizeof(altitude));
	}

	void TheBarometerHasBeenInitialized()
	{
		init_Barometer(&subject, &altimeterInputDouble.interface);
	}

	void TheAverageAltitudeShouldBe(ty_Feet expectedAverageAltitude)
	{
		double actualAverageAltitude;
		Read_Input(&subject.averageAltitudeInterface, &actualAverageAltitude);
		CHECK_EQUAL(expectedAverageAltitude, actualAverageAltitude);
	}

	void TheBarometerIs(ty_Feet altitude)
	{
		ChangeData_double_Input(&altimeterInputDouble, &altitude);
	}

	void TheBarometerHasCurrentAltitudeOf(ty_Feet altitude)
	{
		TheBarometerIs(altitude);
	}

	void TheBarometerIsReadWithTimeStampOf(ty_TimeStamp timeStamp)
	{
		CaptureAltitudeEntry_Barometer(&subject, timeStamp);
	}

	void TimePassesWithTimeStep(uint32_t timeStep)
	{
		uint32_t time = 1;
		for(uint8_t i = 0; i < ALot; i++)
		{
			TheBarometerIsReadWithTimeStampOf(time);
			time += timeStep;
		}
	}

	void TheBarometerIsMovingDownAtVelocity(double velocity)
	{
		uint32_t time = 0;
		ty_Feet altitude = SIZE_OF_BAROMETER_ALTITUDE_ARRAY * velocity * 2;

		for(uint8_t i = 0; i < ALot; i++)
		{
			time++;
			altitude -= velocity;
			TheBarometerHasCurrentAltitudeOf(altitude);
			TheBarometerIsReadWithTimeStampOf(time);
		}
	}

	void TheDownwardVelocityShouldBe(double expectedVelocity)
	{
		double actualVelocity;
		Read_Input(&subject.downwardVelocityInterface, &actualVelocity);
		CHECK_EQUAL(expectedVelocity, actualVelocity);
	}
};

TEST(Barometer_test, ShouldHaveAverageAltitudeOfZeroUponInitialization)	{
	Given TheBarometerHasBeenInitialized();

	TheAverageAltitudeShouldBe(ZeroFeet);
}

TEST(Barometer_test, ShouldHaveCorrectAverageAltitude)	{
	Given TheBarometerHasBeenInitialized();
	And TheBarometerIs(TenFeetHigh);
	And TimePassesWithTimeStep(1 Millisecond);

	TheAverageAltitudeShouldBe(TenFeetHigh);
}

TEST(Barometer_test, ShouldHaveCorrentDownwardVelocity)
{
	Given TheBarometerHasBeenInitialized();
	And TheBarometerIsMovingDownAtVelocity(10);

	TheDownwardVelocityShouldBe(10);
}
