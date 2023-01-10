#include "string.h"



char *find (char *str) {
	if (strequ (str, string.data))
		return string.data;

	for (char *ptr = string.data; ptr <= string.base; ptr++)
		if (!*ptr)
			if (strequ (str, ++ptr))
				return ptr;
	return NULL;
}


char *store (char *read) {
	char *ptr = string.find (read);
	if (ptr) return ptr;

	string.base = string.top;
	for (char *rd = read; *rd; rd++, string.top++)
		*string.top = *rd;

	*string.top++ = '\0';
	return string.base;
}



init_string (string);
