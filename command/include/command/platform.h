#pragma once

#include <command/extern.h>

EXPOSEC void* command_malloc(int size);
EXPOSEC void command_free(void* ptr);
EXPOSEC void* command_realloc(void* ptr, int size);