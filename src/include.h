#pragma once

#include "lang.h"

#define SYSTEM_FAILURE -1
#define SYSTEM_CHECK(X) (((int) (X) == (int) SYSTEM_FAILURE) ? perror (NULL) : (void) NULL)

#ifdef LANG_ALL
#define LANG_SYSTEM
#define LANG_FILE
#define LANG_NETWORKING
#endif





void LoadFunctions (lang_t *);




void CoreDefine (lang_t *);
void CoreDelete (lang_t *);
void CoreEval (lang_t *);

void *CoreNot (lang_t *);
void CoreCond (lang_t *);

char *CoreString (lang_t *);
char *CoreCat (lang_t *);
char *CoreCut (lang_t *);
char *CoreSplit (lang_t *);
char *CoreSplit (lang_t *);
char *CoreSkip (lang_t *);
size_t CoreLength (lang_t *);

void CorePut (lang_t *);
char *CoreInput (lang_t *);




void *MathInteger (lang_t *);
char *MathChar (lang_t *);
void *MathAdd (lang_t *);
void *MathSub (lang_t *);
void *MathMul (lang_t *);
void *MathDiv (lang_t *);




/*	Float
double MathFloat (void *);
void *MathInt (double);

char *MathChar (lang_t *);
void *MathDecimal (lang_t *);

void *MathAdd (lang_t *);
void *MathSub (lang_t *);
void *MathMul (lang_t *);
*/




#ifdef LANG_SYSTEM
void SysExit (lang_t *);

void SysSleep (lang_t *);

void SysExec (lang_t *);
void *SysFork (lang_t *);
char *SysPipe (lang_t *);

void SysWait (void);
void SysKill (lang_t *);

void SysReboot (void);
#endif




#ifdef LANG_FILE
FILE *FileOpen (lang_t *);
char *FileRead (lang_t *);
void FileWrite (lang_t *);
void FileClose (lang_t *);

void FsClose (lang_t *);
void FsRemove (lang_t *);
void FsMount (lang_t *);
void FsUmount (lang_t *);
void FsSymlink (lang_t *);

void *DirOpen (lang_t *);
char *DirRead (lang_t *);
void DirClose (lang_t *);
void DirMake (lang_t *);
void DirChange (lang_t *);
char *DirCurrent (lang_t *);
#endif



#ifdef LANG_NETWORKING
size_t NetAddress (lang_t *);
size_t NetBroadcast (lang_t *);
size_t NetSocket (void);
void NetSend (lang_t *);
size_t NetBind (lang_t *);
char *NetReceive (lang_t *);
#endif
