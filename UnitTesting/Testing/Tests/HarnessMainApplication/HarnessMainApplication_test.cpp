/*
 * Description tests the harness main application
 *
 * Written by JamApps
 */

extern "C" {
#include "HarnessMainApplication.h"
}
#include "CppUTest/TestHarness.h"
#include "double_DigitalInput.h"
#include "double_DigitalOutput.h"
#include "double_Output.h"

#define Given
#define Then
#define Thus
#define And

TEST_GROUP(HarnessMainApplication_test)
{
	ty_HarnessMainApplication subject;

	ty_double_DigitalInput startButtonInputDouble;

	ty_double_DigitalInput leftHookClippedInputDouble;
	ty_double_DigitalInput rightHookClippedInputDouble;

	ty_double_DigitalInput leftHookRfidInRangeInputDouble;
	ty_double_DigitalInput rightHookRfidInRangeInputDouble;

	ty_double_DigitalInput altitudeGreaterThan6FeetInputDouble;
	ty_double_DigitalInput hasFallenInputDouble;

	ty_double_DigitalOutput buzzerQuickBeepOutputDouble;
	ty_double_DigitalOutput buzzerContinuousBeepOutputDouble;

	ty_double_Output reportOutput;

	void setup() {
		init_double_DigitalInput(&startButtonInputDouble);

		init_double_DigitalInput(&leftHookClippedInputDouble);
		init_double_DigitalInput(&rightHookClippedInputDouble);

		init_double_DigitalInput(&leftHookRfidInRangeInputDouble);
		init_double_DigitalInput(&rightHookRfidInRangeInputDouble);

		init_double_DigitalInput(&altitudeGreaterThan6FeetInputDouble);
		init_double_DigitalInput(&hasFallenInputDouble);

		init_double_DigitalOutput(&buzzerQuickBeepOutputDouble);
		init_double_DigitalOutput(&buzzerContinuousBeepOutputDouble);

		init_double_Output(&reportOutput);
	}

	void TheHarnessHasBeenInitialized() {
		init_HarnessMainApplication(
				&subject,
				&startButtonInputDouble.interface,
				&leftHookClippedInputDouble.interface,
				&rightHookClippedInputDouble.interface,
				&leftHookRfidInRangeInputDouble.interface,
				&rightHookRfidInRangeInputDouble.interface,
				&altitudeGreaterThan6FeetInputDouble.interface,
				&hasFallenInputDouble.interface,
				&buzzerQuickBeepOutputDouble.interface,
				&buzzerContinuousBeepOutputDouble.interface,
				&reportOutput.interface);
	}

};

TEST(HarnessMainApplication_test, ShouldInit) {
	Given TheHarnessHasBeenInitialized();
}
