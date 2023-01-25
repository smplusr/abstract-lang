#include "dict.h"




pair_t *dictGet (char *key) {	
	/* Needs testing for hash instead of key
	 * */

	node_t *node = dict.node;
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


void dictSet (char *key, size_t value, type_t type) {	
	pair_t *pair = dict.get (key);

	if (!pair) {
		pair = (pair_t *) malloc (sizeof (pair_t));
		dict.node = newNode ((size_t) pair, dict.node);
	}

	pair->key = key;
	pair->value.data = value;
	pair->value.type = type;
}






void dictDel (char *key) { 
	nodeDelete ((size_t) dict.get (key), &dict.node);
	/* Try to delete (free) the data associated with the pair.
	 * Only if it is a string (allocated).
	 * */
}


init_dict (dict);
