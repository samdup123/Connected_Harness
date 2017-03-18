/*
 * Input_RadioFrequencyReceiver Header File
 *
 * Description
 *
 * Written by JamApps
 */

#ifndef Input_RadioFrequencyReceiver
#define Input_RadioFrequencyReceiver

#include "utilities.h"
#include "i_DigitalInput.h"
#include "i_GpioGroup.h"
#include "VirtualWire.h"


static const uint8_t BUFFER_LENGTH = VW_MAX_MESSAGE_LEN;

typedef struct
{
	ty_i_DigitalInput interface;
	struct
	{
		bool nothing;
		uint8_t buf[BUFFER_LENGTH];
	} priv;
} ty_Input_RadioFrequencyReciever;

void init_Input_RadioFrequencyReceiver(
		ty_Input_RadioFrequencyReciever *subject,
		ty_Channel_GpioGroup channel);

bool ReturnTrue_Input_RadioFrequencyReceiver(ty_Input_RadioFrequencyReciever *subject);

#endif
