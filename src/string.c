#include "string.h"




chr_t *stringFind (const char *str) {
	size_t hash = djb2Hash (str);
	node_t *node = string.node;
	chr_t *ptr;
	if (!node)
		return (chr_t *) NULL;

	for (; node; node = node->next)
		if (node->data) {
			ptr = (chr_t *) node->data;
			if (ptr->hash == hash)
				return ptr;
		}

	return (chr_t *) NULL;
}


char *stringStore (const char *str) {
	chr_t *ptr = string.find (str);
	if (!ptr) {
		ptr = (chr_t *) malloc (sizeof (chr_t));
		ptr->data = (char *) malloc (strlen (str) * sizeof (str));

		strcpy (ptr->data, str);
		ptr->hash = djb2Hash (ptr->data);
		string.node = newNode ((size_t) ptr, string.node);
	}
	return ptr->data;
}


void stringRemove (const char *str) { nodeDelete ((size_t) string.find (str), &string.node); }




init_string (string);
