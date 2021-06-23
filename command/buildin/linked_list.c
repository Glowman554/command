#include <command/buildin/linked_list.h>
#include <command/platform.h>
#include <stdlib.h>
#include <assert.h>

struct linked_list_node_t* linked_list_list_create(uint64_t data, uint64_t data2, struct linked_list_node_t* next) {
	struct linked_list_node_t* new_node = command_malloc(sizeof(struct linked_list_node_t));

	assert(new_node != NULL);

	new_node->data = data;
	new_node->data2 = data2;
	new_node->next = next;

	return new_node;
}

void linked_list_list_traverse(struct linked_list_node_t* head, linked_list_callback f) {
	struct linked_list_node_t* cursor = head;

	while(cursor != NULL) {
		f(cursor);
		cursor = cursor->next;
	}
}

struct linked_list_node_t* linked_list_list_append(uint64_t data, uint64_t data2, struct linked_list_node_t* head) {
	struct linked_list_node_t* cursor = head;
	struct linked_list_node_t* tmp = NULL;

	while(cursor != NULL) {
		tmp = cursor;
		cursor = cursor->next;
	}

	struct linked_list_node_t* new_node = linked_list_list_create(data, data2, NULL);
	tmp->next = new_node;

	return head;
}

struct linked_list_node_t* linked_list_list_search(struct linked_list_node_t* head, uint64_t data) {
	struct linked_list_node_t* cursor = head;

	while(cursor != NULL) {
		if(cursor->data == data) {
			return cursor;
		}

		cursor = cursor->next;
	}

	return NULL;
}

struct linked_list_node_t* linked_list_list_remove_front(struct linked_list_node_t* head) {
	if(head == NULL) {
		return NULL;
	}

	struct linked_list_node_t* front = head;
	head = head->next;

	if(front == head) {
		head = NULL;
	}

	command_free(front);

	return head;
}

struct linked_list_node_t* linked_list_list_remove_back(struct linked_list_node_t* head) {
	if(head->next == NULL || head == NULL) {
		return NULL;
	}

	struct linked_list_node_t* current = head;

	while (current->next->next != NULL) {
		current = current->next;
	}
	
	command_free(current->next);

	current->next = NULL;

	return head;
}

struct linked_list_node_t* linked_list_list_remove(struct linked_list_node_t* head, struct linked_list_node_t* nd) {
	if(nd == head) {
		head = linked_list_list_remove_front(head);
		return head;
	}

	if(nd->next == NULL) {
		head = linked_list_list_remove_back(head);
		return head;
	}

	struct linked_list_node_t* cursor = head;

	while(cursor != NULL) {
		if(cursor->next == nd) {
			break;
		}

		cursor = cursor->next;
	}

	if(cursor != NULL) {
		struct linked_list_node_t* tmp = cursor->next;
		cursor->next = tmp->next;
		tmp->next = NULL;
		command_free(tmp);
	}

	return head;
}

void linked_list_list_dispose(struct linked_list_node_t* head) {
	struct linked_list_node_t* cursor;
	struct linked_list_node_t* tmp;

	if(head != NULL) {
		cursor = head->next;
		head->next = NULL;
		while(cursor != NULL) {
			tmp = cursor->next;
			command_free(cursor);
			cursor = tmp;
		}
	}
}