#pragma once

#include "lib.h"



#define WORD_END "\n\t "

typedef struct lang_t lang_t;
struct lang_t {
	map_t *map;
	char *stream;

	char (*getc) (lang_t *);
	char *(*word) (lang_t *, char *);

	char *(*uniquestr) (lang_t *, char *);
	void *(*update) (lang_t *);
	void (*destroy) (lang_t **);
};


lang_t *Lang (void);
