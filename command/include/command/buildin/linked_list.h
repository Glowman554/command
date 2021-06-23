#pragma once
#include <command/extern.h>
#include <stdint.h>

struct linked_list_node_t {
	uint64_t data;
	uint64_t data2;
	struct linked_list_node_t* next;
};

typedef void (*linked_list_callback)(struct linked_list_node_t* node);

EXPOSEC struct linked_list_node_t* linked_list_create(uint64_t data, uint64_t data2, struct linked_list_node_t* next);
EXPOSEC void linked_list_traverse(struct linked_list_node_t* head, linked_list_callback f);
EXPOSEC struct linked_list_node_t* linked_list_append(uint64_t data, uint64_t data2, struct linked_list_node_t* head);
EXPOSEC struct linked_list_node_t* linked_list_search(struct linked_list_node_t* head, uint64_t data);
EXPOSEC struct linked_list_node_t* linked_list_remove_front(struct linked_list_node_t* head);
EXPOSEC struct linked_list_node_t* linked_list_remove_back(struct linked_list_node_t* head);
EXPOSEC struct linked_list_node_t* linked_list_remove(struct linked_list_node_t* head, struct linked_list_node_t* nd);
EXPOSEC void linked_list_dispose(struct linked_list_node_t* head);