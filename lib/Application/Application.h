/*
 * Application Header File
 *
 * Description The Application
 *
 * Written by JamApps
 */

#ifndef Application
#define Application

#include "Nano_Accelerometer.h"

typedef struct{
	struct
	{
		ty_Nano_Accelerometer accelerometer;
		ty_DigitalInput_GpioGroupAdapter accelerometerMessageAdaptedInput;
		ty_DigitalOutput_GpioGroupAdapter accelerometerMessageAcceptanceAdaptedOutput;
		ty_DigitalOutput_GpioGroupAdapter buzzerAdpatedOutput;
	} priv;
} ty_Application;

void init_Application(
		ty_Application *subject,
		ty_i_GpioGroup gpioGroup);

#endif
