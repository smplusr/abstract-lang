#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include "lang.h"



int pipefd[2]; 

void sysSleep (lang_t *lang) { sleep ((double) lang->update (lang)); }
void sysExit (lang_t *lang) { exit ((double) lang->update (lang)); }

void sysExec (lang_t *lang) {
	char *argv[16] = {NULL};	
	size_t i = 0, argc = (size_t) lang->update (lang); 
	
	for (; i <= argc; i++)
		argv[i] = (char *) lang->update (lang);

	if (pipefd[0])
		dup2 (pipefd[1], STDOUT_FILENO);

	if (execvp (argv[0], argv) == EOF)
		perror (NULL);	
}


size_t sysFork (lang_t *lang) {
	pid_t pid;
	
	signal (SIGCHLD, SIG_IGN);
	if ((pid = fork ()) == EOF)
		perror (NULL); 

	if (!pid) {
		lang->update (lang);
		return (size_t) NULL;
	}

	lang->string->getWord (lang->string, WORD_END);		/* ignore word */
	return (size_t) pid;
}


char *sysPipe (lang_t *lang) {
	char data[BUFF_SIZE];
	
	if (pipe (pipefd) == EOF) {
		perror (NULL);
		return (char *) NULL;
	}

	lang->update (lang);

	read (pipefd[0], data, sizeof (data));
	close (pipefd[0]); close (pipefd[1]);
	return lang->string->store (lang->string, data);
}


void sysReboot (void) {
	reboot (0x4321fedc);
}

/* Does not work, needs a working implementation
 * Also needs unmount functions
 */
void sysMount (lang_t *lang) {
	if (mount ((char *) lang->update (lang), (char *) lang->update (lang), (char *) lang->update (lang), 0, NULL))
		perror ("");
}
