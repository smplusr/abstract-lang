#include "cli.h"



void cliPrint () {
	char c = stream.update (NULL);
	stream.update (NULL);
	switch (c) {
		case 's':
			printf ("%s\n", (char *) eval ());
			break;
		case 'x':
			printf ("0x%lx\n", (size_t) eval ());
			break;
		case 'd':
			printf ("%f\n", (double) eval ());
			break;
		default:
			break;
	}

}
