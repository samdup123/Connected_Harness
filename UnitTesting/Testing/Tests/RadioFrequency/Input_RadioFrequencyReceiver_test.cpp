/*
 * Description
 *
 * Written by JamApps
 */

extern "C" {
#include "i_DigitalInput.h"
}
#include "CppUTest/TestHarness.h"
#include "Input_RadioFrequencyReceiver.h"

#define Given
#define Then
#define Thus
#define And

TEST_GROUP(Input_RadioFrequencyReceiver_test)
{
	ty_Input_RadioFrequencyReciever subject;

	void TheRFInputHasBeenInitialized()
	{
		init_Input_RadioFrequencyReceiver(&subject);
	}
};

TEST(Input_RadioFrequencyReceiver_test, ShouldInit)	{
	Given TheRFInputHasBeenInitialized();
	bool state = Read_DigitalInput(&subject.interface);
	CHECK_EQUAL(true, state);
}
