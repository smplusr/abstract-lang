#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include "list.h"
#include "util.h"


#define BUFF_SIZE 4096 * 8

#define init_string(STR) 	\
	string_t STR = {	\
		NULL,		\
		stringSavePtr,	\
		stringFind,	\
		stringStore,	\
	}



/* String delete function not currently implemented
 * */

typedef struct str_ptr_t {
	char *data;
	size_t hash;
} str_ptr_t;


typedef struct string_t string_t;
struct string_t {
	node_t *node;


	str_ptr_t *(*save) (const char *);
	str_ptr_t *(*find) (const char *);
	char *(*store) (char *);
};


extern string_t string;
