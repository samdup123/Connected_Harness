/*
 * i_InputToOutputMapper Header File
 *
 * Description take input data and send it to an output
 *
 * Written by JamApps
 */

#ifndef i_InputToOutputMapper
#define i_InputToOutputMapper

typedef struct
{
	void (*Map)(void *subj, const void *addition);
} ty_i_api_InputToOutputMapper;

typedef struct
{
	const ty_i_api_InputToOutputMapper *api;
} ty_i_InputToOutputMapper;

#define Map_InputToOutputMapper(subj, addition) \
	(subj)->api->Map((subj), (addition))

#endif
