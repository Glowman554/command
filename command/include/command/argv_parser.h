#pragma once

#include <command/buildin/slot_list.h>
#include <command/extern.h>
#include <stdbool.h>

struct argv_parser_token_t {
	char* option; // aka d1
	char* value; // aka d2

	void* d3;
	void* d4;

	bool is_taken;
};

EXPOSEC slot_list_t* parse_argv(int argc, char** argv);
