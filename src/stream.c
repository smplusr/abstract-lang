#include "stream.h"




char *streamGet () { return stream.data; }
char streamUpdate (char *data) {
	if (data)
		return (bool) (stream.data = data);

	return (stream.data && *stream.data)
		? *stream.data++
		: fgetc (stdin);
}


init_stream (stream);
