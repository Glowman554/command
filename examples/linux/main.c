#include <command/buildin/slot_list.h>
#include <command/buildin/linked_list.h>
#include <command/argv_parser.h>
#include <command/argv_splitter.h>
#include <command/command_manager.h>
#include <command/argv_count.h>
#include <stdio.h>
#include <stdlib.h>
#if 0
void test1(int argc, char** argv) {
	for (int i = 0; i < argc; i++) {
		printf("%s\n", argv[i]);
	}
}


void test2(int argc, char** argv) {
	for (int i = 0; i < argc; i++) {
		printf("%s\n", argv[i]);
	}
}

int main(int argc, char** argv) {
	struct command_manager_t command_manager;

	create_command_manager(&command_manager);

	new_command(&command_manager, "test1", "no", test1);
	new_command(&command_manager, "test2", "no", test2);

	run_command(&command_manager, "test1 hi hi2 hi3");
	run_command(&command_manager, "test2 hi hi2 hi3");
	run_command(&command_manager, "test3 hi hi2 hi3");


	return 0;
}
#endif

int main() {
	char test_args[100] = "program_name value -h -x -help -v 1 some_val -idk";
	char** test_args_split = argv_split(test_args);
	int argc = argv_count(test_args_split);

	for (int i = 0; i < argc; i++) {
		printf("%s\n", test_args_split[i]);

	}

	return 0;
}