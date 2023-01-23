#include "sys.h"




void sysSleep () { sleep ((size_t) coreUpdate ()); }
void sysExit () { exit ((double) coreUpdate ()); }

void sysExec () {
	char *argv[16] = {NULL};	
	size_t i = 0, argc = (size_t) coreUpdate (); 
	
	for (; i <= argc; i++)
		argv[i] = (char *) coreUpdate ();

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
		coreUpdate ();
		return *(pid_t *) NULL;
	}

	strWord ();
	return pid;
}


int pipefd[2]; 
char *sysPipe () {
	char data[BUFF_SIZE] = "";
	
	if (pipe (pipefd) == EOF) {
		perror (NULL);
		return (char *) NULL;
	}

	coreUpdate ();

	read (pipefd[0], data, sizeof (data));
	close (pipefd[0]); close (pipefd[1]);
	return string.store (data);
}

