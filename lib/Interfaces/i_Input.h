/*
 * i_Input Header File
 *
 * Description An input
 *
 * Written by JamApps
 */

#ifndef i_Input
#define i_Input

typedef struct
{
	void* (*Read)(void *subj);
} ty_i_api_Input;

typedef struct
{
	const ty_i_api_Input *api;
} ty_i_Input;

#define Read_Input(subj) \
	(subj)->api->Read((subj))

#endif
