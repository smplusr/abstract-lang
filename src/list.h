#pragma once


#include <stdlib.h>


typedef struct node_t node_t;
struct node_t {
	size_t data;
	node_t *next;
};

node_t *newNode (size_t, node_t *);

/*
typedef struct list_t list_t;
struct list_t {
	node_t *head;

	node_t *(*newNode) (size_t, node_t *);
};*/
