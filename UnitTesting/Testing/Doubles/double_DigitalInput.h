/*
 * double_DigitalInput Header File
 *
 * Description double for digital input
 *
 * Written by JamApps
 */

#ifndef double_DigitalInput
#define double_DigitalInput

#include "i_DigitalInput.h"

typedef struct
{
	ty_i_DigitalInput interface;

	struct
	{
		bool state;
	} priv;
} ty_double_DigitalInput;

void init_double_DigitalInput(ty_double_DigitalInput *subject);
void ChangeState_double_DigitalInput(ty_double_DigitalInput *subject, bool state);
#endif
