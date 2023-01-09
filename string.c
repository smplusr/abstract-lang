#include "string.h"



char *store (char *read) {
	string.base = string.top;
	for (char *ptr = read; *ptr; ptr++, string.top++)
		*string.top = *ptr;

	*string.top++ = '\0';
	return string.base;
}



init_string (string);
