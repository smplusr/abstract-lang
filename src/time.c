#include "lang.h"

#ifdef LANG_TIME

#include <time.h>



void *timeNow (void) {
	time_t *t = (time_t *) malloc (sizeof (time_t));
	*t = time (NULL); *t = mktime (localtime (t));

	return (void *) t;
} 

char *timeConvert (lang_t *lang) {
	time_t *time = (time_t *) lang->update (lang);
	
	char *str = ctime (time);
	return lang->string->store (lang->string, str);
}


#endif
