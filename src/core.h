#pragma once

#include <stddef.h>

#include "dict.h"
#include "string.h"
#include "str.h"


#define WORD_LEN 16




size_t coreUpdate ();
void coreEval ();
void coreDefine ();
bool coreNot ();
void coreCond ();
char *coreInput ();
