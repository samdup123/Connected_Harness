extern "C"
{
#include "DigitalOutput_GpioGroupAdapter.h"
}
#include "CppUTest/TestHarness.h"

TEST_GROUP(ExampleTest)
{
	ty_DigitalOutput_GpioGroupAdapter subject;
	void setup()
	{
	}

};

TEST(ExampleTest, Fail)
{
	FAIL("fail");
}
