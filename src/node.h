#pragma once

#include <stdlib.h>




typedef struct node_t node_t;
struct node_t {
	size_t data;
	node_t *next;
};

node_t *newNode (size_t, node_t *);
node_t *nodeGetNodeParent (size_t data, node_t *head);
node_t *nodeGetNode (size_t data, node_t *head);
void nodeDelete (size_t data, node_t **head);

