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
	dict.set (string.store ("var"),		(size_t) coreVar);
	dict.set (string.store ("define"),	(size_t) coreDefine);
	dict.set (string.store ("not"),		(size_t) coreNot);
	dict.set (string.store ("if"),		(size_t) coreCond);
	dict.set (string.store ("eval"),	(size_t) coreEvaluate);

	dict.set (string.store ("word"),	(size_t) strWord);
	dict.set (string.store ("string"),	(size_t) strString);
	dict.set (string.store ("remove"),	(size_t) strRemove);
	dict.set (string.store ("skip"),	(size_t) strSkip);
	dict.set (string.store ("piks"),	(size_t) strPiks);
	dict.set (string.store ("conc"),	(size_t) strConc);

	dict.set (string.store ("int"),		(size_t) mathInt);
	dict.set (string.store ("add"), 	(size_t) mathAdd);
	dict.set (string.store ("sub"), 	(size_t) mathSub);
	dict.set (string.store ("mul"), 	(size_t) mathMul);
	dict.set (string.store ("div"), 	(size_t) mathDiv);

	dict.set (string.store ("open"),	(size_t) fileOpen);
	dict.set (string.store ("close"),	(size_t) fileClose);
	dict.set (string.store ("read"),	(size_t) fileRead);
	dict.set (string.store ("write"),	(size_t) fileWrite);

	dict.set (string.store ("print"),	(size_t) outPrint);

	dict.set (string.store ("sleep"),	(size_t) sysSleep);
	dict.set (string.store ("exit"),	(size_t) sysExit);
	dict.set (string.store ("exec"),	(size_t) sysExec);
	dict.set (string.store ("fork"),	(size_t) sysFork);
	dict.set (string.store ("pipe"),	(size_t) sysPipe);
}
