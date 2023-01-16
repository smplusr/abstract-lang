#include "str.h"




void *strWord () {
	char str[BUFF_SIZE];
	return string.store (getword (str, WORD_END));
}

void *strString () {
	char delim[DELIM_SIZE], data[BUFF_SIZE], *str;
	str = getword (data, getword (delim, WORD_END));
	stream.update (NULL);
	return string.store (str);
}

void strRemove () { string.delstr ((char *) coreEval ()); }

char *strSkip () {
	char *str = (char *) coreEval ();
	size_t cnt = coreEval ();

	return forward (str, cnt, WORD_END);
}

char *strPiks () {	
	char *str = (char *) coreEval ();
	size_t cnt = coreEval ();

	return backward (str, cnt, WORD_END);
}

char *strConc () {
	char *str1 = (char *) coreEval (),
	     *str2 = (char *) coreEval ();

	return concat (str1, str2);
}
