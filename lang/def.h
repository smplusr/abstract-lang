#pragma once

#include "../dict.h"
#include "../string.h"
#include "../stream.h"

#include "core.h"
#include "cli.h"
#include "str.h"
#include "math.h"
#include "file.h"
#include "sys.h"


void setInstructions () {
	dict.set (string.store ("data"), (size_t) data);
	dict.set (string.store ("define"), (size_t) define);
	dict.set (string.store ("if"), (size_t) condition);
	dict.set (string.store ("eval"), (size_t) interpret);

	dict.set (string.store ("print"), (size_t) cliPrint);

	dict.set (string.store ("word"), (size_t) strWord);
	dict.set (string.store ("string"), (size_t) strString);
	dict.set (string.store ("int"), (size_t) strAtoi);

	dict.set (string.store ("add"), (size_t) mathAdd);
	dict.set (string.store ("sub"), (size_t) mathSub);
	dict.set (string.store ("mul"), (size_t) mathMul);
	dict.set (string.store ("div"), (size_t) mathDiv);

	dict.set (string.store ("open"), (size_t) fileOpen);
	dict.set (string.store ("close"), (size_t) fileClose);
	dict.set (string.store ("read"), (size_t) fileRead);
	dict.set (string.store ("write"), (size_t) fileWrite);

	dict.set (string.store ("sleep"), (size_t) sysSleep);
	dict.set (string.store ("exit"), (size_t) sysExit);
	dict.set (string.store ("exec"), (size_t) sysExec);
}
