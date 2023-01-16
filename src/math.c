#include "math.h"




size_t mathInt () {
	char str[BUFF_SIZE];
	return (size_t) atoi (getword (str, WORD_END));
}

size_t mathAdd () { return (double) coreEval () + (double) coreEval (); }
size_t mathSub () { return (double) coreEval () - (double) coreEval (); }
size_t mathMul () { return (double) coreEval () * (double) coreEval (); }
size_t mathDiv () { return (double) coreEval () / (double) coreEval (); }
