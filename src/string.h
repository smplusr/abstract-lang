#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include "node.h"
#include "util.h"


#define BUFF_SIZE 4096 * 8

#define init_string(STR) 	\
	string_t STR = {	\
		NULL,		\
		stringFind,	\
		stringStore,	\
		stringRemove	\
	}




/* Needs removeal (or rename) of chr_t as
 * hash is calculated dynamically in dictionnary find
 * or string find.
 * */


typedef struct chr_t {
	char *data;
	size_t hash;
} chr_t;

typedef struct string_t string_t;
struct string_t {
	node_t *node;

	chr_t *(*find) (const char *);
	char *(*store) (const char *);
	void (*remove) (const char *);
};


extern string_t string;
