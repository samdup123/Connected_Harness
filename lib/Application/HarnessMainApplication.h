/*
 * HarnessMainApplication Header File
 *
 * Description this application does the main operation of the harness
 *
 * Written by JamApps
 */

#ifndef HarnessMainApplication
#define HarnessMainApplication

#include "i_DigitalInput.h"
#include "i_DigitalOutput.h"
#include "i_Output.h"
#include "NorOperator.h"
#include "StateMachine.h"

typedef struct
{
	struct
	{
		ty_StateMachine mainStateMachine;
		ty_NorOperator clipsNorOperator;

		ty_i_DigitalOutput buzzerQuickBeep;
	} priv;
} ty_HarnessMainApplication;

void init_HarnessMainApplication(
		ty_HarnessMainApplication *subject,
		ty_i_DigitalInput *startButtonInput,
		ty_i_DigitalInput *leftHookClippedInput,
		ty_i_DigitalInput *rightHookClippedInput,
		ty_i_DigitalInput *leftHookRfidInRangeInput,
		ty_i_DigitalInput *rightHookRfidInRangeInput,
		ty_i_DigitalInput *altitudeGreaterThan6FeetInput,
		ty_i_DigitalInput *hasFallenInput,
		ty_i_DigitalOutput *buzzerQuickBeep,
		ty_i_DigitalOutput *buzzerContinuousBeep,
		ty_i_Output *reportOutput);

void Operate_HarnessMainApplication(ty_HarnessMainApplication *subject);


#endif
