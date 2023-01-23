#pragma once

#include <stddef.h>
#include <stdbool.h>

#include "stream.h"
#include "string.h"


#define WORD_END "\xa\t "




bool strequ (const char *, const char *);
char *getword (char *, char *);
bool cins (char, const char *);
size_t djb2Hash (const char *str);
char *forward (const char *, size_t, char *);
char *backward (const char *, size_t, char *);
char *concat (const char *, const char *);
