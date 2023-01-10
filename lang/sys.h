#pragma once

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

#include "core.h"



void sysSleep (); 
void sysExit ();
void sysExec ();
