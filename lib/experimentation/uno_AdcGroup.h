/*
 * uno_AdcGroup Header File
 *
 * Description The adc group specific to the uno
 *
 * Written by JamApps
 */

#ifndef uno_AdcGroup
#define uno_AdcGroup

#include "i_AdcGroup.h"
#include "Arduino.h"

enum
{
	uno_AnalogInputPin_0 = A0,
	uno_AnalogInputPin_1 = A1,
	uno_AnalogInputPin_2 = A2,
	uno_AnalogInputPin_3 = A3,
	uno_AnalogInputPin_4 = A4,
	uno_AnalogInputPin_5 = A5,

};

ty_i_AdcGroup* init_uno_AdcGroup(void);

#endif
