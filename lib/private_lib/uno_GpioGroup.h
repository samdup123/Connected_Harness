/*
 * uno_GpioGroup Header File
 *
 * Description board specific gpio
 *
 * Written by JamApps
 */

#ifndef uno_GpioGroup
#define uno_GpioGroup

#include "i_GpioGroup.h"

enum
{
	uno_DigitalPin_NonPwm_2 = 2,
	uno_DigitalPin_NonPwm_4 = 4,
	uno_DigitalPin_NonPwm_8 = 8,
	uno_DigitalPin_NonPwm_12 = 12,
	uno_DigitalPin_NonPwm_13 = 13
};

ty_i_GpioGroup* init_uno_GpioGroup(void);

#endif


