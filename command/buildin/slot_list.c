#include <command/buildin/slot_list.h>
#include <command/platform.h>

#include <string.h>

void slot_list_create(slot_list_t* list) {
	list->nodes = command_malloc(sizeof(slot_list_node_t) * 10);
	list->len = 10;
}

void slot_list_dispose(slot_list_t* list) {
	command_free(list->nodes);
}

slot_list_node_t* slot_list_find_node(slot_list_t* list, slot_search_function f, void* d1, void* d2, void* d3, void* d4) {
	for (int i = 0; i < list->len; i++) {
		if(list->nodes[i].is_taken) {
			if(f(&list->nodes[i], d1, d2, d3, d4)) {
				return &list->nodes[i];
			}
		}
	}
	return 0;
}

void slot_list_remove_node(slot_list_t* list, slot_list_node_t* node) {
	for (int i = 0; i < list->len; i++) {
		if(&list->nodes[i] == node) {
			memset(&list->nodes[i], 0, sizeof(slot_list_node_t));
		}
	}
}

slot_list_node_t* slot_list_add_node(slot_list_t* list, void* d1, void* d2, void* d3, void* d4) {
search:
	for (int i = 0; i < list->len; i++) {
		if(!list->nodes[i].is_taken) {
			memset(&list->nodes[i], 0, sizeof(slot_list_node_t));
			list->nodes[i] = (slot_list_node_t) { d1, d2, d3, d4, true };
			return &list->nodes[i];
		}
	}
	
	list->nodes = (slot_list_node_t*) command_realloc(list->nodes, sizeof(slot_list_node_t) * (list->len + 1));
	list->len++;

	goto search;
}