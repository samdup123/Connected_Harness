/*
 * Input_Synchronous_Debounced_U16 implementation
 *
 *
 * Written by JamApps
 */

#include "DigitalInput_Synchronous_Debounced.h"

enum
{
	OneHundredPercent = 100
};

static void ShiftDebounceArray(
		ty_DigitalInput_Synchronous_Debounced *subject,
		bool newValue)
{
	subject->priv.totalCounts = 0;
	for(uint8_t index = 1; index < subject->priv.debounceArraySize; index ++)
	{
		subject->priv.totalCounts += subject->priv.debounceArray[index];
		subject->priv.debounceArray[index - 1] = subject->priv.debounceArray[index];

	}
	subject->priv.totalCounts += newValue;
	subject->priv.debounceArray[subject->priv.debounceArraySize - 1] = newValue;

	subject->priv.average = ( (float)(subject->priv.totalCounts) / (float)(subject->priv.debounceArraySize) * OneHundredPercent);
}

static bool Read(void *subj)
{
	RECAST(subject, subj, ty_DigitalInput_Synchronous_Debounced *);
	bool newValue = Read_DigitalInput(&subject->priv.inputToDebounce);
	ShiftDebounceArray(subject, newValue);

	return subject->priv.average >= subject->priv.onOffBoundary;
}

static const ty_i_api_DigitalInput api = { Read };

void init_DigitalInput_Synchronous_Debounced(
		ty_DigitalInput_Synchronous_Debounced *subject,
		ty_i_Input *inputToAdapt,
		uint16_t debounceArraySize,
		ty_Percentage onOffBoundary)
{
	subject->interface.api = &api;

	subject->priv.debounceArraySize = debounceArraySize;
	static bool debounceArray[debounceArraySize];
	memset(debounceArray, 0, sizeof(debounceArraySize));
	subject->priv.debounceArray = debounceArray;
	subject->priv.onOffBoundary = onOffBoundary;
}
