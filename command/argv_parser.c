#include <command/argv_parser.h>

#include <command/platform.h>

slot_list_t* parse_argv(int argc, char** argv) {
	slot_list_t* list = command_malloc(sizeof(slot_list_t));

	slot_list_create(list);

	for (int i = 1; i < argc; i++) {
		if(argv[i][0] == '-') {
			if(i + 1 <= argc) {
				if(argv[i + 1][0] == '-') { // only option without value
					slot_list_add_node(list, argv[i], 0, 0, 0);
				
				} else { // we have a value
					slot_list_add_node(list, argv[i], argv[i + 1], 0, 0);
					i++;
				}
			} else { // we have no options left 
				slot_list_add_node(list, argv[i], 0, 0, 0);
			}
		} else { // we expect just value
			slot_list_add_node(list, 0, argv[i], 0, 0);
		}
	}
	
	return list;
}