#include "lang.h"

#ifdef LANG_DIRECTORY

#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>




void *dirOpen (lang_t *lang) {
	DIR *dp = opendir ((char *) lang->update (lang));

	return (dp)
		? (void *) dp
		: (void *) NULL;
}

void dirClose (lang_t *lang) { SYSTEM_CHECK (closedir ((DIR *) lang->update (lang))); }
char *dirRead (lang_t *lang) { 
	struct dirent *d = readdir ((DIR *) lang->update (lang));
	
	return (d)
		? lang->string->store (lang->string, d->d_name)
		: (char *) NULL;
}

void dirMake (lang_t *lang) { SYSTEM_CHECK (mkdir ((char *) lang->update (lang), 0777)); }
void dirRemove (lang_t *lang) { 
	char *name = (char *) lang->update (lang);
	SYSTEM_CHECK (rmdir (name));
}
void dirChange (lang_t *lang) { SYSTEM_CHECK (chdir ((char *) lang->update (lang))); }
char *dirCurrent (lang_t *lang) {
	char cwd[1024];
	getcwd (cwd, sizeof (cwd));
	return (lang->string->store (lang->string, cwd));
}


#endif
