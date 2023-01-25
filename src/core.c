#include "core.h"




/* TODO: Optimize coreUpdate functions 
 * They are the main sources of lag and slowdowns
 * */

size_t coreUpdate () {
	char *str = strWord ();
	pair_t *pair = (pair_t *) dict.get (str);

	return (pair)
		? (pair->value.type == cal)
			? (size_t) (*(void *(*) ()) pair->value.data) ()
			: (size_t) pair->value.data
		: (size_t) str;
}

/* Useful for:
 * 
 * define a b
 * define b c
 * define a value a
 * 
 * a -> c
 * */

size_t coreValue () {
	pair_t *pair = dict.get ((char *) coreUpdate ());
	return (pair)
		? pair->value.data
		: (size_t) NULL;
}



/* Need a way to detect if a word is cal
 * If yes, do not evaluate (otherwise SEGFAULT)
 * Is it necessary though ?
 * */

void coreEval () { stream.update ((char *) coreUpdate ()); }

/* COMMENT OBSOLETE TODO DELETE
 *
 * Word redefinition needs prior deletion
 * 
 * define variable hello
 * define variable testing
 * 
 * hello -> testing
 * */

void coreDefine () {
	char *word = strWord ();
	dict.set(word, coreUpdate (), dat);
}


bool coreNot () { 
	if (coreUpdate ()) return false;
	return true;
}

void coreCond () {
	((bool) coreUpdate ())
		? (void) coreUpdate ()
		: (void) strWord ();		/* Needs a word ignore function */
}

char *coreInput () {
	char *ptr = stream.get (),
	     str[WORD_LEN];

	stream.update ("");
	getword (str, "\n");
	stream.update (ptr);

	return string.store (str);
}


void coreDelete () { 
	char *word = strWord ();	

	string.remove (word);
	dict.del (word);
}
