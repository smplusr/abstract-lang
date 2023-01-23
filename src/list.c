#include "list.h"




node_t *newNode (size_t data, node_t *head) {
	node_t *node = (node_t *) malloc (sizeof (node_t));
	node->data = data; node->next = head;
	return node;
}
