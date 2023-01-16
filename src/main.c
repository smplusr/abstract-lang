#include <signal.h>
#include "def.h"

extern void setInstructions ();




int main (int argc, char *argv[]) {
	int i; 

	setInstructions ();	
	signal (SIGINT, SIG_IGN);

	for (i = 0; i < argc; i++) {
		char str[6] = "argv"; str[4] = ('0' + i);
		dict.set (string.store (str), (size_t) argv[i]);
	}

	if (argc >= 2)
		stream.update (argv[1]);

	for (; ; )
		coreEval ();
}
