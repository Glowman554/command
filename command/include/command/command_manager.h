#pragma once

#include <command/buildin/slot_list.h>
#include <command/extern.h>

typedef bool (*command_executor)(int argc, char** argv);

struct command_manager_t {
	slot_list_t command_list;
};

struct command_t {
	char name[16];
	char help[1024];
	command_executor executor;
};


EXPOSEC bool run_command(struct command_manager_t* cmd, char* message);
EXPOSEC void new_command(struct command_manager_t* cmd, char* name, char* help, command_executor executor);

EXPOSEC void create_command_manager(struct command_manager_t* cmd);
EXPOSEC void dispose_command_manager(struct command_manager_t* cmd);