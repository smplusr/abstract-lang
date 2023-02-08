#include "lang.h"



size_t mathCharToDecimal (lang_t *lang) {
	char *str = (char *) lang->update (lang);
	int i = 0; sscanf (str, "%d", &i);
	return i;
}

size_t mathCharToOctal (lang_t *lang) {
	char *str = (char *) lang->update (lang);
	unsigned int i = 0; sscanf (str, "%o", &i);
	return i;
}


char *mathIntToChar (lang_t *lang) {
	size_t i = (size_t) lang->update (lang);
	char str[BUFF_SIZE];
	sprintf (str, "%ld", i);
	return lang->string->store (lang->string, str);
}

size_t mathAdd (lang_t *lang) { return (double) lang->update (lang) + (double) lang->update (lang); }
size_t mathSub (lang_t *lang) { return (double) lang->update (lang) - (double) lang->update (lang); }
size_t mathMul (lang_t *lang) { return (double) lang->update (lang) * (double) lang->update (lang); }
size_t mathDiv (lang_t *lang) { return (double) lang->update (lang) / (double) lang->update (lang); }
