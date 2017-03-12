/*
 * double_GpioGroup Header File
 *
 *
 * Written by JamApps
 */

#ifndef Double_GpioGroup
#define Double_GpioGroup

#include "i_GpioGroup.h"

typedef struct
{
	ty_i_GpioGroup interface;

	struct
	{
		bool *channels;
	} priv;
} ty_double_GpioGroup;

void init_double_GpioGroup(
		ty_double_GpioGroup *subject,
		bool *channels);

#endif
