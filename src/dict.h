#pragma once

#include "list.h"



typedef enum {
	null,
	data,
	func
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
	list_t *list;

	void (*destroy) (dict_t **);

	void (*set) (dict_t *, char *, size_t, type_t);
	pair_t *(*get) (dict_t *, char *);
	void (*remove) (dict_t *, char *);

#ifdef DEBUG_DICT
	void (*debug) (dict_t *);
#endif
};


dict_t *Dict ();
