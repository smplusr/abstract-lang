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
