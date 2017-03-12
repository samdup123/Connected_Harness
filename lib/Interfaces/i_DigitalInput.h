/*
 * i_DigitalInput Header File
 *
 * Description interface for a digital input
 *
 * Written by JamApps
 */

#ifndef i_DigitalInput
#define i_DigitalInput

#include <stdbool.h>

typedef struct
{
	bool (*Read)(void *subj);
} ty_i_api_DigitalInput;

typedef struct
{
	const ty_i_api_DigitalInput *api;
} ty_i_DigitalInput;

#define Read_DigitalInput(subj) \
	(subj)->api->Read((subj))

#endif
