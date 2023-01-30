#include "stream.h"




char *streamGet (stream_t *stream) { return stream->data; }
void streamSet (stream_t *stream, char *data) { stream->data = data; }
char streamUpdate (stream_t *stream) {
	return (stream->data && *stream->data)
		? *stream->data++
		: fgetc (stdin);
}

#ifdef DEBUG_STREAM
void streamDebug (stream_t *stream) {
	printf ("--== Debugging Stream ==--\n");
	printf ("Current stream : %s\n", stream->data);
}
#endif

void streamDestroy (stream_t **stream) { free (*stream); stream = NULL; }
stream_t *Stream () {
	stream_t *stream = (stream_t *) malloc (sizeof (stream_t));

	stream->destroy = streamDestroy;

	stream->get = streamGet;
	stream->set = streamSet;
	stream->update = streamUpdate;

#ifdef DEBUG_STREAM
	stream->debug = streamDebug;
#endif

	return stream;
}
