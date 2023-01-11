#include "math.h"




size_t mathInt () {
	char str[BUFF_SIZE];
	return (size_t) atoi (getword (str, STRING_END));
}

size_t mathAdd () { return (double) eval () + (double) eval (); }
size_t mathSub () { return (double) eval () - (double) eval (); }
size_t mathMul () { return (double) eval () * (double) eval (); }
size_t mathDiv () { return (double) eval () / (double) eval (); }
