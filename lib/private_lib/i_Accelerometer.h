/*
 * i_Accelerometer Header File
 *
 * Description interface for an accelerometer
 *
 * Written by JamApps
 */

#ifndef i_Accelerometer
#define i_Accelerometer

#include <stdbool.h>

typedef struct
{
	void (*Reset)(void *subj);
	bool (*CheckHasFallen)(void *subj);
} ty_i_api_Accelerometer;

typedef struct
{
	const ty_i_api_Accelerometer *api;
} ty_i_Accelerometer;

#define CheckHasFallen_Accelerometer(subj) \
	subj->api->CheckHasFallen(subj)

#define Reset_Accelerometer(subject) \
	(subject)->api->Reset(subject)

#endif
