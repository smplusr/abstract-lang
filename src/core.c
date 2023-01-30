#include "lang.h"




void coreDefine (lang_t *lang) {
	char *word = lang->string->getWord (lang->string, "\n\t ");
	lang->dict->set(lang->dict, word, lang->update (lang), dat);
}

size_t coreValue (lang_t *lang) {
	pair_t *pair = lang->dict->get (lang->dict, (char *) lang->update (lang));
	return (pair)
		? pair->value.data
		: (size_t) NULL;
}

void coreEval (lang_t *lang) { lang->string->stream->set (lang->string->stream, (char *) lang->update (lang)); }


size_t coreNot (lang_t *lang) { return (size_t) !lang->update (lang); }

void coreCond (lang_t *lang) {
	((bool) lang->update (lang))
		? (void) lang->update (lang)
		: (void) lang->string->getWord (lang->string, "\n\t ");	/* Needs a word ignore function */
}

char *coreInput (lang_t *lang) {
	char *ptr = lang->string->stream->get (lang->string->stream),
	     *str;

	lang->string->stream->set (lang->string->stream, "");
	str = lang->string->getWord (lang->string, "\n");
	lang->string->stream->set (lang->string->stream, ptr);

	return str;
}


/* Glitchy, needs to be fixed
 * Call -> SEGFAULT
 * */

void coreDelete (lang_t *lang) { 	
	char *word = lang->string->getWord (lang->string, "\n\t ");

	lang->dict->remove (lang->dict, word);
	lang->string->remove (lang->string, word);
}
