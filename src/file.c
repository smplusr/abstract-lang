#include "lang.h"




FILE *fileOpen (lang_t *lang) {
	char *name, *mode;
	FILE *file;

	mode = lang->string->getWord (lang->string, WORD_END);

	name = (char *) lang->update (lang);
	file = fopen (name, mode);

	if (!file || feof (file))
		perror (NULL);

	return (file)
		? file
		: NULL;
}


void fileClose (lang_t *lang) { fclose ((FILE *) lang->update (lang)); }


char *fileRead (lang_t *lang) {
	FILE *file = (FILE *) lang->update (lang);

	char data[BUFF_SIZE], *str = data;
	for (; (*str = fgetc (file)); str++)
		if (feof (file) || !*str)
			break;

	*str = '\0';
	return lang->string->store (lang->string, data);
}


void fileWrite (lang_t *lang) {
	FILE *file = (FILE *) lang->update (lang);
	char *str = (char *) lang->update (lang);

	for (; *str; str++) {
		fputc (*str, file);
		fflush (file);
	}
}
