#include "math.h"




size_t mathInt () {
	char *str = (char *) coreUpdate ();
	return (str)
		? (size_t) atoi (str)
		: (size_t) NULL;
}

size_t mathAdd () { return (double) coreUpdate () + (double) coreUpdate (); }
size_t mathSub () { return (double) coreUpdate () - (double) coreUpdate (); }
size_t mathMul () { return (double) coreUpdate () * (double) coreUpdate (); }
size_t mathDiv () { return (double) coreUpdate () / (double) coreUpdate (); }
