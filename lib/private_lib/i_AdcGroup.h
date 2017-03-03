/*
 * i_AdcGroup Header File
 *
 * Description
 *
 * Written by JamApps
 */

#ifndef i_AdcGroup
#define i_AdcGroup

#include <stdint.h>

typedef uint16_t ty_Channel_AdcGroup;

typedef struct {
	bool (*Read)(ty_Channel_AdcGroup channel);

} ty_i_api_AdcGroup;

typedef struct {
	const ty_i_api_AdcGroup *api;

} ty_i_AdcGroup;

#define Read_AdcGroup(subject, channel) \
	(subject)->api->Read((channel))

#endif
