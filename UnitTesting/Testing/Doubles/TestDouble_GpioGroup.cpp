/*
 * TestDouble_GpioGroup Implementation
 *
 * Written by JamApps
 */

#include "TestDouble_GpioGroup.h"

init_TestDouble_GpioGroup(
		ty_TestDouble_GpioGroup *subject,
		bool *channels,
		uint8_t numberOfChannels)
{
	subject->priv.channels = channels;
	subject->priv.numberOfChannels = numberOfChannels;
}
