/*
 * UniversalConstants - to be used throughout
 *
 * Description describes the universal pins
 *
 * Written by JamApps
 */

#ifndef UniversalConstantsUno
#define UniversalConstantsUno

#include <stdint.h>
#include <stdbool.h>

enum
{
	UniversalPin_Led = 2,
	UniversalPin_MessageOutput = 8,
	UniversalPin_MessageInput = 7,
	UniversalPin_Buzzer = 12
};

typedef uint8_t ty_UniversalPin;

#endif


