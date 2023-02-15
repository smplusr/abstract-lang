#include "lang.h"

#ifdef LANG_SYSTEM

#include <sys/reboot.h>
#include <sys/types.h>
#include <sys/mount.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>




int pipefd[2];
bool wtrigger = 0;


#ifdef _BSD_SOURCE
void sysSleep (lang_t *lang) { usleep (lang->update (lang) * 1000000); }
void sysSync (void) { sync (); }
#else
void sysSleep (lang_t *lang) { sleep (lang->update (lang)); }
void sysSync (lang_t *lang) {
	char *name = (char *) lang->update (lang);
	int fd;
	
	SYSTEM_CHECK ((fd = open (name, O_RDONLY)))
	SYSTEM_CHECK (fsync (fd));
}
#endif


void sysExit (lang_t *lang) { exit (lang->update (lang)); }

void sysExec (lang_t *lang) {
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

	SYSTEM_CHECK (execvp (argv[0], argv))
}

void sysFork (lang_t *lang) {
	int status = 0;

	signal (SIGCHLD, SIG_IGN);

	if (fork () == 0) {
		lang->update (lang);
		return;
	}

	if (wtrigger) { wtrigger = false; wait (&status); }
	lang->string->getWord (lang->string, WORD_END);		/* ignore word */
}

void sysWait (void) { wtrigger = true; }

char *sysPipe (lang_t *lang) {
	char data[BUFF_SIZE];
	
	SYSTEM_CHECK (pipe (pipefd))

	if (!pipefd[0])
		return (char *) NULL;

	lang->update (lang);

	read (pipefd[0], data, sizeof (data));
	close (pipefd[0]); close (pipefd[1]);
	return lang->string->store (lang->string, data);
}


void sysReboot (void) {
#ifdef _BSD_SOURCE
	sync ();
#endif
	SYSTEM_CHECK (reboot (0x4321fedc))
}

void sysMount (lang_t *lang) {
	char *src = (char *) lang->update (lang),
	     *target = (char *) lang->update (lang),
	     *type = (char *) lang->update (lang);

	SYSTEM_CHECK (mount (src, target, type, (size_t) NULL, (char *) NULL));
}

void sysUnmount (lang_t *lang) {
	SYSTEM_CHECK (umount ((char *) lang->update (lang)));
}

void sysSymlink (lang_t *lang) {
	char *base = (char *) lang->update (lang),
	     *link = (char *) lang->update (lang);
	SYSTEM_CHECK (symlink (base, link));
}






#endif
