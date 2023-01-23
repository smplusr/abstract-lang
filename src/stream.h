#pragma once

#include <stdio.h>

#include "util.h"


#define init_stream(STREAM)	\
	stream_t STREAM = {	\
		NULL,		\
		streamGet,	\
		streamUpdate,	\
	}			\



typedef struct stream_t stream_t;
struct stream_t {
	char *data;
	char *(*get) ();
	char (*update) (char *);
};


extern stream_t stream;
