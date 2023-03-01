#include "include.h"

#ifdef LANG_SYSTEM

#include <sys/reboot.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>





int pipefd[2];
bool wtrigger = 0;





void SysSleep (lang_t *lang) { SYSTEM_CHECK (usleep ((size_t) lang->update (lang) * 1000)); }
void SysExit (lang_t *lang) {
	exit ((size_t) lang->update (lang));
}

void SysExec (lang_t *lang) {
	char *argv[16], *str;
	size_t argc = 0;
	
	str = strtok ((char *) lang->update (lang), " ");
	for (; str != NULL; argc++) {
		argv[argc] = str;
		str = strtok (NULL, " ");
	}

	argv[argc] = (char *) NULL;

	if (pipefd[0])
		dup2 (pipefd[1], STDOUT_FILENO);

	SYSTEM_CHECK (execvp (argv[0], argv));
}

void *SysFork (lang_t *lang) {
	pid_t pid;
	int status = 0;

	signal (SIGCHLD, SIG_IGN);

	if ((pid = fork ()) == 0) {
		lang->update (lang);
		return NULL;
	}

	if (wtrigger) { wtrigger = false; wait (&status); }
	free (lang->word (lang, WORD_END));		/* ignore word */

	return (void *) (size_t) pid;
}

char *SysPipe (lang_t *lang) {
	char *data = (char *) malloc (4096 * sizeof (char));
	
	SYSTEM_CHECK (pipe (pipefd));

	if (!pipefd[0])
		return (char *) NULL;

	lang->update (lang);

	read (pipefd[0], data, sizeof (data));
	close (pipefd[0]); close (pipefd[1]);
	return lang->uniquestr (lang, data);
}

void SysWait (void) { wtrigger = true; }

void SysKill (lang_t *lang) {
	pid_t pid = (pid_t) (size_t) lang->update (lang);
	if (pid) kill (pid, SIGSEGV);
} 

void SysReboot (void) { sync (); SYSTEM_CHECK (reboot (0x4321fedc)); }




#endif
