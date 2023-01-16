#include "string.h"



char *stringFind (char *str) {	
	char *ptr; 

	if (strequ (str, string.data))
		return string.data;

	for (ptr = string.data; ptr <= string.base; ptr++)
		if (!*ptr)
			if (strequ (str, ++ptr))
				return ptr;
	return NULL;
}


char *stringStore (char *read) {
	char *rd,
	     *ptr = string.find (read);

	if (ptr) return ptr;
	string.base = string.top;
	
	for (rd = read; *rd; rd++, string.top++)
		*string.top = *rd;

	*string.top++ = '\0';
	return string.base;
}


void stringDelstr (char *read) {
	char *ptr = string.find (read);
	if (!ptr) return;
	
	string.top = ptr;

	for (; *ptr; ptr++)
		*ptr = '\0';
}


init_string (string);
