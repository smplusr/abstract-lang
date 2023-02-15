#include "lang.h"




char *strString (lang_t *lang) {
	char c = lang->string->stream->update (lang->string->stream),
	     *str = lang->string->getWord (lang->string, &c);
	lang->string->stream->update (lang->string->stream);

	return str;
}

char *strConc (lang_t *lang) {
	char *a = (char *) lang->update (lang),
	     *b = (char *) lang->update (lang);

	char str[BUFF_SIZE], *ptr = str;
	const size_t len = sizeof (str) / sizeof (ptr);

	for (; *a && ptr <= (str + len); a++, ptr++)
		*ptr = *a;
	for (; *b && ptr <= (str + len); b++, ptr++)
		*ptr = *b;

	*ptr++ = '\0';
	return lang->string->store (lang->string, str);
}


#ifdef LANG_EXTRA

/* Find a better algorithm for seek?
 * */

char *strSeek (lang_t *lang) {
	char *word = (char *) lang->update (lang),
	     *str = (char *) lang->update (lang),
	     comp[BUFF_SIZE],
	     *a, *b;

	for (; lang->string->charInString (*str, WORD_END); str++);
	for (; str && *str; str = a, str++) {
		for (a = str, b = comp; !lang->string->charInString (*a, WORD_END); a++, b++)
			*b = *a;

		for (; *b; b++) *b = '\0';

		if (lang->string->djb2Hash (comp) == lang->string->djb2Hash (word)) {
			for (; !lang->string->charInString(*str++, WORD_END); );
			return str;
		}
	}

	return (char *) NULL;
}

char *strQuote (lang_t *lang) { return lang->string->getWord (lang->string, WORD_END); }

#endif

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

