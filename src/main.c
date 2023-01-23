#include <signal.h>
#include "def.h"

extern void setInstructions ();




int main (int argc, char *argv[]) {
	FILE *file;
	char file_read[BUFF_SIZE], *str = file_read;

	setInstructions ();	
	signal (SIGINT, SIG_IGN);


	/* For UNIX shell compliancy (shebang)
	 * */
	if (argc) dict.set (string.store ("argv0"), (size_t) argv[0], false);
	if (argc >= 2) {
		file = fopen (argv[1], "r");
		if (file)
			for (; (*str = fgetc (file)); str++)
				if (feof (file) || !*str)
					break;

		dict.set (string.store ("argv1"), (size_t) file_read, false);
		stream.update (file_read);

		fclose (file);
	}


	for (; ; )
		coreUpdate ();
}
