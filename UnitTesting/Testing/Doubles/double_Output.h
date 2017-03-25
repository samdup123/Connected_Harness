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

typedef struct
{
	ty_i_Output interface;

	struct
	{
		void *data;
	} priv;
} ty_double_Output;

void init_double_Output(ty_double_Output *subject);
void ChangeData_double_Output(ty_double_Output *subject, void *data);
#endif
