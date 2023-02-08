#include "lang.h"

#ifdef LANG_STAT

#include <sys/stat.h>



void *statOpen (lang_t *lang) {
	struct stat *st = (struct stat *) malloc (sizeof (struct stat));
	stat ((char *) lang->update (lang), st);

	return (void *) st;
}

void statClose (lang_t *lang) { free ((struct stat *) lang->update (lang)); }


size_t statSize (lang_t *lang) { return ((struct stat *) lang->update (lang))->st_size; }
size_t statBlocks (lang_t *lang) { return ((struct stat *) lang->update (lang))->st_blocks; }

#ifdef LANG_MODE
size_t statMode (lang_t *lang) { return (size_t) ((struct stat *) lang->update (lang))->st_mode; }
#endif

size_t statAccess (lang_t *lang) { return (size_t) &((struct stat *) lang->update (lang))->st_atime; }
size_t statModify (lang_t *lang) { return (size_t) &((struct stat *) lang->update (lang))->st_mtime; }
size_t statChange (lang_t *lang) { return (size_t) &((struct stat *) lang->update (lang))->st_ctime; }



#endif
