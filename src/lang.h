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

FILE *fileOpen (lang_t *);
char *fileRead (lang_t *);
void fileWrite (lang_t *);
void fileClose (lang_t *);

size_t mathCharToInt (lang_t *);
char *mathIntToChar (lang_t *);
size_t mathAdd (lang_t *);
size_t mathSub (lang_t *);
size_t mathMul (lang_t *);
size_t mathDiv (lang_t *);

void sysExit (lang_t *);
void sysSleep (lang_t *);
void sysExec (lang_t *);
size_t sysFork (lang_t *);
char *sysPipe (lang_t *);
