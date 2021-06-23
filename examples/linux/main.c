#include <command/buildin/slot_list.h>
#include <command/buildin/linked_list.h>
#include <command/argv_parser.h>
#include <stdio.h>
#include <stdlib.h>

void enumerate(struct linked_list_node_t* node) {
	printf("Node: 0x%x, %d\n", node, node->data);
}

void print_nodes(slot_list_node_t* node) {
	if(node->data1) {
		if(node->data2) {
			printf("Option: %s, value: %s\n", node->data1, node->data2);
		} else {
			printf("Option: %s\n", node->data1);
		}
	} else {
		printf("value: %s\n", node->data2);
	}
}

int main(int argc, char** argv) {
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

	char* test_argv[] = { "program_name", "-t", "-h", "hello", "-h", "-x", "-t", "test", "test2" };

	slot_list_t* argv_list = parse_argv(8, test_argv);

	slot_list_transverse(argv_list, (slot_transverse_function) print_nodes);

	slot_list_dispose(argv_list);

	free(argv_list);

	return 0;
}