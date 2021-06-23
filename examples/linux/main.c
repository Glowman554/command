#include <command/buildin/slot_list.h>
#include <command/buildin/linked_list.h>

#include <stdio.h>

void enumerate(struct linked_list_node_t* node) {
	printf("Node: 0x%x, %d\n", node, node->data);
}


int main() {
	struct linked_list_node_t* head = NULL;

	head = linked_list_create(0, 0, NULL);
	linked_list_append(1, 0, head);
	linked_list_append(2, 0, head);
	linked_list_append(3, 0, head);

	linked_list_traverse(head, enumerate);
	printf("\n\n");

	head = linked_list_remove(head, linked_list_search(head, 2));
	linked_list_traverse(head, enumerate);
	printf("\n\n");

	head = linked_list_remove(head, linked_list_search(head, 0));
	linked_list_traverse(head, enumerate);
	printf("\n\n");

	head = linked_list_remove(head, linked_list_search(head, 3));
	linked_list_traverse(head, enumerate);
	printf("\n\n");

	linked_list_dispose(head);

	return 0;
}