#include "lang.h"




size_t langUpdate (lang_t *lang) {
	char *word = lang->string->getWord (lang->string, "\n\t ");
	
	pair_t *pair = (pair_t *) lang->dict->get (lang->dict, word);

	return (pair)
		? (pair->value.type == func)
			? (size_t) (*(void *(*) ()) pair->value.data) (lang)
			: (size_t) pair->value.data
		: (size_t) word;
}


#ifdef DEBUG_LANG
void langDebug (lang_t *lang) {
#ifdef DEBUG_DICT
	printf ("\n");
	lang->dict->debug (lang->dict);
#endif
#ifdef DEBUG_STRING
	printf ("\n");
	lang->string->debug (lang->string);
#endif
#ifdef DEBUG_STREAM
	printf ("\n");
	lang->string->stream->debug (lang->string->stream);
#endif
	printf ("\n");
}
#endif

void langDestroy (lang_t **lang) {
	(*lang)->string->destroy (&(*lang)->string);
	(*lang)->dict->destroy (&(*lang)->dict);
	free (*lang);
	*lang = (lang_t *) NULL;
}
lang_t *Lang () {
	lang_t *lang = (lang_t *) malloc (sizeof (lang_t));

	lang->dict = Dict ();
	lang->string = String ();

	lang->destroy = langDestroy;
	lang->update = langUpdate;

	lang->dict->set (lang->dict, lang->string->store (lang->string, "define"), (size_t) coreDefine, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "value"), (size_t) coreValue, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "eval"), (size_t) coreEval, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "not"), (size_t) coreNot, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "if"), (size_t) coreCond, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "input"), (size_t) coreInput, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "delete"), (size_t) coreDelete, func);

	lang->dict->set (lang->dict, lang->string->store (lang->string, "string"), (size_t) strString, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "conc"), (size_t) strConc, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "seek"), (size_t) strSeek, func);

	lang->dict->set (lang->dict, lang->string->store (lang->string, "print"), (size_t) outPrint, func);

	lang->dict->set (lang->dict, lang->string->store (lang->string, "open"), (size_t) fileOpen, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "read"), (size_t) fileRead, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "write"), (size_t) fileWrite, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "close"), (size_t) fileClose, func);

	lang->dict->set (lang->dict, lang->string->store (lang->string, "int"), (size_t) mathCharToInt, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "char"), (size_t) mathIntToChar, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "add"), (size_t) mathAdd, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "sub"), (size_t) mathSub, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "mul"), (size_t) mathMul, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "div"), (size_t) mathDiv, func);

	lang->dict->set (lang->dict, lang->string->store (lang->string, "exit"), (size_t) sysExit, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "sleep"), (size_t) sysSleep, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "exec"), (size_t) sysExec, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "fork"), (size_t) sysFork, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "pipe"), (size_t) sysPipe, func);

#ifdef DEBUG_LANG
	lang->debug = langDebug;
	lang->dict->set (lang->dict, lang->string->store (lang->string, "debug"), (size_t) lang->debug, func);
#endif

	return lang;
}
