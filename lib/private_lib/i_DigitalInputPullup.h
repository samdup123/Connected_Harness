/*
 * i_DigitalInputPullup Header File
 *
 * Description
 *
 * Written by JamApps
 */

#ifndef i_DigitalInputPullup
#define i_DigitalInputPullup

#include <stdbool.h>

typedef struct
{
	bool (*Read)(void *subj);

} ty_i_api_DigitalInputPullup;

typedef struct
{
	const ty_i_api_DigitalInputPullup *api;
} ty_i_DigitalInputPullup;

#define Read_DigitalInputPullup(subj) \
	(subj)->api->Read((subj))


#endif
