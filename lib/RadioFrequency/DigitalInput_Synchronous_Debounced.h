/*
 * Input_Synchronous_Debounced_U16 Header File
 *
 * Description Synchronous solution to debouncing
 *
 * Written by JamApps
 */

#ifndef DigitalInput_Synchronous_Debounced_U16
#define DigitalInput_Synchronous_Debounced_U16

#include "i_DigitalInput.h"
#include "utilities.h"
#include "Percentage.h"

typedef struct
{
	ty_i_DigitalInput interface;

	struct
	{
		ty_i_DigitalInput inputToDebounce;

		void *debounceArray;
		uint16_t debounceArraySize;
		ty_Percentage onOffBoundary;
		uint16_t totalCounts;
		ty_Percentage average;
	} priv;
} ty_DigitalInput_Synchronous_Debounced;

void init_DigitalInput_Synchronous_Debounced(
		ty_DigitalInput_Synchronous_Debounced *subject,
		ty_i_Input *inputToAdapt,
		uint16_t debounceArraySize,
		ty_Percentage onOffBoundary);

#endif
