/*
 * Description Tests the Nor Operator
 *
 * Written by JamApps
 */

extern "C" {
#include "NorOperator.h"
#include "utilities.h"
}
#include "CppUTest/TestHarness.h"
#include "double_DigitalInput.h"

#define Given
#define Then
#define And
#define Thus

TEST_GROUP(NorOperator_test) {
	ty_NorOperator instance;
	ty_double_DigitalInput leftInput;
	ty_double_DigitalInput rightInput;

	void setup()
	{
		init_double_DigitalInput(&leftInput);
		init_double_DigitalInput(&rightInput);
	}

	void TheNorOperatorIsInitialized()
	{
		init_NorOperator(&instance, &leftInput.interface, &rightInput.interface);
	}

	void TheLeftInputReadsAs(bool state)
	{
		ChangeState_double_DigitalInput(&leftInput, state);
	}

	void TheRightInputReadsAs(bool state)
	{
		ChangeState_double_DigitalInput(&rightInput, state);
	}

	void TheNorOperatorShouldReadAs(bool expectedState)
	{
		bool actualState = instance.externalInput.api->Read(&instance.externalInput);
		CHECK_EQUAL(expectedState, actualState);
	}
};

TEST(NorOperator_test, ShouldInit) {
	TheNorOperatorIsInitialized();
}

TEST(NorOperator_test, ShouldReturnTrueIfBothInputsAreFalse) {
	Given TheNorOperatorIsInitialized();
	Then TheLeftInputReadsAs(OFF);
	And TheRightInputReadsAs(OFF);

	Thus TheNorOperatorShouldReadAs(ON);
}

TEST(NorOperator_test, ShouldReturnFalseIfLeftIsTrueAndLeftIsFalse)
{
	Given TheNorOperatorIsInitialized();
    Then TheLeftInputReadsAs(OFF);
    And TheRightInputReadsAs(ON);

    Thus TheNorOperatorShouldReadAs(OFF);
}

TEST(NorOperator_test, ShouldReturnFalseIfLeftIsFalseAndLeftIsTrue)
{
	Given TheNorOperatorIsInitialized();
    Then TheLeftInputReadsAs(ON);
    And TheRightInputReadsAs(OFF);

    Thus TheNorOperatorShouldReadAs(OFF);
}

TEST(NorOperator_test, ShouldReturnFalseBothAreTrue)
{
	Given TheNorOperatorIsInitialized();
    Then TheLeftInputReadsAs(ON);
    And TheRightInputReadsAs(ON);

    Thus TheNorOperatorShouldReadAs(OFF);
}
