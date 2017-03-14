/*
 * StateMachine implementation
 *
 *
 * Written by JamApps
 */

#include "StateMachine.h"

enum
{
	SIGNAL_ENTRY,
	SIGNAL_EXIT,
};

void init_StateMachine(
		ty_StateMachine *subject,
		ty_State_StateMachine initialState,
		void *context)
{
	subject->priv.currentState = initialState;

	subject->priv.currentState(context, SIGNAL_ENTRY);
}

void SendSignal_StateMachine(
		ty_StateMachine *subject,
		ty_Signal_StateMachine signal,
		void *context)
{
	subject->priv.currentState(context, signal);
}

void Transition_StateMachine(
		ty_StateMachine *subject,
		ty_State_StateMachine newState,
		void *context)
{
	subject->priv.currentState(context, SIGNAL_EXIT);
	subject->priv.currentState = newState;
	subject->priv.currentState(context, SIGNAL_ENTRY);
}
