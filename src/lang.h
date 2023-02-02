#pragma once

#include "dict.h"
#include "string.h"




typedef struct lang_t lang_t;
struct lang_t {
	dict_t *dict;
	string_t *string;

	void (*destroy) (lang_t **);
	size_t (*update) (lang_t *);

#ifdef DEBUG_LANG
	void (*debug) (lang_t *);
#endif
};

lang_t *Lang ();



void coreDefine (lang_t *);
size_t coreValue (lang_t *);
void coreEval (lang_t *);
size_t coreNot (lang_t *);
void coreCond (lang_t *);
char *coreInput (lang_t *);
void coreDelete (lang_t *);

char *strString (lang_t *);
char *strConc (lang_t *);
char *strSeek (lang_t *);

void outPrint (lang_t *);
void outClear (void);

#include <sys/stat.h>
FILE *fileOpen (lang_t *);
char *fileRead (lang_t *);
void fileWrite (lang_t *);
void fileClose (lang_t *);
void fileRemove (lang_t *);

size_t mathCharToInt (lang_t *);
char *mathIntToChar (lang_t *);
size_t mathAdd (lang_t *);
size_t mathSub (lang_t *);
size_t mathMul (lang_t *);
size_t mathDiv (lang_t *);

#include <sys/reboot.h>
#include <sys/mount.h>
#include <unistd.h>
void sysExit (lang_t *);
void sysSleep (lang_t *);
void sysExec (lang_t *);
size_t sysFork (lang_t *);
char *sysPipe (lang_t *);
void sysReboot (void);
void sysMount (lang_t *);

#include <dirent.h>
#include <unistd.h>
DIR *dirOpen (lang_t *);
void dirClose (lang_t *);
char *dirRead (lang_t *);
void dirMake (lang_t *);
void dirRemove (lang_t *);
void dirChange (lang_t *);
char *dirCurrent (lang_t *);
