/*
 * Barometer Header File
 *
 * Description Barometer object
 *
 * Written by JamApps
 */

#ifndef Barometer
#define Barometer

#include <stdint.h>
#include "i_Input.h"
#include "i_Output.h"
#include "i_InputToOutputMapper.h"
#include "i_DigitalInput.h"
#include "AltitudeAnalysisArray.h"
#include "AddTimeStamp_InputToOutputMapper.h"

typedef uint32_t ty_Velocity;
typedef uint32_t ty_Feet;

typedef struct
{
	ty_i_DigitalInput hasFallenInterface;
	ty_i_DigitalInput aboveThresholdAltitudeInput;
	ty_i_Output thresholdUpdateOutput;

	ty_i_Input velocityInput;
	ty_i_Input altitudeAverageInput;
	struct
	{
		ty_i_Input *altimeterInput;
		ty_i_Output *analysisOutput;

		ty_AltitudeAnalysisArray altitudeAnalysisArray;
		ty_AddTimeStamp_InputToOutputMapper altimeterMapper;

		ty_Velocity fallenThresholdSpeed;
		ty_Feet altitudeThreshold;
	} priv;
} ty_Barometer;

void init_Barometer(
		ty_Barometer *subject,
		void *entryTable,
		uint8_t numberOfEntries,
		ty_i_Input *altimeterInput);

void CaptureAltitudeEntry_Barometer(ty_Barometer *subject, uint32_t time);

#endif
