#include <command/argv_splitter.h>
#include <command/platform.h>

#include <string.h>

char** argv_split(char* str) {
	int len = strlen(str);

	int argc = 1;

	for (int i = 0; i < len; i++) {
		if(str[i] == ' ') {
			argc++;
		}
	}

	char** argv = command_malloc(sizeof(char*) * (argc + 1));

	argc = 1;
	argv[0] = &str[0];

	for (int i = 0; i < len; i++) {
		if(str[i] == ' ') {
			argv[argc] = &str[i + 1];
			str[i] = 0;
			argc++;
		}
	}

	return argv;
	
}