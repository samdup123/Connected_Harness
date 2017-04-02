/*
 * double_Output Header File
 *
 * Description double for output
 *
 * Written by JamApps
 */

#ifndef double_Output
#define double_Output

#include "i_Output.h"
#include <stdint.h>

typedef struct
{
	ty_i_Output interface;

	struct
	{
		void *data;
		uint8_t sizeOfData;
	} priv;
} ty_double_Output;

void init_double_Output(ty_double_Output *subject, void * data, uint8_t sizeOfData);

void * CheckData_double_Output(ty_double_Output *subject);
#endif
