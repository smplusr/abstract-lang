#include "dict.h"




pair_t *dictGet (dict_t *dict, char *key) {	
	/* Needs testing for hash instead of key
	 * */

	node_t *node = dict->list->head;
	pair_t *pair;

	if (!node) return (pair_t *) NULL;

	for (; node; node = node->next)
		if (node->data) {
			pair = (pair_t *) node->data;
			if (pair->key == key)
				return pair;
		}

	return (pair_t *) NULL;
}


void dictSet (dict_t *dict, char *key, size_t value, type_t type) {	
	pair_t *pair = dict->get (dict, key);

	if (!pair) {
		pair = (pair_t *) malloc (sizeof (pair_t));
		dict->list->head = Node ((size_t) pair, dict->list->head);	/* listAppend? */
	}

	pair->key = key;
	pair->value.data = value;
	pair->value.type = type;
}


void dictRemove (dict_t *dict, char *key) { 
	pair_t *pair = dict->get (dict, key);
	dict->list->remove (&dict->list->head, (size_t) pair);
	free (pair);

	/* Try to delete (free) the data associated with the pair.
	 * Only if it is a string (allocated).
	 * */
}

void dictDestroy (dict_t **dict) {
	(*dict)->list->destroy (&(*dict)->list);
	free (*dict);

	*dict = NULL;
}


#ifdef DEBUG_DICT
#include <stdio.h>
void dictDebug (dict_t *dict) {
	node_t *node = dict->list->head;
	pair_t *pair; size_t i;

	printf ("--== Debugging Dictionary ==--\n");
	printf ("number	key	value\n");

	for (i = 0; node; node = node->next, i++) {
		pair = (pair_t *) node->data;
		printf ("%li	%s	%p\n", i, pair->key, (void *) *(size_t *)(&pair->value));
	}
}
#endif

dict_t *Dict () {
	dict_t *dict = (dict_t *) malloc (sizeof (dict_t));
	dict->list = List ();

	dict->set = dictSet;
	dict->get = dictGet;
	dict->remove = dictRemove;
	dict->destroy = dictDestroy;

#ifdef DEBUG_DICT
	dict->debug = dictDebug;
#endif

	return dict;
}
