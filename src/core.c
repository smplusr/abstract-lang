#include "core.h"




size_t var () {
	char str[WORD_LEN];
	getword (str, STRING_END);

	return (dict.get (str))
		? dict.get (str)->data
		: (size_t) NULL;
}

size_t eval () {
	void *(*func) () = (*(void *(*) ()) var ());
	return (func)
		? (size_t) func ()
		: (size_t) NULL;

}

void define () {
	char str[WORD_LEN],
		*ptr = string.store (getword (str, STRING_END));

	dict.set (ptr, (size_t) eval ());
}

bool condnot () { return ! (bool) eval (); }

void condition () {
	((bool) eval ())
		? eval ()
		: var ();
}

void interpret () {
	stream.update ((char *) eval ());
}
