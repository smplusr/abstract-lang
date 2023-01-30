#include "lang.h"




size_t mathCharToInt (lang_t *lang) {
	char *str = (char *) lang->update (lang);
	return (str)
		? (size_t) atoi (str)
		: (size_t) NULL;
}

size_t mathAdd (lang_t *lang) { return (double) lang->update (lang) + (double) lang->update (lang); }
size_t mathSub (lang_t *lang) { return (double) lang->update (lang) - (double) lang->update (lang); }
size_t mathMul (lang_t *lang) { return (double) lang->update (lang) * (double) lang->update (lang); }
size_t mathDiv (lang_t *lang) { return (double) lang->update (lang) / (double) lang->update (lang); }
