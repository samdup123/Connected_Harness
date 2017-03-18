/*
 * Description Tests the synchronous debounced Digital input
 *
 * Written by JamApps
 */

extern "C" {
#include "DigitalInput_Synchronous_Debounced.h"
#include "utilities.h"
}
#include "CppUTest/TestHarness.h"
#include "double_DigitalInput.h"

#define Given
#define Then
#define Thus
#define And

enum
{
	Zeros = false, Ones = true
};

enum
{
	DebounceArraySize = 50
};

enum
{
	FiftyPercent = 50,
	FourtyNinePercent = 49,
	SixtyPercent = 60,
	NinetyNinePercent = 99
};

enum
{
	ALotOfTimes = 5000
};

TEST_GROUP(DigitalInput_Synchronous_Debounced_test)
{
	ty_DigitalInput_Synchronous_Debounced subject;
	ty_double_DigitalInput inputToBeDebouncedDouble;

	bool debounceArray[DebounceArraySize];

	void setup() {
		init_double_DigitalInput(&inputToBeDebouncedDouble);
	}

	void TheDebouncerIsInitializedWithBoundary(ty_Percentage onOffBoundary) {
		init_DigitalInput_Synchronous_Debounced(&subject,
				&inputToBeDebouncedDouble.interface, debounceArray,
				DebounceArraySize, onOffBoundary);
	}

	void TheInputToBeDebouncedReadsAs(bool state) {
		ChangeState_double_DigitalInput(&inputToBeDebouncedDouble, state);
	}

	void TheDebouncerShouldRead(bool expectedState) {
		CHECK_EQUAL(expectedState, Read_DigitalInput(&subject.interface));
	}

	void TheDebouncerShouldReadOffThisManyTimes(const uint16_t times) {
		for (uint16_t counter = 0; counter < times; counter++) {
			TheDebouncerShouldRead(OFF);
		}
	}

	void TheDebouncedArrayShouldBeRoughly50PercentOnesAndTheDebouncerShouldReadLogicLow() {
		// the array should look like this { 1, 0, 1, 0, 1, 0 ...
		// the ratio of of ones to zeros should be almost exactly 1:1
		// in other words there should almost exactly 50% ones
		// but if you have an odd sized array then the ratio will climb a little above 50
		bool state = OFF;
		for (uint16_t counter = 0; counter < ALotOfTimes; counter++) {
			TheInputToBeDebouncedReadsAs(state);
			state = !state;
			TheDebouncerShouldRead(OFF);
		}
	}

	void TheDebounceArrayShouldBeAll(bool expectedState) {
		for (uint16_t index = 0; index < DebounceArraySize; index++) {
			CHECK_EQUAL(expectedState, debounceArray[index]);
		}
	}

	void TheDebounceArrayIsAll(bool state) {
		for (uint16_t index = 0; index < DebounceArraySize; index++) {
			debounceArray[index] = state;
		}
	}

	void TheDebounceArrayIsHalfFullOfOnes() {
		// forces the debounce array to look like this { 1, 0, 1, 0, 1, 0 ...
		// if you have an odd array length the ratio of one's to zero's should be a little off 1:1
		bool state = 0;
		for (uint16_t index = 0; index < DebounceArraySize; index++) {
			debounceArray[index] = state;
			state = !state;
		}
	}

	void TheDebounceArrayHaveOnly1Zero() {
		// forces the debounce array to look like this { *0*, 1, 1, 1, 1, ...
		// if you have an odd array length the ratio of one's to zero's should be a little off 1:1
		for (uint16_t index = 1; index < DebounceArraySize; index++) {
			debounceArray[index] = true;
		}
	}

	void TheOnOffBoundaryIsChangedTo(ty_Percentage boundary) {
		ChangeBoundary_DigitalInput_Synchronous_Debounced(&subject, boundary);
	}
};

TEST(DigitalInput_Synchronous_Debounced_test, ShouldInit) {
	TheDebouncerIsInitializedWithBoundary(FiftyPercent);
}

TEST(DigitalInput_Synchronous_Debounced_test, ShouldReadOffIfOnlyOffsAreReadInToTheInputToBeDebounced) {
	Given TheDebouncerIsInitializedWithBoundary(FiftyPercent);
	And TheInputToBeDebouncedReadsAs(OFF);
	TheDebouncerShouldReadOffThisManyTimes(ALotOfTimes);
	TheDebounceArrayShouldBeAll(Zeros);
}

TEST(DigitalInput_Synchronous_Debounced_test, ShouldReadOnIfTheDebounceArrayIsFullOfOnes) {
	Given TheDebouncerIsInitializedWithBoundary(FiftyPercent);
	And TheDebounceArrayIsAll(Ones);
	TheDebouncerShouldRead(ON);
}

TEST(DigitalInput_Synchronous_Debounced_test, ShouldReadOffIfNotEnoughOnsAreReadToTheOnOffBoundaryPercent) {
	Given TheDebouncerIsInitializedWithBoundary(SixtyPercent);
	TheDebouncedArrayShouldBeRoughly50PercentOnesAndTheDebouncerShouldReadLogicLow();
}

TEST(DigitalInput_Synchronous_Debounced_test, ShouldReadOnIfTheRatioOfOnesIsJustOverTheBoundary) {
	// this test might fail if you have a odd array length
	Given TheDebouncerIsInitializedWithBoundary(FourtyNinePercent);
	And TheDebounceArrayIsHalfFullOfOnes();
	And

	TheDebouncerShouldRead(ON);
}

TEST(DigitalInput_Synchronous_Debounced_test, ShouldReadOffIfTheRatioOfOnesIsRightAtTheBoundary) {
	// this test might fail if you have a odd array length
	Given TheDebouncerIsInitializedWithBoundary(FiftyPercent);
	And TheDebounceArrayIsHalfFullOfOnes();

	TheDebouncerShouldRead(ON);
}

TEST(DigitalInput_Synchronous_Debounced_test, ShouldCorrectlyChangeBoundary) {
	Given TheDebouncerIsInitializedWithBoundary(FiftyPercent);
	And TheDebounceArrayIsHalfFullOfOnes();

	TheDebouncerShouldRead(ON);
	// ^ this might fail is you have an odd array length

	Given TheOnOffBoundaryIsChangedTo(NinetyNinePercent);
	TheDebouncerShouldRead(OFF);

	Given TheInputToBeDebouncedReadsAs(OFF);
	Then TheDebounceArrayIsAll(Ones);
	// When the debouncer is read it should bring in another value from the input to be debounced
	// which will be zero and then it will fail the check below
	TheDebouncerShouldRead(OFF);

	Given TheInputToBeDebouncedReadsAs(ON);
	Then TheDebounceArrayIsAll(Ones);
	Thus TheDebouncerShouldRead(ON);
}

