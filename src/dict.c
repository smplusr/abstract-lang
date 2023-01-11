#include "dict.h"




node_t *get (char *name) {
	node_t *ptr = dict.node;
	for (; ptr < dict.ptr; ptr++) {
		if (strequ (name, ptr->name))
			return ptr;
	}

	return NULL;
}


void set (char *name, size_t data) {
	node_t *tmp = dict.get (name);
	if (tmp) {
		tmp->data = data;	
		return;
	}

	dict.ptr->name = name;
	dict.ptr->data = data;

	dict.ptr++;
}




init_dict (dict);
