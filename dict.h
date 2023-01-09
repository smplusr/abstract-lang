#pragma once

#include "util.h"


#define DICT_SIZE 256

#define init_dict(DICT) 	\
	dict_t DICT = {		\
		{},		\
		DICT.node,	\
		set,		\
		get		\
	}



typedef struct node_t {
	char *name;
	size_t data;
} node_t;

typedef struct dict_t dict_t;
struct dict_t {
	node_t node[DICT_SIZE],
		*ptr;

	void (*set) (char *, size_t);
	node_t *(*get) (char *);
};


extern dict_t dict;
