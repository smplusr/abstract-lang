#include "file.h"




FILE *fileOpen () {
	char *name,
	     mode[DELIM_SIZE];

	FILE *file;

	getword (mode, WORD_END);

	name = (char *) coreEval ();
	file = fopen (name, mode);

	if (!file || feof (file))
		perror (NULL);

	return (file)
		? file
		: NULL;
}


void fileClose () {
	fclose ((FILE *) coreEval ());
}


char *fileRead () {
	FILE *file = (FILE *) coreEval ();

	char data[BUFF_SIZE], *str = data;
	for (; (*str = fgetc (file)); str++)
		if (feof (file) || !*str)
			break;

	*str = '\0';
	return string.store (data);
}


void fileWrite () {
	FILE *file = (FILE *) coreEval ();
	char *str = (char *) coreEval ();

	for (; *str; str++) {
		fputc (*str, file);
		fflush (file);
	}
}
