#include "include.h"




void *MathInteger (lang_t *lang) {
	long a = 0; sscanf ((char *) (size_t) lang->update (lang), "%ld", &a);
	return (void *) a;
}

char *MathChar (lang_t *lang) {
	char *a = (char *) malloc ((sizeof (void *) + 1) * sizeof (char));
	sprintf (a, "%ld", (long) lang->update (lang));
	return lang->uniquestr (lang, a);
}

void *MathAdd (lang_t *lang) { return (void *) ((long) lang->update (lang) + (long) lang->update (lang)); }
void *MathSub (lang_t *lang) { return (void *) ((long) lang->update (lang) - (long) lang->update (lang)); }
void *MathMul (lang_t *lang) { return (void *) ((long) lang->update (lang) * (long) lang->update (lang)); }
void *MathDiv (lang_t *lang) { return (void *) ((long) lang->update (lang) / (long) lang->update (lang)); }
