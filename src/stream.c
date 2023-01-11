#include "stream.h"


char update (char *data) {
	if (data)
		return (bool) (stream.data = data);

	return (stream.data && *stream.data)
		? *stream.data++
		: fgetc (stdin);
}


init_stream (stream);
