/*
 * Description
 *
 * Written by JamApps
 */

extern "C" {
#include <stdio.h>
#include "DigitalOutput_GpioGroupAdapter.h"
#include "utilities.h"
}
#include "CppUTest/TestHarness.h"
#include "double_GpioGroup.h"

#define Given
#define When
#define Then
#define And
#define Thus

enum
{
	Channel1,
	Channel2
};

TEST_GROUP(DigitalOutput_GpioGroupAdapter_test) {

	ty_DigitalOutput_GpioGroupAdapter instance;
	ty_double_GpioGroup gpioGoupDouble;

	void setup()
	{
		static bool gpioGroupTestDoubleChannels[2];
		init_double_GpioGroup(&gpioGoupDouble, gpioGroupTestDoubleChannels);
	}

	void TheModuleHasBeenInitializedWith(ty_Channel_GpioGroup channel)
	{
		init_DigitalOutput_GpioGroupAdapter(&instance, &gpioGoupDouble.interface, channel);
	}

	void TheModuleWrites(bool state)
	{
		Write_DigitalOutput(&instance.interface, state);
	}

	void TheGpioGroupShouldRead(ty_Channel_GpioGroup channel, bool expectedState)
	{
		CHECK_EQUAL(expectedState, Read_GpioGroup(&gpioGoupDouble.interface, channel));
	}
};

TEST(DigitalOutput_GpioGroupAdapter_test, ShouldInit) {
	Given TheModuleHasBeenInitializedWith(Channel1);
}

TEST(DigitalOutput_GpioGroupAdapter_test, ShouldBeAbleToWriteOn) {
	Given TheModuleHasBeenInitializedWith(Channel1);
	TheModuleWrites(ON);

	Thus TheGpioGroupShouldRead(Channel1, ON);
}

TEST(DigitalOutput_GpioGroupAdapter_test, ShouldBeAbleToWriteOff) {
	Given TheModuleHasBeenInitializedWith(Channel1);
	TheModuleWrites(OFF);

	Thus TheGpioGroupShouldRead(Channel1, 0);
}

TEST(DigitalOutput_GpioGroupAdapter_test, ShouldBeAbleToWriteOffToADifferentChannel) {
	Given TheModuleHasBeenInitializedWith(Channel2);
	TheModuleWrites(OFF);

	Thus TheGpioGroupShouldRead(Channel2, OFF);
}

TEST(DigitalOutput_GpioGroupAdapter_test, ShouldBeAbleToWriteAlternatingValues) {
	Given TheModuleHasBeenInitializedWith(Channel1);
	TheModuleWrites(OFF);

	Thus TheGpioGroupShouldRead(Channel1, OFF);

	TheModuleWrites(ON);

	Thus TheGpioGroupShouldRead(Channel1, ON);
}
