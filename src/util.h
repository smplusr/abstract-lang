#pragma once

#include <stddef.h>
#include <stdbool.h>

#include "stream.h"
#include "string.h"


#define WORD_END "\xa\t "




bool strequ (char *, char *);
char *getword (char *, char *);
bool cins (char, char *);
char *forward (char *, size_t, char *);
char *backward (char *, size_t, char *);
char *concat (char *, char *);
