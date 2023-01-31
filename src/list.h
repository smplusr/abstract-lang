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

	node_t *(*append) (list_t *, size_t);
	node_t *(*find) (list_t *, size_t);
	void (*remove) (list_t *, size_t);
};

list_t *List ();
