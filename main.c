#include "lang/def.h"
extern void setInstructions ();




int main (int argc, char *argv[]) {
	setInstructions ();

	for (size_t i = 0; i < argc; i++) {
		char str[6] = "argv"; str[4] = ('0' + i);
		dict.set (str, (size_t) argv[i]);
	}

	for (; ; )
		eval ();

}
