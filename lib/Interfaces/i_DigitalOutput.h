/*
 * i_DigitalOutput Header File
 *
 * Description Allows modules to output digital values
 *
 * Written by JamApps
 */

#ifndef i_DigitalOutput
#define i_DigitalOutput

#include <stdbool.h>

typedef struct
{
	void (*Write)(void *subj, bool state);

} ty_i_api_DigitalOutput;

typedef struct
{
	const ty_i_api_DigitalOutput *api;
} ty_i_DigitalOutput;

#define Write_DigitalOutput(subj, state) \
	(subj)->api->Write((subj), (state))

#endif
