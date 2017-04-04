/*
 * double_Output Implementation
 *
 * Written by JamApps
 */

#include "double_Output.h"
#include "utilities.h"

void Write(void *subj, void *data) {
	RECAST(subject, subj, ty_double_Output *);
	memcpy(subject->priv.data, data, subject->priv.sizeOfData);
}

static const ty_i_api_Output api = { Write };

void init_double_Output(ty_double_Output *subject, void * data, uint8_t sizeOfData) {
	subject->interface.api = &api;
	subject->priv.data = data;
	subject->priv.sizeOfData = sizeOfData;
}

void * CheckData_double_Output(ty_double_Output *subject)
{
	return subject->priv.data;
}
