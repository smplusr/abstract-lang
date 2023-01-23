#include "core.h"




/* TODO: Optimize coreUpdate functions 
 * They are the main sources of lag and slowdowns
 * */

size_t coreUpdate () {
	char *str = strWord ();
	pair_t *pair = (pair_t *) dict.get (str);
	return (pair)
		? (pair->value.type == callable)
			? (size_t) (*(void *(*) ()) pair->value.data) ()
			: (size_t) pair->value.data
		: (size_t) str;	
}

/* Need a way to detect if a word is callable
 * If yes, do not evaluate (otherwise SEGFAULT)
 * Is it necessary though ?
 * */

void coreEval () { stream.update ((char *) coreUpdate ()); }

void coreDefine () {
	char *str = strWord ();
	dict.set (str, coreUpdate (), data);
}


bool coreNot () { return ! (bool) coreUpdate (); }

void coreCond () {
	((bool) coreUpdate ())
		? (void) coreUpdate ()
		: (void) strWord ();
}

char *coreInput () {
	char *ptr = stream.get (),
	     str[WORD_LEN];

	stream.update ("");
	getword (str, "\n");
	stream.update (ptr);

	return string.store (str);
}
