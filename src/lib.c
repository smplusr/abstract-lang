#include "lib.h"




/* Implementation of <string.h> functions */
size_t strlen (const char *str) {
	size_t i = 0; for (; *str; str++, i++);
	return i;
}

char *strchr (const char *str, int c) {
	for (; *str; str++)
		if (*str == c)
			return (char *) str;
	return (char *) NULL;
}




/* Global type and assign (memcpy) function */
void _assign (void *a, const void *b) {
	unsigned i; for (i = 0; i < sizeof (void *); i++)
		((char *) a)[i] = ((char *) b)[i];
}




/* Linked list */
node_t *Node (const void *value) {
	node_t *node = (node_t *) malloc (sizeof (node_t));
	assign (node->value, value); node->next = (node_t *) NULL;
	return node;
}

void ListInsert (list_t *list, const void *value) {
	node_t *node = Node (value);
	node->next = list->head;
	list->head = node;
}

node_t *ListFind (list_t *list, const void *value) {
	node_t *node = list->head;
	for (; node; node = node->next)
		if (node->value == value)
			return node;
	return (node_t *) NULL;
}

void ListRemove (list_t *list, const node_t *node) {
	node_t *t = list->head, *p;

	if (!node) return;
	if (t != (node_t *) NULL && t->value == node->value) {
		list->head = t->next;
		free (t);
		return;
	}
	
	do (p = t, t = t->next);
	while (t != (node_t *) NULL && t->value != node->value);

	p->next = t->next;
	free (t);
}

void ListDestroy (list_t **list) {
	node_t *node = (*list)->head, *t;
	for (; node; ) {
		t = node;
		node = node->next;
		free (t);
	}

	free (*list); *list = (list_t *) NULL;
}

list_t *List (void) {
	list_t *list = (list_t *) malloc (sizeof (list_t));

	list->head = Node ((void *) (size_t) NULL);

	list->insert = ListInsert;
	list->find = ListFind;
	list->remove = ListRemove;
	list->destroy = ListDestroy;

	return list;
}




/* Dictionary / Map */
size_t djb2Hash (const char *key) {
	size_t hash = 5381;

	for (; *key; key++)
		hash = ((hash << 5) + hash) + *key;
	return hash;
}

pair_t *TypedPair (char *key, void *value, char type) {
	pair_t *pair = (pair_t *) malloc (sizeof (pair_t));
	pair->key = djb2Hash (key);
	pair->value = value; pair->type = type;

	return pair;
}

void MapInsert (map_t *map, pair_t *pair) {
	pair_t *p;
	if (!pair) return;

	p = map->find (map, pair->key);
	(p)	? (void) (p->value = pair->value, p->type = pair->type)
		: map->list->insert (map->list, (void *) (size_t) pair);
}

pair_t *MapFind (map_t *map, size_t key) {
	node_t *node = map->list->head;
	
	for (; node && node->value; node = node->next)
		if (((pair_t *) (size_t) node->value)->key == key)
			return (pair_t *) (size_t) node->value;

	return (pair_t *) NULL;
}

void MapRemove (map_t *map, size_t key) { map->list->remove (map->list, map->list->find (map->list, (void *) (size_t) map->find (map, key))); }

void MapDestroy (map_t **map) { 
	(*map)->list->destroy (&(*map)->list);
	free (*map); *map = NULL;
}

map_t *Map (void) {
	map_t *map = (map_t *) malloc (sizeof (map_t));

	map->list = List ();

	map->hash = djb2Hash;
	map->insert = MapInsert;
	map->find = MapFind;
	map->remove = MapRemove;
	map->destroy = MapDestroy;

	return map;
}
