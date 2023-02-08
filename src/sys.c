#include "lang.h"

#ifdef LANG_SYSTEM

#include <sys/reboot.h>
#include <sys/types.h>
#include <sys/mount.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>



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

	ERROR_CHECK (execvp (argv[0], argv))
}


size_t sysFork (lang_t *lang) {
	pid_t pid;
	
	signal (SIGCHLD, SIG_IGN);
	ERROR_CHECK ((pid = fork ()))

	if (!pid) {
		lang->update (lang);
		return (size_t) NULL;
	}

	lang->string->getWord (lang->string, WORD_END);		/* ignore word */
	return (size_t) pid;
}


char *sysPipe (lang_t *lang) {
	char data[BUFF_SIZE];
	
	ERROR_CHECK (pipe (pipefd))

	if (!pipefd[0])
		return (char *) NULL;

	lang->update (lang);

	read (pipefd[0], data, sizeof (data));
	close (pipefd[0]); close (pipefd[1]);
	return lang->string->store (lang->string, data);
}

void sysReboot (void) {
	ERROR_CHECK (reboot (0x4321fedc))
}

void sysMount (lang_t *lang) {
	char *src = (char *) lang->update (lang),
	     *target = (char *) lang->update (lang),
	     *type = (char *) lang->update (lang);

	ERROR_CHECK (mount (src, target, type, (size_t) NULL, (char *) NULL/*"mode=0700,uid=65534"*/));
}

void sysUnmount (lang_t *lang) {
	ERROR_CHECK (umount ((char *) lang->update (lang)));
}

void sysSymlink (lang_t *lang) {
	char *base = (char *) lang->update (lang),
	     *link = (char *) lang->update (lang);
	ERROR_CHECK (symlink (base, link));
}

void sysSync (lang_t *lang) {
	char *name = (char *) lang->update (lang);
	int fd;
	
	ERROR_CHECK ((fd = open (name, O_RDONLY)))
	ERROR_CHECK (fsync (fd));
}





#endif
