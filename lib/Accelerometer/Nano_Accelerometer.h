/*
 * Nano_Accelerometer Header File
 *
 * Description driver for the nano-wrapped accleerometer
 *
 * Written by JamApps
 */

#ifndef Nano_Accelerometer
#define Nano_Accelerometer

#include "i_Accelerometer.h"
#include "i_DigitalOutput.h"
#include "i_DigitalInput.h"


typedef struct
{
	ty_i_Accelerometer interface;

	struct
	{
		bool hasFallen;

		ty_i_DigitalOutput *output;
		ty_i_DigitalInput *input;
	} priv;
} ty_Nano_Accelerometer;

void init_Nano_Accelerometer(
		ty_Nano_Accelerometer *subject,
		ty_i_DigitalOutput *output,
		ty_i_DigitalInput *input);


#endif
