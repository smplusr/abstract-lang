#include "node.h"
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
	if (argc) lang->dict->set (lang->dict, lang->string->store (lang->string, "argv0"), (size_t) argv[0], dat);
	if (argc >= 2) {
		file = fopen (argv[1], "r");
		if (file) {
			for (; (*str = fgetc (file)); str++)
				if (feof (file) || !*str)
					break;

			lang->dict->set (lang->dict, lang->string->store (lang->string, "argv1"), (size_t) file_read, dat);
			lang->string->stream->set (lang->string->stream, file_read);
		
			fclose (file);
		} else {
			lang->dict->set (lang->dict, lang->string->store (lang->string, "argv1"), (size_t) argv[1], dat);
			lang->string->stream->set (lang->string->stream, argv[1]);
		}

	}

	for (; ; )
		lang->update (lang);

}
