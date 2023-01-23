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
	dict.set (string.store ("define"),	(size_t) coreDefine,	callable);
	dict.set (string.store ("eval"),	(size_t) coreEval,	callable);
	dict.set (string.store ("not"),		(size_t) coreNot,	callable);
	dict.set (string.store ("if"),		(size_t) coreCond,	callable);
	dict.set (string.store ("input"), 	(size_t) coreInput,	callable);

	dict.set (string.store ("string"),	(size_t) strString,	callable);
	dict.set (string.store ("skip"),	(size_t) strSkip,	callable);
	dict.set (string.store ("piks"),	(size_t) strPiks,	callable);
	dict.set (string.store ("conc"),	(size_t) strConc,	callable);

	dict.set (string.store ("int"),		(size_t) mathInt,	callable);
	dict.set (string.store ("add"), 	(size_t) mathAdd,	callable);
	dict.set (string.store ("sub"), 	(size_t) mathSub,	callable);
	dict.set (string.store ("mul"), 	(size_t) mathMul,	callable);
	dict.set (string.store ("div"), 	(size_t) mathDiv,	callable);

	dict.set (string.store ("open"),	(size_t) fileOpen,	callable);
	dict.set (string.store ("close"),	(size_t) fileClose,	callable);
	dict.set (string.store ("read"),	(size_t) fileRead,	callable);
	dict.set (string.store ("write"),	(size_t) fileWrite,	callable);

	dict.set (string.store ("print"),	(size_t) outPrint,	callable);

	dict.set (string.store ("sleep"),	(size_t) sysSleep,	callable);
	dict.set (string.store ("exit"),	(size_t) sysExit,	callable);
	dict.set (string.store ("exec"),	(size_t) sysExec,	callable);
	dict.set (string.store ("fork"),	(size_t) sysFork,	callable);
	dict.set (string.store ("pipe"),	(size_t) sysPipe,	callable);
}
