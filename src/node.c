#include "node.h"


node_t *Node (size_t data, node_t *next) {
	node_t *node = (node_t *) malloc (sizeof (node_t));
	node->data = data; node->next = next;
	return node;
}

node_t *nodeFind (node_t *head, size_t data) {
	node_t *node = head;
	for (; node; node = node->next)
		if (node->data == data)
			return node;
	return (node_t *) NULL;

}

void nodeRemove (node_t **head, size_t data) {
	node_t **node = head;
	node_t *tmp = (*node)->next;

	for (; (*node)->next; (*node) = (*node)->next)
		if ((*node)->next->data == data)
			break;

	(*node)->next = (*node)->next->next;
	free (tmp);

}

void nodeUnlink (node_t **head) {
	node_t *node = *head; *head = (*head)->next;
	for (; *head; node = *head, *head = (*head)->next)
		free (node);
}


void listDestroy (list_t **list) {
	(*list)->unlink (&(*list)->head);
	free (*list);
	*list = (list_t *) NULL;
}

list_t *List () {
	list_t *list = (list_t *) malloc (sizeof (list_t));
	list->head = (node_t *) NULL;

	list->destroy = listDestroy;

	list->find = nodeFind;
	list->remove = nodeRemove;
	list->unlink = nodeUnlink;

	return list;
}
