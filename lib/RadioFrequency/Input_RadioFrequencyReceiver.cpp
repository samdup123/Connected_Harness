/*
 * Input_RadioFrequencyReceiver implementation
 *
 *
 * Written by JamApps
 */

#include "Input_RadioFrequencyReceiver.h"

enum
{
	BitRate = 4000
};

static bool Read(void *subj) {
	RECAST(subject, subj, ty_Input_RadioFrequencyReciever *);
	uint8_t bufLength = BUFFER_LENGTH;
	if (vw_get_message(subject->priv.buf, &bufLength)
			&& subject->priv.buf[0] == '1') {
		return true;
	}
	return false;
}

static const ty_i_api_DigitalInput api = { Read };

void init_Input_RadioFrequencyReceiver(
		ty_Input_RadioFrequencyReciever *subject,
		ty_Channel_GpioGroup channel) {
	subject->interface.api = &api;

	vw_set_ptt_inverted(true);

	vw_set_rx_pin(channel);
	vw_setup(BitRate);

	vw_rx_start();
}

bool ReturnTrue_Input_RadioFrequencyReceiver(
		ty_Input_RadioFrequencyReciever *subject,
		ty_Channel_GpioGroup channel) {
	return true;
}
