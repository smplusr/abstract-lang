#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include "node.h"
#include "stream.h"


#define BUFF_SIZE 4096 * 8



/* Needs removeal (or rename) of token_t as
 * hash is calculated dynamically in dictionnary find
 * or string find.
 * */


typedef struct token_t {
	char *data;
	size_t hash;
} token_t;

typedef struct string_t string_t;
struct string_t {
	stream_t *stream;
	list_t *list;
	
	void (*destroy) (string_t **string);

	token_t *(*find) (string_t *, char *);
	char *(*store) (string_t *, char *);
	void (*remove) (string_t *, char *);

	bool (*charInString) (char, const char *);
	size_t (*djb2Hash) (const char *str);
	char *(*read) (string_t *, char *, char *);
	char *(*getWord) (string_t *, char *);

#ifdef DEBUG_STRING
	void (*debug) (string_t *);
#endif
};


string_t *String ();
