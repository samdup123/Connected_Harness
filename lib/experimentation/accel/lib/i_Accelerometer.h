/*
 * i_Accelerometer Header File
 *
 * Description
 *
 * Written by JamApps
 */

#ifndef i_Accelerometer
#define i_Accelerometer

#include <stdbool.h>

typedef struct
{
	void (*SetTriggers)(void *subj);

	bool (*CheckFallStatus)(void *subj);
} ty_i_api_Accelerometer;

typedef struct
{
	ty_i_api_Accelerometer *api;
} ty_i_Accelerometer;

#define SetTriggers_Accelerometer(subject) \
	(subject)->(api)->SetTriggers((subject))

#define CheckFallStatus_Accelerometer(subject) \
	(subject)->(api)->CheckFallStatus((subject))

#endif
