#include "str.h"




void *strWord () {
	char str[BUFF_SIZE];
	return string.store (getword (str, STRING_END));
}

void *strString () {
	char delim[DELIM_SIZE], data[BUFF_SIZE], *str;
	str = getword (data, getword (delim, STRING_END));
	stream.update (NULL);
	return string.store (str);
}

size_t strAtoi () {
	return (size_t) atoi ((char *) eval ());
}
