//
// Created by andre on 8/9/2023.
//

#ifndef DICTIONARY_H
# define DICTIONARY_H

# include "../../DataStructures/LinkedList/LinkedList.h"
# include <stddef.h>

typedef struct s_dictionary
{
	LinkedList			*buckets;
	size_t				used;
	size_t				size;
}						t_dictionary;

typedef t_dictionary	*t_dict;

typedef struct s_dict_obj
{
	Generic				key;
	Generic				value;
	void				(*dealloc_key)(Generic);
	void				(*dealloc_value)(Generic);
	size_t				(*hash_key)(Generic, size_t);
}						t_dict_obj;

typedef t_dict_obj		*Dict_obj;

t_dict					Dict_Init(size_t size);
void					Dict_Add(t_dict *dict, Generic key, Generic value,
							size_t (*hash_key)(Generic, size_t),
							void (*dealloc_key)(Generic),
							void (*dealloc_value)(Generic));
void					*Dict_Get(t_dict dict, Generic key,
							size_t (*hash_key)(Generic, size_t),
							int (*cmp)(Generic, Generic));
void					Dict_Remove(t_dict dict, Generic key);
void					Dict_Free(t_dict dict);

void					Dict_Status(t_dict dict);

#endif
