#include "lang.h"




/*char *strWord () {
	char str[BUFF_SIZE];
	return string.store (getword (str, WORD_END));
}*/

char *strString (lang_t *lang) {
/*	char delim[DELIM_SIZE], data[BUFF_SIZE], *str;
	str = getword (data, getword (delim, WORD_END));
	stream.update (NULL);
*/

/*
	char *delim = lang->string->getWord (lang->string, "\n\t ");
	char *string = lang->string->getWord (lang->string, delim);
	lang->string->remove (lang->string, delim);
*/

	return lang->string->getWord (lang->string, lang->string->getWord (lang->string, "\n\t "));
}
/*
char *strSkip (lang_t *lang) {
	char *str = (char *) lang->update (lang);
	size_t cnt = lang->update (lang);

	for (; lang->string->charInString (*str, delim); str++);
	for (; cnt; cnt--, str++)
		for (; !lang->string->charInString (*str, delim); str++);

	return forward (str, cnt, WORD_END);
}*/
/*
char *strPiks () {	
	char *str = (char *) coreUpdate ();
	size_t cnt = coreUpdate ();

	return backward (str, cnt, WORD_END);
}*/

char *strConc (lang_t *lang) {
	char *a = (char *) lang->update (lang),
	     *b = (char *) lang->update (lang);

	char str[4096 * 8], *ptr = str;
	const size_t len = sizeof (str) / sizeof (ptr);

	for (; *a && ptr <= (str + len); a++, ptr++)
		*ptr = *a;
	for (; *b && ptr <= (str + len); b++, ptr++)
		*ptr = *b;

	*ptr++ = '\0';
	return lang->string->store (lang->string, str);
}

/* Find a better algorithm for seek?
 * */

char *strSeek (lang_t *lang) {
	char *word = (char *) lang->update (lang),
	     *str = (char *) lang->update (lang),
	     comp[4096 * 8],
	     *a, *b;

	for (; lang->string->charInString (*str, "\n\t "); str++);
	for (; str && *str; str = a, str++) {
		for (a = str, b = comp; !lang->string->charInString (*a, "\n\t "); a++, b++)
			*b = *a;

		for (; *b; b++) *b = '\0';

		if (lang->string->djb2Hash (comp) == lang->string->djb2Hash (word)) {
			for (; !lang->string->charInString(*str++, "\n\t "); );
			return str;
		}
	}

	return (char *) NULL;
}
