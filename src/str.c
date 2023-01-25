#include "str.h"




char *strWord () {
	char str[BUFF_SIZE];
	return string.store (getword (str, WORD_END));
}

char *strString () {
	char delim[DELIM_SIZE], data[BUFF_SIZE], *str;
	str = getword (data, getword (delim, WORD_END));
	stream.update (NULL);

	return string.store (str);
}

char *strSkip () {
	char *str = (char *) coreUpdate ();
	size_t cnt = coreUpdate ();

	return forward (str, cnt, WORD_END);
}

char *strPiks () {	
	char *str = (char *) coreUpdate ();
	size_t cnt = coreUpdate ();

	return backward (str, cnt, WORD_END);
}

char *strConc () {
	char *str1 = (char *) coreUpdate (),
	     *str2 = (char *) coreUpdate ();

	return concat (str1, str2);
}

/* Find a better algorithm for seek?
 * */

char *strSeek () {
	char *word = (char *) coreUpdate (),
	     *str = (char *) coreUpdate (),
	     comp[BUFF_SIZE],
	     *a, *b;

	for (; cins (*str, WORD_END); str++);
	for (; str && *str; str = a, str++) {
		for (a = str, b = comp; !cins (*a, WORD_END); a++, b++)
			*b = *a;

		for (; *b; b++) *b = '\0';

		if (djb2Hash (comp) == djb2Hash (word)) {
			for (; !cins(*str++, WORD_END); );
			return str;
		}
	}

	return (char *) NULL;
}


void strRemove () { string.remove ((char *) coreUpdate ()); }
