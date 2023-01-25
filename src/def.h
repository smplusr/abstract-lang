#pragma once

#include "dict.h"
#include "string.h"
#include "stream.h"

#include "core.h"
#include "str.h"
#include "math.h"
#include "file.h"
#include "out.h"
#include "sys.h"


void setInstructions () {
	dict.set (string.store ("define"),	(size_t) coreDefine,	cal);
	dict.set (string.store ("value"),	(size_t) coreValue,	cal);
	dict.set (string.store ("eval"),	(size_t) coreEval,	cal);
	dict.set (string.store ("not"),		(size_t) coreNot,	cal);
	dict.set (string.store ("if"),		(size_t) coreCond,	cal);
	dict.set (string.store ("input"), 	(size_t) coreInput,	cal);

	dict.set (string.store ("delete"), 	(size_t) coreDelete,	cal);
	dict.set (string.store ("remove"), 	(size_t) strRemove,	cal);

	dict.set (string.store ("string"),	(size_t) strString,	cal);
	dict.set (string.store ("skip"),	(size_t) strSkip,	cal);
	dict.set (string.store ("piks"),	(size_t) strPiks,	cal);
	dict.set (string.store ("conc"),	(size_t) strConc,	cal);
	dict.set (string.store ("seek"),	(size_t) strSeek,	cal);

	dict.set (string.store ("int"),		(size_t) mathInt,	cal);
	dict.set (string.store ("add"), 	(size_t) mathAdd,	cal);
	dict.set (string.store ("sub"), 	(size_t) mathSub,	cal);
	dict.set (string.store ("mul"), 	(size_t) mathMul,	cal);
	dict.set (string.store ("div"), 	(size_t) mathDiv,	cal);

	dict.set (string.store ("open"),	(size_t) fileOpen,	cal);
	dict.set (string.store ("close"),	(size_t) fileClose,	cal);
	dict.set (string.store ("read"),	(size_t) fileRead,	cal);
	dict.set (string.store ("write"),	(size_t) fileWrite,	cal);

	dict.set (string.store ("print"),	(size_t) outPrint,	cal);

	dict.set (string.store ("sleep"),	(size_t) sysSleep,	cal);
	dict.set (string.store ("exit"),	(size_t) sysExit,	cal);
	dict.set (string.store ("exec"),	(size_t) sysExec,	cal);
	dict.set (string.store ("fork"),	(size_t) sysFork,	cal);
	dict.set (string.store ("pipe"),	(size_t) sysPipe,	cal);
}
