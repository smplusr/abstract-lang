#pragma once

#include <stdio.h>
#include <malloc.h>




/* Implementation of <stdlib.h> types */
#ifndef NULL
#define NULL ((void *) 0)
#endif
typedef unsigned long size_t;

/* Implementation of <string.h> functions */
size_t strlen (const char *str);
char *strchr (const char *str, int c);




/* Assign (memcpy) function */
#define assign(x, y) _assign ((void *) &x, (void *) &y)
void _assign (void *, const void *);
/*#define void *void *
*/



/* Linked list */
typedef struct node_t node_t;
struct node_t {
	void *value;
	node_t *next;
};

typedef struct list_t list_t;
struct list_t {
	node_t *head;

	void (*insert) (list_t *, const void *);
	node_t *(*find) (list_t *, const void *);
	void (*remove) (list_t *, const node_t *);
	void (*destroy) (list_t **);
};


node_t *Node (const void *value);
list_t *List (void);




/* Dictionary / Map */
typedef struct pair_t {
	size_t key;
	void *value;
	char type;
} pair_t;

typedef struct map_t map_t;
struct map_t {
	list_t *list;

	size_t (*hash) (const char *);
	void (*insert) (map_t *, pair_t *);
	pair_t *(*find) (map_t *, size_t);
	void (*remove) (map_t *, size_t);	
	void (*destroy) (map_t **);
};


#define Pair(X, Y) TypedPair (X, Y, 0)
pair_t *TypedPair (char *, void *, char);
map_t *Map (void);
