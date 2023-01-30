#pragma once


#include <stdio.h>
#include <stdlib.h>




typedef struct stream_t stream_t;

struct stream_t {
	char *data;

	void (*destroy) (stream_t **stream);

	char *(*get) (stream_t *);
	void (*set) (stream_t *, char *);
	char (*update) (stream_t *);

#ifdef DEBUG_STREAM
	void (*debug) (stream_t *);
#endif
};

stream_t *Stream ();
