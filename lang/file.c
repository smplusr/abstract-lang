#include "file.h"




FILE *fileOpen () {
	char *name = (char *) eval (),
	     mode[DELIM_SIZE];
	getword (mode, STRING_END);

	FILE *file = fopen (name, mode);

	if (!file || feof (file))
		perror (NULL);

	return (file)
		? file
		: NULL;
}


void fileClose () {
	fclose ((FILE *) eval ());
}


char *fileRead () {
	FILE *file = (FILE *) eval ();

	char data[BUFF_SIZE], *str = data;
	for (; (*str = fgetc (file)); str++)
		if (feof (file) || !*str)
			break;

	*str = '\0';
	return string.store (data);
}


void fileWrite () {
	FILE *file = (FILE *) eval ();
	for (char *str = (char *) eval (); *str; str++) {
		fputc (*str, file);
		fflush (file);			// wanky C stdio file interaction
	}
}
