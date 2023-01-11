#pragma once

#include <stddef.h>
#include <stdbool.h>

#include "stream.h"


#define STRING_END "\xa\t "




bool strequ (char *a, char *b);
char *getword (char *str, char *delim);
bool cins (char c, char *str);
