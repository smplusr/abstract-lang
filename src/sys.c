#include "sys.h"




void sysSleep () { sleep ((size_t) coreEval ()); }
void sysExit () { exit ((double) coreEval ()); }
char *sysExec () {
	bool piping = (bool) coreEval ();
	int link[2]; char data[BUFF_SIZE] = "";

	char *argv[16] = {NULL};	
	size_t i = 0, argc = (size_t) coreEval (); 
	pid_t pid;


	if (piping)
		if (pipe (link) == EOF)
			{ perror (NULL); return (char *) NULL; }

	for (; i <= argc; i++)
		argv[i] = (char *) coreEval ();

	signal (SIGCHLD, SIG_IGN);
	if ((pid = fork ()) == EOF) 
		{ perror (NULL); return (char *) NULL; }

	if (!pid) {
		if (piping) {
			dup2 (link[1], STDOUT_FILENO);
			close (link[0]); close (link[1]);
		}

		if (execvp (argv[0], argv) == EOF)
			{ perror (NULL); return (char *) NULL; }
	}

	if (piping) {
		read (link[0], data, sizeof (data));
		close (link[0]); close (link[1]);

		return string.store (data);
	}

	return (char *) NULL;
}
