/*
 * Description
 *
 * Written by JamApps
 */

extern "C" {
#include "Nano_Accelerometer.h"
#include "utilities.h"
#include <stdbool.h>
}
#include "CppUTest/TestHarness.h"
#include "double_DigitalInput.h"
#include "double_DigitalOutput.h"

#define Given
#define Then
#define Thus
#define And

enum
{
	HasFallen = true,
	HasNotFallen = false
};

TEST_GROUP(Nano_Accelerometer_test)
{
	ty_Nano_Accelerometer subject;
	ty_double_DigitalInput input;
	ty_double_DigitalOutput output;

	void setup() {
		init_double_DigitalInput(&input);
		init_double_DigitalOutput(&output);
	}

	void TheAccelerometerIsInitialized() {
		init_Nano_Accelerometer(&subject, &output.interface, &input.interface);
	}

	void TheAccelerometerShouldNotSayThatItHasFallen() {
		CHECK_EQUAL(false, HasFallen_Accelerometer(&subject.interface));
	}

	void TheAccelerometerShouldSayThatItHasFallen() {
		CHECK_EQUAL(true, HasFallen_Accelerometer(&subject.interface));
	}

	void TheAccelerometerFallStateIs(bool state) {
		ChangeState_double_DigitalInput(&input, state);
	}

	void TheOutputShouldBeAtState(bool expectedState)
	{
		CHECK_EQUAL(expectedState, CheckState_double_DigitalOutput(&output));
	}
};

TEST(Nano_Accelerometer_test, ShouldInit) {
	Given TheAccelerometerIsInitialized();
}

TEST(Nano_Accelerometer_test, ShouldReturnFalseIfItHasntFallen) {
	Given TheAccelerometerIsInitialized();
	And TheAccelerometerFallStateIs(HasNotFallen);
	Thus TheAccelerometerShouldNotSayThatItHasFallen();
}

TEST(Nano_Accelerometer_test, ShouldReturnTrueIfTheInputIsEnabled) {
	Given TheAccelerometerIsInitialized();
	And TheAccelerometerFallStateIs(HasFallen);
	Thus TheAccelerometerShouldSayThatItHasFallen();
}

TEST(Nano_Accelerometer_test, ShouldEnableOutputIfItHasFallen) {
	Given TheAccelerometerIsInitialized();
	And TheAccelerometerFallStateIs(HasFallen);
	Thus TheAccelerometerShouldSayThatItHasFallen();

	Then TheOutputShouldBeAtState(ON);
}

TEST(Nano_Accelerometer_test, ShouldNotSayItHasFallenTwiceInARowIfItHasFallenOnce) {
	Given TheAccelerometerIsInitialized();
	And TheAccelerometerFallStateIs(HasFallen);
	Thus TheAccelerometerShouldSayThatItHasFallen();

	Then TheOutputShouldBeAtState(ON);

	And TheAccelerometerShouldNotSayThatItHasFallen();
}

TEST(Nano_Accelerometer_test, ShouldDisableOutputAfterItIsReadTwice) {
	Given TheAccelerometerIsInitialized();
	And TheAccelerometerFallStateIs(ON);
	Thus TheAccelerometerShouldSayThatItHasFallen();

	Then TheOutputShouldBeAtState(ON);

	And TheAccelerometerShouldNotSayThatItHasFallen();

	Then TheOutputShouldBeAtState(OFF);
}

TEST(Nano_Accelerometer_test, ShouldBeAbleToFallTwice) {
	Given TheAccelerometerIsInitialized();
	And TheAccelerometerFallStateIs(HasFallen);
	Thus TheAccelerometerShouldSayThatItHasFallen();

	And TheAccelerometerShouldNotSayThatItHasFallen();

	Then TheAccelerometerFallStateIs(HasFallen);

	Thus TheAccelerometerShouldSayThatItHasFallen();
}
