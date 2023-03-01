#include "include.h"




char *mainRead (FILE *file) {
	char *ctn; size_t len;

	if (!file) return (char *) NULL;

	fseek (file, 0L, SEEK_END);
	len = ftell (file);
	fseek (file, 0L, SEEK_SET);

	ctn = (char *) malloc (len * sizeof (char));
	fread (ctn, len, sizeof (char), file);
	fclose (file);

	ctn[len] = '\0';
	return ctn;
}




int main (int argc, char *argv[]) {

	lang_t *lang = Lang ();

	LoadFunctions (lang);


	if (argc > 1)
		lang->stream = mainRead (fopen (argv[1], "rb"));

	for (; ; )
		lang->update (lang);



	return 0;
}




void LoadFunctions (lang_t *lang) {
#ifdef LANG_NETWORKING
	lang->map->insert (lang->map, TypedPair ("receive",	(void *) (size_t) NetReceive, 0x1));
	lang->map->insert (lang->map, TypedPair ("bind",	(void *) (size_t) NetBind, 0x1));
	lang->map->insert (lang->map, TypedPair ("send",	(void *) (size_t) NetSend, 0x1));
	lang->map->insert (lang->map, TypedPair ("socket",	(void *) (size_t) NetSocket, 0x1));
	lang->map->insert (lang->map, TypedPair ("broadcast",	(void *) (size_t) NetBroadcast, 0x1));
	lang->map->insert (lang->map, TypedPair ("address",	(void *) (size_t) NetAddress, 0x1));
#endif 
#ifdef LANG_FILE
	lang->map->insert (lang->map, TypedPair ("cwd",		(void *) (size_t) DirCurrent, 0x1));
	lang->map->insert (lang->map, TypedPair ("cd",		(void *) (size_t) DirChange, 0x1));
	lang->map->insert (lang->map, TypedPair ("mkdir",	(void *) (size_t) DirMake, 0x1));
	lang->map->insert (lang->map, TypedPair ("readdir",	(void *) (size_t) DirRead, 0x1));
	lang->map->insert (lang->map, TypedPair ("opendir",	(void *) (size_t) DirOpen, 0x1));

	lang->map->insert (lang->map, TypedPair ("ln",		(void *) (size_t) FsSymlink, 0x1));
	lang->map->insert (lang->map, TypedPair ("umount",	(void *) (size_t) FsUmount, 0x1));
	lang->map->insert (lang->map, TypedPair ("mount",	(void *) (size_t) FsMount, 0x1));
	lang->map->insert (lang->map, TypedPair ("remove",	(void *) (size_t) FsRemove, 0x1));
	lang->map->insert (lang->map, TypedPair ("close",	(void *) (size_t) FsClose, 0x1));
	
	lang->map->insert (lang->map, TypedPair ("write",	(void *) (size_t) FileWrite, 0x1));
	lang->map->insert (lang->map, TypedPair ("read",	(void *) (size_t) FileRead, 0x1));
	lang->map->insert (lang->map, TypedPair ("open",	(void *) (size_t) FileOpen, 0x1));
#endif
#ifdef LANG_SYSTEM
	lang->map->insert (lang->map, TypedPair ("reboot",	(void *) (size_t) SysReboot, 0x1));
	lang->map->insert (lang->map, TypedPair ("kill",	(void *) (size_t) SysKill, 0x1));
	lang->map->insert (lang->map, TypedPair ("wait",	(void *) (size_t) SysWait, 0x1));
	lang->map->insert (lang->map, TypedPair ("pipe",	(void *) (size_t) SysPipe, 0x1));
	lang->map->insert (lang->map, TypedPair ("fork",	(void *) (size_t) SysFork, 0x1));
	lang->map->insert (lang->map, TypedPair ("exec",	(void *) (size_t) SysExec, 0x1));
	lang->map->insert (lang->map, TypedPair ("sleep",	(void *) (size_t) SysSleep, 0x1));
	lang->map->insert (lang->map, TypedPair ("exit",	(void *) (size_t) SysExit, 0x1));
#endif

	lang->map->insert (lang->map, TypedPair ("div",		(void *) (size_t) MathDiv, 0x1));	
	lang->map->insert (lang->map, TypedPair ("mul",		(void *) (size_t) MathMul, 0x1));
	lang->map->insert (lang->map, TypedPair ("sub",		(void *) (size_t) MathSub, 0x1));
	lang->map->insert (lang->map, TypedPair ("add",		(void *) (size_t) MathAdd, 0x1));
	lang->map->insert (lang->map, TypedPair ("char",	(void *) (size_t) MathChar, 0x1));
	lang->map->insert (lang->map, TypedPair ("int",		(void *) (size_t) MathInteger, 0x1));


	lang->map->insert (lang->map, TypedPair ("put",		(void *) (size_t) CorePut, 0x1));
	lang->map->insert (lang->map, TypedPair ("input",	(void *) (size_t) CoreInput, 0x1));
	lang->map->insert (lang->map, TypedPair ("length",	(void *) (size_t) CoreLength, 0x1));
	lang->map->insert (lang->map, TypedPair ("skip",	(void *) (size_t) CoreSkip, 0x1));
	lang->map->insert (lang->map, TypedPair ("cut",		(void *) (size_t) CoreCut, 0x1));
	lang->map->insert (lang->map, TypedPair ("cat",		(void *) (size_t) CoreCat, 0x1));
	lang->map->insert (lang->map, TypedPair ("string",	(void *) (size_t) CoreString, 0x1));


	lang->map->insert (lang->map, TypedPair ("delete",	(void *) (size_t) CoreDelete, 0x1));
	lang->map->insert (lang->map, TypedPair ("not",		(void *) (size_t) CoreNot, 0x1));
	lang->map->insert (lang->map, TypedPair ("if",		(void *) (size_t) CoreCond, 0x1));	
	lang->map->insert (lang->map, TypedPair ("eval",	(void *) (size_t) CoreEval, 0x1));	
	lang->map->insert (lang->map, TypedPair ("define",	(void *) (size_t) CoreDefine, 0x1));
}

