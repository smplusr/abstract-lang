#include "sys.h"




void sysSleep () { sleep ((size_t) eval ()); }
void sysExit () { exit ((double) eval ()); }
void sysExec () {
	char *argv[16] = {NULL};
	size_t i = 0, pid,
	       argc = (size_t) eval (); 

	for (; i <= argc; i++)
		argv[i] = (char *) eval ();

	signal (SIGCHLD, SIG_IGN);
	pid = fork ();

	if (!pid) {
		if (execvp (argv[0], argv) == -1)
			perror (NULL);
	}
	if (pid == (size_t) -1)
		perror (NULL);
}
