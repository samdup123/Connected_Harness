/*
 * Altimeter_MPL3115A2 implementation
 *
 *
 * Written by JamApps
 */
#include "utilities.h"
#include "Altimeter_MPL3115A2.h"

MPL3115A2 myPressure;

void Read(void *subj, void *data) {
	RECAST(altitude, data, uint16_t *);
	*altitude =  myPressure.readAltitudeFt();
}

static const ty_i_api_Input api = { Read };

void init_AltimeterMPL3115A2(ty_Altimeter_MPL3115A2 *subject) {
	subject->interface.api = &api;
	Wire.begin();
	myPressure.begin();

	myPressure.setModeAltimeter();

	myPressure.setOversampleRate(7); // Set Oversample to the recommended 128
	myPressure.enableEventFlags();
}
