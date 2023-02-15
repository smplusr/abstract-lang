#include "lang.h"






size_t mathCharToInt (lang_t *lang) {
	long a; sscanf ((char *) lang->update (lang), "%ld", &a);
	return a;
}



#ifdef LANG_MODE
size_t mathCharToOctal (lang_t *lang) {
	unsigned int a = 0; 
	sscanf ((char *) lang->update (lang), "%o", &a);
	return a;
}
#endif



char *mathIntToChar (lang_t *lang) {
	char str[BUFF_SIZE];
	sprintf (str, "%ld", (long) lang->update (lang));
	return lang->string->store (lang->string, str);
}



size_t mathAdd (lang_t *lang) { return lang->update (lang) + lang->update (lang); }
size_t mathSub (lang_t *lang) { return lang->update (lang) - lang->update (lang); }
size_t mathMul (lang_t *lang) { return lang->update (lang) * lang->update (lang); }
size_t mathDiv (lang_t *lang) { return lang->update (lang) / lang->update (lang); }
