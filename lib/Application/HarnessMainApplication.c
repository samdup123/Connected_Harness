/*
 * HarnessMainApplication implementation
 *
 *
 * Written by JamApps
 */

#include "HarnessMainApplication.h"
#include "utilities.h"

enum
{
	SIGNAL_ENTRY, SIGNAL_EXIT, SIGNAL_STARTBUTTONPUSHED,
};

static void State_NotClimbing(void *context, ty_Signal_StateMachine signal);

static void State_NotClimbing(void *context, ty_Signal_StateMachine signal) {
	RECAST(subject, context, ty_HarnessMainApplication *);

	switch (signal) {

	case SIGNAL_STARTBUTTONPUSHED:
		break;
	}
}

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
		ty_i_Output *reportOutput) {

	init_StateMachine(subject->priv.mainStateMachine, State_NotClimbing, subject);
	subject->priv.buzzerQuickBeep = buzzerQuickBeep;
}
