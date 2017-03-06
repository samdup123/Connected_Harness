/*
 * i_GpioGroup Header File
 *
 * Description Interface for gpio
 *
 * Written by JamApps
 */

#ifndef i_GpioGroup
#define i_GpioGroup

#include <stdint.h>
#include <stdbool.h>

typedef uint8_t ty_Channel_GpioGroup;

typedef struct
{
	bool (*Read)(void *subj, ty_Channel_GpioGroup channel);

	bool (*Read_InputPullUp)(void *subj, ty_Channel_GpioGroup channel);

	void (*Write)(void *subj, ty_Channel_GpioGroup channel, const bool state);
} ty_i_api_GpioGroup;

typedef struct
{
	const ty_i_api_GpioGroup *api;
} ty_i_GpioGroup;

#define Read_GpioGroup(subj, channel) \
	(subj)->api->Read((subj), (channel))

#define Write_GpioGroup(subj, channel, state) \
	(subj)->api->Write((subj), (channel), (state))

#endif

