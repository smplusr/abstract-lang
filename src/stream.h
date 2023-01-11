#pragma once

#include <stdio.h>

#include "util.h"


#define init_stream(STREAM)	\
	stream_t STREAM = {	\
		NULL,		\
		update,		\
	}			\



typedef struct stream_t stream_t;
struct stream_t {
	char *data;
	char (*update) (char *);
};


extern stream_t stream;
