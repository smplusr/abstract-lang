#pragma once

#include <stddef.h>

#include "dict.h"
#include "string.h"


#define WORD_LEN 16




size_t coreVar ();
size_t coreEval ();
void coreDefine ();
bool coreNot ();
void coreCond ();
void coreEvaluate ();
