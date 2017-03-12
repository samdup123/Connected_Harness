/*
 * NorOperator Implementation
 *
 * Written by JamApps
 */

#include "NorOperator.h"
#include "utilities.h"

bool Read(void *subj) {
	RECAST(subject, subj, ty_NorOperator *);
	bool leftState = Read_DigitalInput(subject->priv.leftInput);
	bool rightState = Read_DigitalInput(subject->priv.rightInput);

	return !leftState && !rightState;
//	(void)subject;
//	(void)leftState;
//	return false;
}

static const ty_i_api_DigitalInput api = { Read };

void init_NorOperator(
		ty_NorOperator *subject,
		ty_i_DigitalInput *leftInput,
		ty_i_DigitalInput *rightInput) {

	subject->priv.leftInput = leftInput;
	subject->priv.rightInput = rightInput;

	subject->externalInput.api = &api;
}
