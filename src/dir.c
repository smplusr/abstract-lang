#include "lang.h"




DIR *dirOpen (lang_t *lang) {
	DIR *dp = opendir ((char *) lang->update (lang));

	return (dp)
		? dp
		: (DIR *) NULL;
}

void dirClose (lang_t *lang) { closedir ((DIR *) lang->update (lang)); }
char *dirRead (lang_t *lang) { 
	struct dirent *d = readdir ((DIR *) lang->update (lang));
	
	return (d)
		? lang->string->store (lang->string, d->d_name)
		: (char *) NULL;
}

void dirMake (lang_t *lang) { mkdir ((char *) lang->update (lang), (size_t) lang->update (lang)); }
void dirRemove (lang_t *lang) { rmdir ((char *) lang->update (lang)); }
void dirChange (lang_t *lang) { chdir ((char *) lang->update (lang)); }
char *dirCurrent (lang_t *lang) {
	char cwd[1024];
	getcwd (cwd, sizeof (cwd));
	return (lang->string->store (lang->string, cwd));
}
