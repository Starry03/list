# UniC

### Version 1.6

### Latest features & changes

- DoubleLinkedList
- types

### TO-DO

- Heap
- Graph

## About

General purpose library

Feel free to use it, but please note:

- it's not optimized for performance
- it could be obviously improved

### Linking

```sh
cd '<lib path>'
make						# compile library
gcc ... ./UniC/UniC.a		# link library
```

## Data structures

- Matrices
- Vector
- Node
- Linked list
- Double linked list
- Queue
- Stack
- Binary tree
- Dictionary (Hash map)

### Dictionaries

Handles everything

example:

```c
#include <stdio.h>
#include <stdlib.h>
#include "./DataStructures/Dictionary/Dictionary.h"

void alloc(Dict d)
{
	static int i = 0;
	Dict_Add(d, i++, 10, NULL, NULL);
}

int main() {
	Dict dict = Dict_Init(10);
	int i = 0;
	while (i++ < 10)
		alloc(dict);
	Dict_Status(dict);
	int a = (int)Dict_Get(&dict, 0);
	printf("%d\n", a);
	Dict_Free(dict);
}

```

- Resizes for better performance

## Algorithms

- Search
- Sort

## Libft

Basic implementation

