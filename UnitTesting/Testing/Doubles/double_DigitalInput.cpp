/*
 * double_DigitalInput Implementation
 *
 * Written by JamApps
 */

#include "double_DigitalInput.h"
#include "utilities.h"

bool Read(void *subj) {
	RECAST(subject, subj, ty_double_DigitalInput *);
	return subject->priv.state;
}

static const ty_i_api_DigitalInput api = { Read };

void init_double_DigitalInput(ty_double_DigitalInput *subject) {
	subject->interface.api = &api;
	subject->priv.state = false;
}

void ChangeState_double_DigitalInput(ty_double_DigitalInput *subject, bool state)
{
	subject->priv.state = state;
}
