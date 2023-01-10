#include "sys.h"




void sysSleep () { sleep ((size_t) eval ()); }
void sysExit () { exit ((double) eval ()); }
void sysExec () {
	char *argv[16] = {NULL};
	for (size_t i = 0, argc = (size_t) eval (); i <= argc; i++)
		argv[i] = (char *) eval ();

	signal (SIGCHLD, SIG_IGN);
	size_t pid = fork ();

	if (!pid) {
		if (execvp (argv[0], argv) == -1)
			perror (NULL);
	}
	if (pid == -1)
		perror (NULL);
}
