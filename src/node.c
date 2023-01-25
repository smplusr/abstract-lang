#include "node.h"




node_t *newNode (size_t data, node_t *head) {
	node_t *node = (node_t *) malloc (sizeof (node_t));
	node->data = data; node->next = head;
	return node;
}

node_t *nodeGetNodeParent (size_t data, node_t *head) {
	node_t *node = head, *parent = (node_t *) NULL;

	for (; node; parent = node, node = node->next)
		if (node->data == data)
			return parent;

	return (node_t *) NULL;
}

node_t *nodeGetNode (size_t data, node_t *head) {
	node_t *node = nodeGetNodeParent (data, head);

	return (node)
		? node->next
		: head;
}

void nodeDelete (size_t data, node_t **head) {
	node_t *parent = nodeGetNodeParent (data, *head);
	if (parent) {
		parent->next = parent->next->next;
		free (parent->next);
	} else if ((*head)->data == data) {
		free (*head);
		*head = (*head)->next;
	}
}
