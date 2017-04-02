/*
 * Barometer implementation
 *
 *
 * Written by JamApps
 */

#include "Barometer.h"
#include "utilities.h"
#include <stdio.h>

void WriteAltitudeThreshold(void *subj, void *data)
{
	RECAST(subject, subj, ty_Barometer *);
	memcpy(&subject->priv.altitudeThreshold, data, sizeof(ty_Feet));
}

static const ty_i_api_Output altitudeThresholdOutputApi = { WriteAltitudeThreshold };


bool CheckIfAboveAltitudeThreshold(void *subj)
{
	RECAST(subject, subj, ty_Barometer *);
	return AverageAltitudeAboveThreshold_AltitudeAnalysisArray(
			&subject->priv.altitudeAnalysisArray,
			subject->priv.altitudeThreshold);
}

static const ty_i_api_DigitalInput aboveThresholdAltitudeInputApi = { CheckIfAboveAltitudeThreshold };

void init_Barometer(
		ty_Barometer *subject,
		void *entryTable,
		uint8_t numberOfEntries,
		ty_i_Input *altimeterInput)
{
	// set up barometer's own interfaces
	subject->thresholdUpdateOutput.api = &altitudeThresholdOutputApi;

	subject->aboveThresholdAltitudeInput.api = &aboveThresholdAltitudeInputApi;

	// add in barometer's privates
	subject->priv.altimeterInput = altimeterInput;

	init_AltitudeAnalysisArray(
			&subject->priv.altitudeAnalysisArray,
			entryTable,
			numberOfEntries);

	init_AddTimeStamp_InputToOutputMapper(
			&subject->priv.altimeterMapper,
			subject->priv.altimeterInput,
			&subject->priv.altitudeAnalysisArray.interface);
}

void CaptureAltitudeEntry_Barometer(ty_Barometer *subject, uint32_t time)
{
	Map_InputToOutputMapper(&subject->priv.altimeterMapper.interface, &time);
}
