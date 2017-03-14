/*
 * StateMachine Header File
 *
 * Description
 *
 * Written by JamApps
 */

#ifndef StateMachine
#define StateMachine

#include <stdint.h>

typedef uint8_t ty_Signal_StateMachine;

typedef void (*ty_State_StateMachine)(void *context, ty_Signal_StateMachine signal);

typedef struct
{
	struct
	{
		ty_State_StateMachine currentState;
	} priv;
} ty_StateMachine;

void init_StateMachine(
		ty_StateMachine *subject,
		ty_State_StateMachine initialState,
		void *context);

void SendSignal_StateMachine(
		ty_StateMachine *subject,
		ty_Signal_StateMachine signal,
		void *context);

void Transition_StateMachine(
		ty_StateMachine *subject,
		ty_State_StateMachine newState,
		void *context);

#endif
