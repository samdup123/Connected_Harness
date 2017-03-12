/*
 * Description
 *
 * Written by JamApps
 */

extern "C" {
#include <stdio.h>
#include "DigitalInput_GpioGroupAdapter.h"
#include "utilities.h"
}
#include "CppUTest/TestHarness.h"

#include "d_GpioGroup.h"

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

TEST_GROUP(DigitalInput_GpioGroupAdapter_test) {

	ty_DigitalInput_GpioGroupAdapter instance;
	ty_double_GpioGroup gpioGoupDouble;

	void setup()
	{
		static bool gpioGroupTestDoubleChannels[2];
		init_double_GpioGroup(&gpioGoupDouble, gpioGroupTestDoubleChannels);
	}

	void TheModuleHasBeenInitializedWith(ty_Channel_GpioGroup channel)
	{
		init_DigitalInput_GpioGroupAdapter(&instance, &gpioGoupDouble.interface, channel);
	}

	void TheModuleShouldRead(bool expectedState)
	{
		CHECK_EQUAL(expectedState, Read_DigitalInput(&instance.interface));
	}

	void TheGpioGroupWrites(ty_Channel_GpioGroup channel, bool state)
	{
		Write_GpioGroup(&gpioGoupDouble.interface, channel, state);
	}
};

TEST(DigitalInput_GpioGroupAdapter_test, ShouldInit) {
	Given TheModuleHasBeenInitializedWith(Channel1);
}

TEST(DigitalInput_GpioGroupAdapter_test, ShouldReadLowValueCorrectly) {
	Given TheModuleHasBeenInitializedWith(Channel1);
	Then TheGpioGroupWrites(Channel1, ON);

	Thus TheModuleShouldRead(ON);
}

TEST(DigitalInput_GpioGroupAdapter_test, ShouldReadHighValueCorrectly) {
	Given TheModuleHasBeenInitializedWith(Channel1);
	Then TheGpioGroupWrites(Channel1, OFF);

	Thus TheModuleShouldRead(OFF);
}

TEST(DigitalInput_GpioGroupAdapter_test, ShouldReadFromDifferentChannel) {
	Given TheModuleHasBeenInitializedWith(Channel2);
	Then TheGpioGroupWrites(Channel2, OFF);

	Thus TheModuleShouldRead(OFF);
}

TEST(DigitalInput_GpioGroupAdapter_test, ShouldReadAlternatingValues) {
	Given TheModuleHasBeenInitializedWith(Channel1);
	Then TheGpioGroupWrites(Channel1, OFF);

	Thus TheModuleShouldRead(OFF);

	Then TheGpioGroupWrites(Channel1, ON);

	Thus TheModuleShouldRead(ON);
}
