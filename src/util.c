#include "util.h"




bool strequ (char *a, char *b) {
	for (; *a || *b; a++, b++)
		if (*a != *b)
			return false;
	return true;
}


bool cins (char c, char *str) {
	char *ptr = str;
	for (; *ptr; ptr++)
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


char *forward (char *str, size_t cnt, char *delim) {
	for (; cins (*str, delim); ) str++;
	for (; cnt; cnt--, str++)
		for (; !cins (*str, delim); str++);

	return str;
}


char *backward (char *base, size_t cnt, char *delim) {
	char str[BUFF_SIZE] = "", *ptr = base;
	size_t i;
	for (; *ptr; ptr++);
	for (; cins (*--ptr, delim); );
	for (; cnt; cnt--, ptr--)
		for (; !cins (*ptr, delim); ptr--);

	for (i = 0; i <= (size_t) (ptr - base); i++)
		str[i] = base[i];

	return string.store (str);
}


char *concat (char *str1, char *str2) {
	char str[BUFF_SIZE] = "", *ptr;
	size_t i = 0;
	for (ptr = str1; *ptr && i < BUFF_SIZE; ptr++, i++)
		str[i] = *ptr;
	for (ptr = str2; *ptr && i < BUFF_SIZE; ptr++, i++)
		str[i] = *ptr;

	return string.store (str);
} 
