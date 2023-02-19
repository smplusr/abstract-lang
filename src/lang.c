#include "lang.h"




size_t langUpdate (lang_t *lang) {
	char *word = lang->string->getWord (lang->string, "\n\t ");
	
	pair_t *pair = (pair_t *) lang->dict->get (lang->dict, word);

	return (pair)
		? (pair->value.type == func)
			? (size_t) (*(void *(*) ()) pair->value.data) (lang)
			: (size_t) pair->value.data
		: (size_t) word;
}


#ifdef DEBUG_LANG
void langDebug (lang_t *lang) {
#ifdef DEBUG_DICT
	printf ("\n");
	lang->dict->debug (lang->dict);
#endif
#ifdef DEBUG_STRING
	printf ("\n");
	lang->string->debug (lang->string);
#endif
#ifdef DEBUG_STREAM
	printf ("\n");
	lang->string->stream->debug (lang->string->stream);
#endif
	printf ("\n");
}
#endif

void langDestroy (lang_t **lang) {
	(*lang)->string->destroy (&(*lang)->string);
	(*lang)->dict->destroy (&(*lang)->dict);
	free (*lang);
	*lang = (lang_t *) NULL;
}
lang_t *Lang () {
	lang_t *lang = (lang_t *) malloc (sizeof (lang_t));

	lang->dict = Dict ();
	lang->string = String ();

	lang->destroy = langDestroy;
	lang->update = langUpdate;



#ifdef DEBUG_LANG
	lang->debug = langDebug;
	lang->dict->set (lang->dict, lang->string->store (lang->string, "debug"), (size_t) lang->debug, func);
#endif


#ifdef LANG_STAT
	lang->dict->set (lang->dict, lang->string->store (lang->string, "stat"), (size_t) statOpen, func);
#ifdef LANG_MODE
	lang->dict->set (lang->dict, lang->string->store (lang->string, "perm"), (size_t) statMode, func);
#endif
	lang->dict->set (lang->dict, lang->string->store (lang->string, "size"), (size_t) statSize, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "blocks"), (size_t) statBlocks, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "atime"), (size_t) statAccess, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "mtime"), (size_t) statModify, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "ctime"), (size_t) statChange, func);
#endif


#ifdef LANG_NET
	lang->dict->set (lang->dict, lang->string->store (lang->string, "address"), (size_t) netAddress, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "socket"), (size_t) netSocket, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "send"), (size_t) netSend, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "broadcast"), (size_t) netBroadcast, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "bind"), (size_t) netBind, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "receive"), (size_t) netReceive, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "close"), (size_t) netClose, func);
#endif


#ifdef LANG_MODE
	lang->dict->set (lang->dict, lang->string->store (lang->string, "mode"), (size_t) modeConvert, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "chmod"), (size_t) modeChange, func);
#endif


#ifdef LANG_TIME
	lang->dict->set (lang->dict, lang->string->store (lang->string, "now"), (size_t) timeNow, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "time"), (size_t) timeConvert, func);
#endif


#ifdef LANG_DIRECTORY
	lang->dict->set (lang->dict, lang->string->store (lang->string, "opendir"), (size_t) dirOpen, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "closedir"), (size_t) dirClose, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "readdir"), (size_t) dirRead, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "mkdir"), (size_t) dirMake, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "rmdir"), (size_t) dirRemove, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "cd"), (size_t) dirChange, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "pwd"), (size_t) dirCurrent, func);
#endif


#ifdef LANG_FILE
	lang->dict->set (lang->dict, lang->string->store (lang->string, "open"), (size_t) fileOpen, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "read"), (size_t) fileRead, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "write"), (size_t) fileWrite, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "fclose"), (size_t) fileClose, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "rm"), (size_t) fileRemove, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "touch"), (size_t) fileCreate, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "access"), (size_t) fileAccess, func);
#endif


#ifdef LANG_SYSTEM
	lang->dict->set (lang->dict, lang->string->store (lang->string, "exit"), (size_t) sysExit, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "sleep"), (size_t) sysSleep, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "exec"), (size_t) sysExec, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "fork"), (size_t) sysFork, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "wait"), (size_t) sysWait, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "pipe"), (size_t) sysPipe, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "kill"), (size_t) sysKill, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "reboot"), (size_t) sysReboot, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "mount"), (size_t) sysMount, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "umount"), (size_t) sysUnmount, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "ln"), (size_t) sysSymlink, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "sync"), (size_t) sysSync, func);
#endif


#ifdef LANG_EXTRA
	lang->dict->set (lang->dict, lang->string->store (lang->string, "print"), (size_t) outPrint, func);	
#endif
	lang->dict->set (lang->dict, lang->string->store (lang->string, "put"), (size_t) outPut, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "clear"), (size_t) outClear, func);


	lang->dict->set (lang->dict, lang->string->store (lang->string, "int"), (size_t) mathCharToInt, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "char"), (size_t) mathIntToChar, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "add"), (size_t) mathAdd, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "sub"), (size_t) mathSub, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "mul"), (size_t) mathMul, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "div"), (size_t) mathDiv, func);


	lang->dict->set (lang->dict, lang->string->store (lang->string, "string"), (size_t) strString, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "conc"), (size_t) strConc, func);
#ifdef LANG_EXTRA
	lang->dict->set (lang->dict, lang->string->store (lang->string, "quote"), (size_t) strQuote, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "seek"), (size_t) strSeek, func);
#endif


	lang->dict->set (lang->dict, lang->string->store (lang->string, "define"), (size_t) coreDefine, func);
#ifdef LANG_EXTRA
	lang->dict->set (lang->dict, lang->string->store (lang->string, "value"), (size_t) coreValue, func);
#endif
	lang->dict->set (lang->dict, lang->string->store (lang->string, "eval"), (size_t) coreEval, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "not"), (size_t) coreNot, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "if"), (size_t) coreCond, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "input"), (size_t) coreInput, func);
	lang->dict->set (lang->dict, lang->string->store (lang->string, "delete"), (size_t) coreDelete, func);

	return lang;
}
