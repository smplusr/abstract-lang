#include "core.h"




size_t coreVar () {
	char str[WORD_LEN];
	getword (str, WORD_END);

	return (dict.get (str))
		? dict.get (str)->data
		: (size_t) NULL;
}

size_t coreEval () {
	void *(*func) () = (*(void *(*) ()) coreVar ());
	return (func)
		? (size_t) func ()
		: (size_t) NULL;

}

void coreDefine () {
	char str[WORD_LEN],
		*ptr = string.store (getword (str, WORD_END));

	dict.set (ptr, (size_t) coreEval ());
}

bool coreNot () { return ! (bool) coreEval (); }

void coreCond () {
	((bool) coreEval ())
		? coreEval ()
		: coreVar ();
}

void coreEvaluate () {
	stream.update ((char *) coreEval ());
}


