/*
 * double_Output Implementation
 *
 * Written by JamApps
 */

#include "double_Output.h"
#include "utilities.h"

void Write(void *subj, void *data) {
	RECAST(subject, subj, ty_double_Output *);
	subject->priv.data = data;
}

static const ty_i_api_Output api = { Write };

void init_double_Output(ty_double_Output *subject) {
	subject->interface.api = &api;
}

void ChangeData_double_Output(ty_double_Output *subject, void *data)
{
	subject->priv.data = data;
}
