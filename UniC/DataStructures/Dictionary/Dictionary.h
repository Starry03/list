//
// Created by andre on 8/9/2023.
//

#ifndef DICTIONARY_H
# define DICTIONARY_H

# include "../../DataStructures/LinkedList/LinkedList.h"
# include <stdbool.h>
# include <stddef.h>
#include <stdint.h>

typedef struct s_dictionary
{
	LinkedList			*buckets;
	size_t				used;
	size_t				size;
	Comparator			cmp;
	Hasher				hash_key;
	Deallocator			dealloc_key;
	uint64_t			a;
	uint64_t			b;
	uint64_t			prime;
}						t_dictionary;

typedef t_dictionary	*t_dict;

typedef struct s_dict_obj
{
	Generic				key;
	Generic				value;
	Deallocator			dealloc_key;
	Deallocator			dealloc_value;
}						t_dict_obj;

typedef t_dict_obj		*Dict_obj;

t_dict					Dict_Init(size_t size, Comparator cmp, Hasher hash_key,
							Deallocator dealloc_key);
bool					Dict_Add(t_dict dict, Generic key, Generic value,
							Deallocator dealloc_value);
void					*Dict_Get(t_dict dict, Generic key);
void					Dict_Remove(t_dict dict, Generic key);
void					Dict_Free(t_dict dict);

void					Dict_Status(t_dict dict);

#endif
