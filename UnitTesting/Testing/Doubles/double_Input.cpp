/*
 * double_Input Implementation
 *
 * Written by JamApps
 */

#include "double_Input.h"
#include "utilities.h"

void Read(void *subj, void *data) {
	RECAST(subject, subj, ty_double_Input *);
	memcpy(data, subject->priv.data, subject->priv.sizeOfData);
}

static const ty_i_api_Input api = { Read };

void init_double_Input(ty_double_Input *subject, void *data, uint8_t sizeOfData) {
	subject->interface.api = &api;
	subject->priv.data = data;
	subject->priv.sizeOfData = sizeOfData;
}

void ChangeData_double_Input(ty_double_Input *subject, void *newData)
{
	memcpy(subject->priv.data, newData, subject->priv.sizeOfData);
}
