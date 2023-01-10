#include "core.h"


size_t data () {
	char str[WORD_LEN];
	getword (str, STRING_END);

	return (dict.get (str))
		? dict.get (str)->data
		: (size_t) NULL;
}

size_t eval () {
	void *(*func) () = (*(void *(*) ()) data ());
	return (func)
		? (size_t) func ()
		: (size_t) NULL;

}

void define () {
	char str[WORD_LEN],
		*ptr = string.store (getword (str, STRING_END));

	dict.set (ptr, (size_t) eval ());
}

void condition () {
	((bool) eval ())
		? eval ()
		: data ();
}

void interpret () {
	stream.update ((char *) eval ());
}
