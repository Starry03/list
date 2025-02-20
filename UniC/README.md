# UniC

## Update info

- major refactor
- headers moved into "unic" folder
- lib name changed to "unic" (makefile & link affected)

### Version
2.1

### Latest features & changes

- doc generation
- doc ui
- 42 norminette (almost)

## About

General purpose library

### Dependecies

- gcc
- make
- doc (optional)
	- python
	- node
	- postgresql

### Doc
Documentation is provided on top of every function

If you want to use the client for a better experience, check the dependencies

NOTE: doc tool was made just for "fun" and trying something new like databases, it's kinda useless unless you like the way it works

NOTE 2: doc dependencies are quite heavy and have a shitty ecosystem (node expecially) so if you come across troubles, just use the doc provided in the code, is literally the same

```sh
# build postgres db and next-js
bash ./doc_uisetup.sh
or
chmod 777 ./doc_uisetup.sh && ./doc_uisetup.sh
```

#### Run UI

```sh
bash ./doc_uistart.sh
or
chmod 777 ./doc_uistart.sh && ./doc_uistart.sh
```

### Linking

```sh
# go inside UniC path
cd <lib path>
# compile library
make
# link library
gcc ... <unic_path>/unic.a -I<unic_path>
```

#### Makefile template

```make
unic_path=
unic_lib=$(unic_path)/unic.a
unic_includes=-I$(unic_path)
```

## Content

- libft
- unic

### Datastructures

- Matrices
- Vector
- Node
- Linked list
- Double linked list
- Queue
- Stack
- Binary tree
- Dictionary (Hash map)
- Heap
- Graph

### Algorithms

- Search
- Sort

### Libft

Basic implementation

## Examples

Compile the library before running any example

### Graph

- Generate a graphical representation of the graph using [mermaid](https://github.com/mermaid-js/mermaid)

```make
make graphdraw
```

output:

```mermaid
flowchart LR
0((a)) -- 2 --> 1((b))
0((a)) -- 1 --> 3((d))
1((b)) -- 4 --> 2((c))
1((b)) -- 1 --> 4((e))
2((c))
3((d)) -- 3 --> 4((e))
4((e)) -- 2 --> 5((f))
5((f)) -- 6 --> 4((e))
5((f)) -- 3 --> 2((c))
5((f)) -- 1 --> 0((a))
```
