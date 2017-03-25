/*
 * i_Output Header File
 *
 * Description Allows modules to output data
 *
 * Written by JamApps
 */

#ifndef i_Output
#define i_Output

typedef struct
{
	void (*Write)(void *subj, void *data);

} ty_i_api_Output;

typedef struct
{
	const ty_i_api_Output *api;
} ty_i_Output;

#define Write_Output(subj, data) \
	(subj)->api->Write((subj), (data))

#endif
