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

typedef struct {
	bool (*Read)(ty_Channel_GpioGroup channel);

	void (*Write)(ty_Channel_GpioGroup channel, const bool state);

} ty_i_api_GpioGroup;

typedef struct {
	const ty_i_api_GpioGroup *api;

} ty_i_GpioGroup;

#define Read_GpioGroup(subject, channel) \
	(subject)->api->Read((channel))

#define Write_GpioGroup(subject, channel, state) \
	(subject)->api->Write((channel), (state))

#endif

