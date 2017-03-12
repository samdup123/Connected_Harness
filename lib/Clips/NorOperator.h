/*
 * NorOperator Header File
 *
 * Description Takes two digital inputs and provides a digital output
 *
 * Output returns true if and only if both inputs are read as false
 *
 * Written by JamApps
 */

#ifndef NorOperator
#define NorOperator

#include "i_DigitalInput.h"

typedef struct
{
	ty_i_DigitalInput externalInput;
	struct
	{
		ty_i_DigitalInput *leftInput;
		ty_i_DigitalInput *rightInput;
	} priv;
} ty_NorOperator;

void init_NorOperator(
		ty_NorOperator *subj,
		ty_i_DigitalInput *leftInput,
		ty_i_DigitalInput *rightInput);
#endif
