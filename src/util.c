#include "util.h"




bool strequ (const char *a, const char *b) {
	for (; *a || *b; a++, b++)
		if (*a != *b)
			return false;
	return true;
}


bool cins (char c, const char *str) {
	for (; *str; str++)
		if (*str == c)
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

size_t djb2Hash (const char *str) {
	size_t hash = 5381;

	for (; *str; str++)
		hash = ((hash << 5) + hash) + *str;

	return hash;
}


char *forward (const char *str, size_t cnt, char *delim) {
	for (; cins (*str, delim); ) str++;
	for (; cnt; cnt--, str++)
		for (; !cins (*str, delim); str++);

	return (char *) str;
}


char *backward (const char *base, size_t cnt, char *delim) {
	char str[BUFF_SIZE] = "", *ptr = (char *) base;
	size_t i;
	for (; *ptr; ptr++);
	for (; cins (*--ptr, delim); );
	for (; cnt; cnt--, ptr--)
		for (; !cins (*ptr, delim); ptr--);

	for (i = 0; i <= (size_t) (ptr - base); i++)
		str[i] = base[i];

	return string.store (str);
}


char *concat (const char *a, const char *b) {
	char str[BUFF_SIZE] = "";
	size_t i = 0;
	for (; *a && i < BUFF_SIZE; a++, i++)
		str[i] = *a;
	for (; *b && i < BUFF_SIZE; b++, i++)
		str[i] = *b;

	return string.store (str);
} 
