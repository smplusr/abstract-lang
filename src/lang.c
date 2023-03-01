#include "lang.h"




char LangChar (lang_t *lang) {
	return (lang->stream && *(lang->stream))
		? *(lang->stream)++
		: fgetc (stdin);
}

char *LangWord (lang_t *lang, char *delim) {
	size_t alloc = 2, i = 0;
	char *buffer = (char *) malloc (alloc * sizeof (char));

	for (; ; i++) {
		if (i >= alloc) {
			alloc *= 2;
			buffer = (char *) realloc (buffer, alloc * sizeof (char));
		}
		buffer[i] = lang->getc (lang);
		if (strchr (delim, buffer[i]))
			break;
	} buffer[i] = '\0';

	return buffer;
}

char *LangUniqueStr (lang_t *lang, char *value) {
	pair_t *pair = lang->map->find (lang->map, lang->map->hash (value));

	return (pair) ? (free (value), pair->value)
		: (pair = Pair (value, (void *) (size_t) value), lang->map->insert (lang->map, pair), (char *) (size_t) pair->value);
}

void *LangUpdate (lang_t *lang) {
	char *word = lang->word (lang, WORD_END);
	pair_t *pair = lang->map->find (lang->map, lang->map->hash (word));

	return (pair)
		? (free (word), (pair->type == 0x1))
			? (*(void *(*) ()) (size_t) pair->value) (lang)
			: pair->value
		: lang->uniquestr (lang, word);
}

void LangDestroy (lang_t **lang) {
	(*lang)->map->destroy (&(*lang)->map);
	(*lang)->stream = NULL;

	free (*lang); *lang = NULL;
}

lang_t *Lang (void) {
	lang_t *lang = (lang_t *) malloc (sizeof (lang_t));

	lang->map = Map ();
	lang->stream = NULL;

	lang->getc = LangChar;
	lang->word = LangWord;

	lang->uniquestr = LangUniqueStr;
	lang->update = LangUpdate;
	lang->destroy = LangDestroy;

	return lang;
}
