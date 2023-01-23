#include "out.h"



void outPrint () {
	char delim[DELIM_SIZE];
	getword (delim, WORD_END);

	if (cins ('s', delim))
		printf ("%s", (char *) coreUpdate ());
	if (cins ('x', delim))
		printf ("0x%lx", (size_t) coreUpdate ());
	if (cins ('d', delim))
		printf ("%li", (size_t) coreUpdate ());
	if (cins ('f', delim))
		printf ("%f", (double) coreUpdate ());
	if (cins ('n', delim))
		printf ("\n");
}
