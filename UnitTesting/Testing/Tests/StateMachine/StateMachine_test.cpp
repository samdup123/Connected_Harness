/*
 * Description Tests the state machine
 *
 * Written by JamApps
 */

extern "C" {
#include "StateMachine.h"
}
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#define Given
#define Then
#define Thus
#define And

enum
{
	SIGNAL_ENTRY, SIGNAL_EXIT, SIGNAL_ANOTHER_SIGNAL
};

TEST_GROUP(StateMachine_test)
{
	ty_StateMachine subject;

	static void State_1(void *context, ty_Signal_StateMachine signal) {
		mock().actualCall("Signal").withParameter("signal", signal);
	}

	static void State_2(void *context, ty_Signal_StateMachine signal) {
		mock().actualCall("Signal").withParameter("signal", signal);
	}

	void TheStateMachineIsInitializedWith(ty_State_StateMachine state) {
		init_StateMachine(&subject, state, NULL);
	}

	void ExpectStateToBeToBeCalledWithSignal(ty_Signal_StateMachine signal) {
		mock().expectOneCall("Signal").withParameter("signal", signal);
	}

	void TheSignalIsSent(ty_Signal_StateMachine signal) {
		SendSignal_StateMachine(&subject, signal, NULL);
	}

	void TheStateMachineTransitionsTo(ty_State_StateMachine state) {
		Transition_StateMachine(&subject, state, NULL);
	}

};

TEST(StateMachine_test, ShouldInit) {
	ExpectStateToBeToBeCalledWithSignal(SIGNAL_ENTRY);
	Given TheStateMachineIsInitializedWith(State_1);
}

TEST(StateMachine_test, ShouldBeAbleToSend) {
	ExpectStateToBeToBeCalledWithSignal(SIGNAL_ENTRY);
	Given TheStateMachineIsInitializedWith(State_1);
	ExpectStateToBeToBeCalledWithSignal(SIGNAL_ANOTHER_SIGNAL);
	And TheSignalIsSent(SIGNAL_ANOTHER_SIGNAL);
}

TEST(StateMachine_test, ) {
	ExpectStateToBeToBeCalledWithSignal(SIGNAL_ENTRY);
	Given TheStateMachineIsInitializedWith(State_1);

	ExpectStateToBeToBeCalledWithSignal(SIGNAL_EXIT);
	ExpectStateToBeToBeCalledWithSignal(SIGNAL_ENTRY);
	TheStateMachineTransitionsTo(State_2);
}



