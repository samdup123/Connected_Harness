/*
 * UniversalPins Header File
 *
 * Description describes the universal pins
 *
 * Written by JamApps
 */

#ifndef UniversalPins
#define UniversalPins

#include <stdint.h>
#include "Arduino.h"

enum
{
	UniversalPin_Led = 2,
	UniversalPin_OnBoardLed = LED_BUILTIN
};

typedef uint8_t ty_UniversalPin;

#endif


