#pragma once

#include "list.h"
#include "util.h"


#define init_dict(DICT) 		\
	dict_t DICT = {			\
		NULL,			\
		dictSet,		\
		dictGet			\
	}

/* Dictionary delete function is not currently implemented
 * */

typedef enum {
	callable,
	data
} type_t;

typedef struct global_t {
	size_t data;
	type_t type;
} global_t;

typedef struct pair_t {
	char *key;
	global_t value;
} pair_t;

typedef struct dict_t dict_t;
struct dict_t {
	node_t *node;

	void (*set) (char *, size_t, type_t);
	pair_t *(*get) (char *);
};


extern dict_t dict;
