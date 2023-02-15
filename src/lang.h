#pragma once

#include "dict.h"
#include "string.h"


#ifdef LANG_ALL
#define LANG_EXTRA
#define LANG_FILE
#define LANG_SYSTEM
#define LANG_DIRECTORY
#define LANG_TIME
#define LANG_STAT
#define LANG_MODE
#define LANG_NET
#endif

#define SYSTEM_FAIL -1
#define LOG_ERR perror (NULL);
#define SYSTEM_CHECK(X) if ((X) == SYSTEM_FAIL) LOG_ERR
#define FAIL_IF_NULL(X) if (!(X)) { LOG_ERR return (size_t) NULL; }



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
void coreFree (lang_t *lang);

char *strSpace (void);
char *strQuote (lang_t *);
char *strString (lang_t *);
char *strConc (lang_t *);
char *strSeek (lang_t *);

void outPrint (lang_t *);
void outPut (lang_t *);
void outClear (void);

/*double mathIntToFloat (size_t);
size_t mathFloatToInt (double);*/
size_t mathCharToInt (lang_t *);
char *mathIntToChar (lang_t *);
size_t mathAdd (lang_t *);
size_t mathSub (lang_t *);
size_t mathMul (lang_t *);
size_t mathDiv (lang_t *);

FILE *fileOpen (lang_t *);
char *fileRead (lang_t *);
void fileCreate (lang_t *);
void fileWrite (lang_t *);
void fileClose (lang_t *);
size_t fileAccess (lang_t *);
void fileRemove (lang_t *);

void sysExit (lang_t *);
void sysSleep (lang_t *);
void sysExec (lang_t *);
void sysFork (lang_t *);
void sysWait (void);
char *sysPipe (lang_t *);
void sysReboot (void);
void sysMount (lang_t *);
void sysUnmount (lang_t *);
void sysSymlink (lang_t *);
#ifdef _BSD_SOURCE
void sysSync (void);
#else
void sysSync (lang_t *);
#endif

void *dirOpen (lang_t *);
void dirClose (lang_t *);
char *dirRead (lang_t *);
void dirMake (lang_t *);
void dirRemove (lang_t *);
void dirChange (lang_t *);
char *dirCurrent (lang_t *);

void *timeNow (void);
char *timeConvert (lang_t *);

char *modeConvert (lang_t *);
void modeChange (lang_t *);

void *statOpen (lang_t *);
size_t statMode (lang_t *);
size_t statSize (lang_t *);
size_t statBlocks (lang_t *);
size_t statAccess (lang_t *);
size_t statModify (lang_t *);
size_t statChange (lang_t *);

size_t netAddress (lang_t *);
size_t netBroadcast (lang_t *);
size_t netSocket (void);
void netSend (lang_t *);
size_t netBind (lang_t *);
char *netReceive (lang_t *);
void netClose (lang_t *);
