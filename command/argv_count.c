#include <command/argv_count.h>

#include <stddef.h>

int argv_count(char* argv[]) {
	int argc = 0;

	while(argv[argc] != NULL) {
		argc++;
	}

	return argc;
}