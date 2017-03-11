/*
 * i_Accelerometer Header File
 *
 * Description interface for an acclerometer device
 *
 * Written by JamApps
 */

#ifndef i_Accelerometer
#define i_Accelerometer

#include <stdbool.h>

typedef struct
{
	void (*CollectTrigger)(void subj*);

	bool (*HasFallen)(void subj*);
} ty_i_api_Accelerometer;

typedef struct
{
	const ty_i_api_Accelerometer *api;
} ty_i_Accelerometer;

#define HasFallen_Accelerometer(subject) \
	(subject)->(api)->HasFallen((subject))

#endif
