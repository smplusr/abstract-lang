#include "include.h"

#include <string.h>



/*
char *strcpy (char *dest, const char *src) { for (; *src; dest++, src++) *dest = *src; return dest; }
char *catstr (const char *a, const char *b) {
	char *dest = (char *) malloc (strlen (a) + strlen (b) * sizeof (char));
	strcpy (dest, b); strcpy (dest + strlen (dest), a);
	return dest;
}*/
/*
char *strcpy (char *dest, const char *src) { 
	char *p = dest;
	for (; *src; src++, p++)
		*p = *src;

	return dest;
}*/


char *CoreString (lang_t *lang) {
	char c = lang->getc (lang),
	     *dest =lang->word (lang, &c);

	(void) lang->getc (lang);
	return lang->uniquestr (lang, dest);
}

char *CoreCat (lang_t *lang) { 
	char *a = (char *) lang->update (lang),
	     *b = (char *) lang->update (lang),
	     *dest = (char *) malloc ((strlen (a) + strlen (b)) * sizeof (char));

	strcpy (dest, a); strcpy (dest + strlen (a), b);
	return lang->uniquestr (lang, dest);
}

char *CoreCut (lang_t *lang) { 
	char *src = (char *) lang->update (lang), 
	     *dest;
	size_t len = (size_t) lang->update (lang);

	dest = (char *) malloc (len * sizeof (char));
	memcpy (dest, src, len);
	*(dest + len) = '\0';

	return lang->uniquestr (lang, dest);
}

char *CoreSkip (lang_t *lang) { 
	char *dest = (char *) lang->update (lang);
	size_t len = (size_t) lang->update (lang);

	return lang->uniquestr (lang, (char *) (dest + len));
}

size_t CoreLength (lang_t *lang) { return strlen ((char *) lang->update (lang)); }




void CoreDelete (lang_t *lang) {
	char *key = (char *) lang->word (lang, WORD_END);	/* (char *) lang->update (lang); */
	lang->map->remove (lang->map, lang->map->hash (key));
	free (key);
}

void CoreDefine (lang_t *lang) {
	char *key = (char *) lang->word (lang, WORD_END);	/* (char *) lang->update (lang); */
	void * value = lang->update (lang);
	pair_t *pair = lang->map->find (lang->map, lang->map->hash (key));

	(pair)	? (void) (pair->value = value)
		: (pair = Pair (key, value), lang->map->insert (lang->map, pair));

	free (key);
}

void CoreEval (lang_t *lang) { lang->stream = (char *) (size_t) lang->update (lang); }
void *CoreNot (lang_t *lang) { return (void *) (long) !lang->update (lang); }
void CoreCond (lang_t *lang) {
	(lang->update (lang))
		? (void) lang->update (lang)
		: (void) free (lang->word (lang, WORD_END));
}

char *CoreInput (lang_t *lang) { 
	size_t alloc = 2, i = 0;
	char *buffer = (char *) malloc (alloc * sizeof (char));

	for (; ; i++) {
		if (i >= alloc) {
			alloc *= 2;
			buffer = (char *) realloc (buffer, alloc * sizeof (char));
		}
		buffer[i] = fgetc (stdin);
		if (buffer[i] == '\n' || !buffer[i])
			break;
	} buffer[i] = '\0';

	return lang->uniquestr (lang, buffer);
}

void CorePut (lang_t *lang) { puts ((char *) (size_t) lang->update (lang)); }
