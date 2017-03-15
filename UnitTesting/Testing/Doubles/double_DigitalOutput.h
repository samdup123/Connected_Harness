/*
 * double_Digitaloutput Header File
 *
 * Description double for digital output
 *
 * Written by JamApps
 */

#ifndef double_DigitalOutput
#define double_Digitaluutput

#include "i_DigitalOutput.h"

typedef struct
{
	ty_i_DigitalOutput interface;

	struct
	{
		bool state;
	} priv;
} ty_double_DigitalOutput;

void init_double_DigitalOutput(ty_double_DigitalOutput *subject);
bool CheckState_double_DigitalOutput(ty_double_DigitalOutput *subject);
#endif
