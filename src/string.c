#include "string.h"




token_t *stringFind (string_t *string, char *str) {
	size_t hash = string->djb2Hash (str);
	node_t *node = string->list->head;
	token_t *ptr;

	if (!node)
		return (token_t *) NULL;

	for (; node; node = node->next)
		if (node->data) {
			ptr = (token_t *) node->data;
			if (ptr->hash == hash)
				return ptr;
		}

	return (token_t *) NULL;
}


char *stringStore (string_t *string, char *str) {
	token_t *ptr = string->find (string, str);
	if (!ptr) {
		ptr = (token_t *) malloc (sizeof (token_t));
		ptr->data = (char *) malloc (strlen (str) * sizeof (str));

		strcpy (ptr->data, str);
		ptr->hash = string->djb2Hash (ptr->data);
		string->list->append (string->list, (size_t) ptr);
	}
	return ptr->data;
}


void stringRemove (string_t *string, char *in) {
	token_t *token = string->find (string, in);
	if (!token) return;

	string->list->remove (string->list, (size_t) token);
	free (token);
}


bool charInString (char c, const char *delim) {
	for (; *delim; delim++)
		if (c == *delim)
			return true;
	return false;
}


char *stringRead (string_t *string, char *out, char *delim) {
	char *ptr = (char *) out;
	for (; ; ptr++) {
		*ptr = string->stream->update (string->stream);
		if (string->charInString (*ptr, delim))
			break;
	} *ptr = '\0';
	return (char *) out;
}

char *getWord (string_t *string, char *delim) {
	char str[BUFF_SIZE];
	string->read (string, str, delim);
	return string->store (string, str);
}


size_t djb2Hash (const char *word) {
	size_t hash = HASH_CONS;
	for (; *word; word++)
		hash = ((hash << 5) + hash) + *word;
	return hash;
}


void stringDestroy (string_t **string) { 
	(*string)->list->destroy (&(*string)->list);
	(*string)->stream->destroy (&(*string)->stream);
	free (*string);

	*string = NULL;
}

#ifdef DEBUG_STRING
void stringDebug (string_t *string) {
	node_t *node = string->list->head;
	token_t *token; size_t i;

	printf ("--== Debugging String ==--\n");
	printf ("number	raw	hash\n");

	for (i = 0; node; node = node->next, i++) {
		token = (token_t *) node->data;
		printf ("%li	%s	%li\n", i, token->data, token->hash);
	}
}
#endif


string_t *String () {
	string_t *string = (string_t *) malloc (sizeof (string_t));

	string->stream = Stream ();
	string->list = List ();

	string->destroy = stringDestroy;
	string->find = stringFind;
	string->store = stringStore;
	string->remove = stringRemove;

	string->charInString = charInString;
	string->read = stringRead;
	string->getWord = getWord;
	string->djb2Hash = djb2Hash;

#ifdef DEBUG_STRING
	string->debug = stringDebug;
#endif

	return string;
}
