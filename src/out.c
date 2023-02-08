#include "lang.h"




void outPrint (lang_t *lang) {
	char *delim = lang->string->getWord (lang->string, "\n\t ");

	if (lang->string->charInString ('s', delim))
		printf ("%s", (char *) lang->update (lang));
	if (lang->string->charInString ('x', delim))
		printf ("0x%lx", (size_t) lang->update (lang));
	if (lang->string->charInString ('d', delim))
		printf ("%li", (size_t) lang->update (lang));
	if (lang->string->charInString ('f', delim))
		printf ("%f", (double) lang->update (lang));
	if (lang->string->charInString ('n', delim))
		printf ("\n");
}

void outPut (lang_t *lang) { puts ((char *) lang->update (lang)); }
void outClear (void) { puts ("\033[2J\033[0;0H"); }
