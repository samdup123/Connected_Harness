/*
 * AddTimeStamp_InputToOutputMapper implementation
 *
 *
 * Written by JamApps
 */

#include "AddTimeStamp_InputToOutputMapper.h"
#include "AltitudeAnalysisArray.h"
#include "utilities.h"

static ty_entry_AltitudeAnalysisArray entry;

static void Map(void *subj, const void *addition)
{
	RECAST(subject, subj, ty_AddTimeStamp_InputToOutputMapper *);
	RECAST(timeStamp, addition, uint32_t *);

	Read_Input(subject->priv.input, &entry.altitude);
	entry.timeStamp = *timeStamp;

	Write_Output(subject->priv.output, &entry);
}

static const ty_i_api_InputToOutputMapper api = { Map };

void init_AddTimeStamp_InputToOutputMapper(
		ty_AddTimeStamp_InputToOutputMapper *subject,
		ty_i_Input *input,
		ty_i_Output *output)
{
	subject->interface.api = &api;
	subject->priv.input = input;
	subject->priv.output = output;
}
