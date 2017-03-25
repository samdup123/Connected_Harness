/*
 * double_DigitalOutput Implementation
 *
 * Written by JamApps
 */

#include "double_DigitalOutput.h"
#include "utilities.h"

void Write(void *subj, bool state) {
	RECAST(subject, subj, ty_double_DigitalOutput *);
	subject->priv.state = state;
}

static const ty_i_api_DigitalOutput api = { Write };

void init_double_DigitalOutput(ty_double_DigitalOutput *subject) {
	subject->interface.api = &api;
	subject->priv.state = false;
}

bool CheckState_double_DigitalOutput(ty_double_DigitalOutput *subject)
{
	return subject->priv.state;
}
