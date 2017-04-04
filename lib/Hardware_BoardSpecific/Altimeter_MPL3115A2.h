/*
 * Altimeter_MPL3115A2 Header File
 *
 * Description A driver for the MPL3115A2 Barometric Altitude sensor
 *
 * Written by JamApps
 */

#ifndef Altimeter_MPL3115A2
#define Altimeter_MPL3115A2

#include <Wire.h>
#include "SparkFunMPL3115A2.h"
#include "i_Input.h"
#include "Feet.h"

typedef struct
{
	ty_i_Input interface;
} ty_Altimeter_MPL3115A2;

void init_AltimeterMPL3115A2(ty_Altimeter_MPL3115A2 *subject);

#endif
