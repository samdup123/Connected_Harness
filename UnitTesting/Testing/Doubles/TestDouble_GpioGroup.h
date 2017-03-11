/*
 * TestDouble_GpioGroup Header File
 *
 * Description
 *
 * Written by JamApps
 */

#ifndef TestDouble_GpioGroup
#define TestDouble_GpioGroup

#include <stdint.h>
#include "i_GpioGroup.h"


typedef struct
{
	ty_i_GpioGroup interface;

	struct
	{
		bool *channels;
		uint8_t numberOfChannels;
	} priv;
} ty_TestDouble_GpioGroup;

init_TestDouble_GpioGroup(
		ty_TestDouble_GpioGroup *subject,
		bool *channels,
		uint8_t numberOfChannels);
#endif
