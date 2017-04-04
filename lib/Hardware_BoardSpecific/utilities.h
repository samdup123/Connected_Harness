/*
 * utilities Header File
 *
 * Description some basic utilities
 *
 * Written by JamApps
 */

#ifndef utilities
#define utilities

#include <stdbool.h>
#include <string.h>

#define RECAST(newName, oldName, newType) \
	newType newName = (newType)oldName

#define ON true

#define OFF false

#define UINT16_MAX_VALUE (65535)

#endif
