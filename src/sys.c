#include "sys.h"




void sysSleep () { sleep ((size_t) coreEval ()); }
void sysExit () { exit ((double) coreEval ()); }

void sysExec () {
	char *argv[16] = {NULL};	
	size_t i = 0, argc = (size_t) coreEval (); 
	
	for (; i <= argc; i++)
		argv[i] = (char *) coreEval ();

	if (pipefd[0])
		dup2 (pipefd[1], STDOUT_FILENO);

	if (execvp (argv[0], argv) == EOF)
		perror (NULL);	
}


pid_t sysFork () {
	pid_t pid;
	
	signal (SIGCHLD, SIG_IGN);
	if ((pid = fork ()) == EOF)
		perror (NULL); 

	if (!pid) {
		coreEval ();
		return *(pid_t *) NULL;
	}

	coreVar ();
	return pid;
}


int pipefd[2]; 
char *sysPipe () {
	char data[BUFF_SIZE] = "";
	
	if (pipe (pipefd) == EOF) {
		perror (NULL);
		return (char *) NULL;
	}

	coreEval ();

	read (pipefd[0], data, sizeof (data));
	close (pipefd[0]); close (pipefd[1]);
	return string.store (data);
}

