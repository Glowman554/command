#include <command/platform.h>

#include <stdlib.h>

void* command_malloc(int size) {
	return malloc(size);
}

void command_free(void* ptr) {
	free(ptr);
}

void* command_realloc(void* ptr, int size) {
	return realloc(ptr, size);
}