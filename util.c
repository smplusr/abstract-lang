#include "util.h"




bool strequ (char *a, char *b) {
	for (; *a || *b; a++, b++)
		if (*a != *b)
			return false;
	return true;
}


bool cins (char c, char *str) {
	for (char *ptr = str; *ptr; ptr++)
		if (*ptr == c)
			return true;
	return false;
}


char *getword (char *str, char *delim) {
	char *ptr = str;
	for (; ; ptr++) {
		*ptr = stream.update (NULL);
		if (cins (*ptr, delim))
			break;
	}

	*ptr = '\0';
	return str;
}
