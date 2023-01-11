#include "file.h"




FILE *fileOpen () {
	char *name,
	     mode[1];

	FILE *file;

	*mode = stream.update (NULL);
	stream.update (NULL);

	name = (char *) eval ();
	file = fopen (name, mode);

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
	
	char *str = (char *) eval ();
	for (; *str; str++) {
		fputc (*str, file);
		fflush (file);
	}
}
