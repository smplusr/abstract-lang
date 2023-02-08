#include "lang.h"

#ifdef LANG_MODE

#include <sys/stat.h>



char *modeToChar (char *out, mode_t mode) {
	char *c;
	for (c = out; c < out + 9 * sizeof (char); c++)
		*c = '-';
	*c = '\0';

	if ((mode & 0777) & S_IRUSR) out[0] = 'r';
	if ((mode & 0777) & S_IWUSR) out[1] = 'w';
	if ((mode & 0777) & S_IXUSR) out[2] = 'x';
	if ((mode & 0777) & S_IRGRP) out[3] = 'r';
	if ((mode & 0777) & S_IWGRP) out[4] = 'w';
	if ((mode & 0777) & S_IXGRP) out[5] = 'x';
	if ((mode & 0777) & S_IROTH) out[6] = 'r';
	if ((mode & 0777) & S_IWOTH) out[7] = 'w';
	if ((mode & 0777) & S_IXOTH) out[8] = 'x';

	return out;
}

char *modeConvert (lang_t *lang) {
	char mode[10];

	modeToChar (mode, (mode_t) lang->update (lang));
	return lang->string->store (lang->string, mode);
}

void modeChange (lang_t *lang) {
	char *file = (char *) lang->update (lang);
	mode_t mode = (int) lang->update (lang);
	chmod (file, mode);
}


#endif
