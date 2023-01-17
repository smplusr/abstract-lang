#pragma once

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

#include "core.h"




extern int pipefd[2]; 

void sysSleep (); 
void sysExit ();
void sysExec ();
pid_t sysFork ();
char *sysPipe ();
