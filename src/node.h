#pragma once

#include <stdlib.h>


/* Needs rework
 * */

typedef struct node_t node_t;
struct node_t {
	size_t data;
	node_t *next;
};

typedef struct list_t list_t;
struct list_t {
	node_t *head;

	void (*destroy) (list_t **);

	node_t *(*find) (node_t *, size_t);
	void (*remove) (node_t **, size_t);
	void (*unlink) (node_t **);
};

node_t *Node (size_t, node_t *);
list_t *List ();
