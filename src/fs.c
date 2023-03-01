#include "include.h"

#ifdef LANG_FILE

#include <sys/mount.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>




FILE *FileOpen (lang_t *lang) {
	char *name, *mode;
	FILE *file;

	mode = lang->word (lang, WORD_END);

	name = (char *) lang->update (lang);
	file = fopen (name, mode);

	return (file)
		? file
		: NULL;
}

char *FileRead (lang_t *lang) {
	FILE *file = (FILE *) lang->update (lang);
	char *ctn; size_t len;

	fseek (file, 0L, SEEK_END);
	len = ftell (file);
	fseek (file, 0L, SEEK_SET);

	ctn = (char *) malloc (len * sizeof (char));
	fread (ctn, len, sizeof (char), file);

	ctn[len] = '\0'; 
	return lang->uniquestr (lang, ctn);
}

void FileWrite (lang_t *lang) {
	FILE *file = (FILE *) lang->update (lang);
	char *p = (char *) lang->update (lang);

	for (; *p; p++) {
		fputc (*p, file);
		fflush (file);
	}
}




void FsClose (lang_t *lang) { 
	void *p = lang->update (lang);
	if (!p) return;

	(fileno ((FILE *) p))
		? SYSTEM_CHECK (fclose ((FILE *) p))
		: (dirfd ((DIR *) p))
			? SYSTEM_CHECK (closedir ((DIR *) p))
			: SYSTEM_CHECK (close ((size_t) p));
}
void FsRemove (lang_t *lang) { SYSTEM_CHECK (remove ((char *) lang->update (lang))); }
void FsMount (lang_t *lang) {
	char *src = (char *) lang->update (lang),
	     *dest = (char *) lang->update (lang),
	     *type = (char *) lang->update (lang);

	SYSTEM_CHECK (mount (src, dest, type, (size_t) NULL, (char *) NULL));
}
void FsUmount (lang_t *lang) { SYSTEM_CHECK (umount ((char *) lang->update (lang))); }
void FsSymlink (lang_t *lang) {
	char *base = (char *) lang->update (lang),
	     *link = (char *) lang->update (lang);
	SYSTEM_CHECK (symlink (base, link));
}




void *DirOpen (lang_t *lang) {
	DIR *dp = opendir ((char *) lang->update (lang));

	return (dp)
		? (void *) dp
		: (void *) NULL;
}

char *DirRead (lang_t *lang) { 
	struct dirent *d = readdir ((DIR *) lang->update (lang));
	
	return (d)
		? lang->uniquestr (lang, d->d_name)
		: (char *) NULL;
}

void DirMake (lang_t *lang) { SYSTEM_CHECK (mkdir ((char *) lang->update (lang), 0777)); }
void DirChange (lang_t *lang) { SYSTEM_CHECK (chdir ((char *) lang->update (lang))); }
char *DirCurrent (lang_t *lang) {
	char *cwd = (char *) malloc (256 * sizeof (char));
	getcwd (cwd, sizeof (cwd));
	return (lang->uniquestr (lang, cwd));
}




#endif
