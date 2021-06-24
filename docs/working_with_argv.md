# Working with argv 

This library includes a few functions to make the working with argv/argc easier.  
This functions are: argv_count, parse_argv, argv_split.

## argv_count

argv_count is self explanatory: it counts how many arguments argv includes.

```c
int main() {
	const char* args[] = { "/bin/test.elf", "-t", "test", NULL };
	int argcount = argv_count(args);

	printf("There are %d arguments!\n", argcount);

	return 0;
}
```

## parse_argv

This function is way more complicated. It parses the argv array into a slot list. THe slot list contains different tokens with contain in node->data1 the option for example "-v". It also contains in node->data2 the value of the option if there is any.  
Also note: this function allocates a slot list and also some storage to store this list you need to free that.

```c
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

int main() {
	const char* args[] = { "/bin/test.elf", "test", "-v", "-t", "test", NULL };

	slot_list_t* argv_list = parse_argv(argv_count(args), args);

	slot_list_transverse(argv_list, (slot_transverse_function) print_nodes);

	slot_list_dispose(argv_list);
	free(argv_list);

	return 0;
}
```

## argv_split

This function does exactly what it says it dose. It splits a string into an argv array.  
Note: this function allocates memory with needs to be freed. The string will be written to. Every ' ' gets replaced with 0.

```c
int main() {
	char test_args[100] = "program_name value -h -x -help -v 1 some_val -idk";
	char** test_args_split = argv_split(test_args);
	int argc = argv_count(test_args_split);

	for (int i = 0; i < argc; i++) {
		printf("%s\n", test_args_split[i]);

	}

	return 0;
}
```