#include "list.h"
#include "string.h"
#include "dict.h"
#include "lang.h"




int main (int argc, char *argv[]) {
	lang_t *lang = Lang ();

	FILE *file;
	char file_read[BUFF_SIZE], *str = file_read;

/*	signal (SIGINT, SIG_IGN);	*/


	/* For UNIX shell compliancy (shebang)
	 * */
	
	short i;
	for (i = 0; i < (short) argc; i++) {
		char str1[6] = "argv", str2[6];
		sprintf (str2, "%d", i);
		lang->dict->set (lang->dict, lang->string->store (lang->string, strcat (str1, str2)), (size_t) argv[i], data);

	}

	file = fopen (argv[1], "r");
	if (file) {
		for (; (*str = fgetc (file)); str++)
				if (feof (file) || !*str)
					break;

			lang->dict->set (lang->dict, lang->string->store (lang->string, "argv1"), (size_t) file_read, data);
			lang->string->stream->set (lang->string->stream, file_read);
	} else {
		lang->string->stream->set (lang->string->stream, argv[1]);
	}


	for (; ; )
		lang->update (lang);
}
