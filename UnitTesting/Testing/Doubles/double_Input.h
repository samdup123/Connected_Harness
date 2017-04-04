/*
 * double_Input Header File
 *
 * Description double for input
 *
 * Written by JamApps
 */

#ifndef double_Input
#define double_Input

#include "i_Input.h"
#include <stdint.h>

typedef struct
{
	ty_i_Input interface;

	struct
	{
		void *data;
		uint8_t sizeOfData;
	} priv;
} ty_double_Input;

void init_double_Input(ty_double_Input *subject, void *data, uint8_t sizeOfData);
void ChangeData_double_Input(ty_double_Input *subject, void *newData);
#endif
