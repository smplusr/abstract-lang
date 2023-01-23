#include "string.h"


/*
bool stringExists (const char *str) {
	node_t *node = string.node;
	str_ptr_t *ptr;
	for (; node; node = node->next) {
		if (node->data) {
			ptr = (str_ptr_t *) node->data;
			if (ptr->data == str)
				return true;
		}
	}
	return false;
}*/

str_ptr_t *stringFind (const char *str) {	
	size_t hash = djb2Hash (str);
	node_t *node = string.node;
	str_ptr_t *ptr;
	if (!node)
		return (str_ptr_t *) NULL;

	for (; node; node = node->next)
		if (node->data) {
			ptr = (str_ptr_t *) node->data;
			if (ptr->hash == hash)
				return ptr;
		}

	return (str_ptr_t *) NULL;


}


str_ptr_t *stringSavePtr (const char *str) {
	str_ptr_t *ptr = (str_ptr_t *) malloc (sizeof (str_ptr_t));
	char *strptr = (char *) malloc (strlen (str) * sizeof (str));

	strcpy (strptr, str);

	ptr->data = strptr;
	ptr->hash = djb2Hash (strptr);

	return ptr;
}

char *stringStore (char *read) {
	str_ptr_t *ptr = string.find (read); 
	if (!ptr) {
		ptr = stringSavePtr (read);
		string.node = newNode ((size_t) ptr, string.node);
	}

	return ptr->data;
}




init_string (string);
