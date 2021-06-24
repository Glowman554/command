# Porting

The general process of porting libcommand to other platforms is relatively easy.  
The functions needed are: assert, memset, strlen, strcpy, command_malloc, command_free and command_realloc.

## Memory allocation functions

The memory allocation functions can be defined like this:

```c
void* command_malloc(int size) {
	return malloc(size);
}
```

```c
void command_free(void* ptr) {
	free(ptr);
}
```

```c
void* command_realloc(void* ptr, int size) {
	return realloc(ptr, size);
}
```

## Other functions

The other functions are standard c functions and should be included in the libc.