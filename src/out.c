#include "out.h"



void outPrint () {
	char delim[DELIM_SIZE];
	getword (delim, WORD_END);

	if (cins ('s', delim))
		printf ("%s", (char *) coreEval ());
	if (cins ('x', delim))
		printf ("0x%lx", (size_t) coreEval ());
	if (cins ('d', delim))
		printf ("%f", (double) coreEval ());
	if (cins ('n', delim))
		printf ("\n");
}
