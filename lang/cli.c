#include "cli.h"



void cliPrint () { printf ("%s\n", (char *) eval ()); }
void cliDump () { printf ("0x%lx\n", eval ()); }
