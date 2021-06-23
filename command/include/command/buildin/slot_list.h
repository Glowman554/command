#pragma once

#include <command/extern.h>
#include <stdbool.h>

typedef struct {
	void* data1;
	void* data2;
	void* data3;
	void* data4;

	bool is_taken;
} slot_list_node_t;

typedef struct {
	slot_list_node_t* nodes;
	int len;
} slot_list_t;


typedef bool (*slot_search_function)(slot_list_node_t* node, void* d1, void* d2, void* d3, void* d4);

EXPOSEC void slot_list_create(slot_list_t* list);
EXPOSEC void slot_list_dispose(slot_list_t* list);

EXPOSEC slot_list_node_t* slot_list_find_node(slot_list_t* list, slot_search_function f, void* d1, void* d2, void* d3, void* d4);
EXPOSEC void slot_list_remove_node(slot_list_t* list, slot_list_node_t* node);
EXPOSEC slot_list_node_t* slot_list_add_node(slot_list_t* list, void* d1, void* d2, void* d3, void* d4);