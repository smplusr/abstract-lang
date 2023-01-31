#include "list.h"

/*
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
}*/


node_t *listAppend (list_t *list, size_t data) {
	node_t *node = (node_t *) malloc (sizeof (node_t));
	node->data = data; node->next = list->head;
	list->head = node;
	return node;
}

node_t *listFind (list_t *list, size_t data) {
	node_t *node = list->head;
	for (; node; node = node->next)
		if (node->data == data)
			return node;
	return (node_t *) NULL;
}


/* Need to rework this function
 * Glitchy infinite linked list 
 * */

void listRemove (list_t *list, size_t data) {	
	node_t **node = &(list->head);
	node_t *tmp = (*node)->next;

	if ((*node)->data == data) {
		tmp = (*node)->next;
		free (*node);
		list->head = tmp;
		return;
	}
		
	for (; (*node)->next; (*node) = (*node)->next)
		if ((*node)->next->data == data) {
			tmp = (*node)->next;
			break;
		}
	
	((*node)->next && (*node)->next->next)
		? tmp = (*node)->next->next
		: (node_t *) NULL;
	
	free ((*node)->next);
	(*node)->next = tmp;
}


void listDestroy (list_t **list) {
	node_t *node = (*list)->head; (*list)->head = (*list)->head->next;
	for (; (*list)->head; node = (*list)->head, (*list)->head = (*list)->head->next)
		free (node);

	free (*list);
	*list = (list_t *) NULL;
}

list_t *List () {
	list_t *list = (list_t *) malloc (sizeof (list_t));
	list->head = (node_t *) NULL;

	list->destroy = listDestroy;

	list->append = listAppend;
	list->find = listFind;
	list->remove = listRemove;

	return list;
}
