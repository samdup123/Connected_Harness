/*
 * DigitalInput_Synchronous_Debounced Header File
 *
 * Description Synchronous solution to debouncing
 *
 * Written by JamApps
 */

#ifndef DigitalInput_Synchronous_Debounced
#define DigitalInput_Synchronous_Debounced

#include "i_DigitalInput.h"
#include "utilities.h"
#include "Percentage.h"

typedef uint16_t ty_size_DebounceArray;

typedef struct
{
	ty_i_DigitalInput interface;

	struct
	{
		ty_i_DigitalInput *inputToDebounce;

		bool *debounceArray;
		ty_size_DebounceArray debounceArraySize;
		ty_Percentage onOffBoundary;
		uint16_t totalCounts;
		ty_Percentage average;
	} priv;
} ty_DigitalInput_Synchronous_Debounced;

void init_DigitalInput_Synchronous_Debounced(
		ty_DigitalInput_Synchronous_Debounced *subject,
		ty_i_DigitalInput *inputToDebounce,
		bool *debounceArray,
		ty_size_DebounceArray debounceArraySize,
		ty_Percentage onOffBoundary);

void ChangeBoundary_DigitalInput_Synchronous_Debounced(
		ty_DigitalInput_Synchronous_Debounced *subject,
		ty_Percentage onOffBoundary);

#endif
