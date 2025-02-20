//
// Created by andre on 8/9/2023.
//

#ifndef DICTIONARY_H
# define DICTIONARY_H

# include "unic/linkedlist.h"
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

typedef struct s_dictionary
{
	t_linkedlist		*buckets;
	size_t				used;
	size_t				size;
	t_comparator		cmp;
	t_hasher			hash_key;
	t_deallocator		dealloc_key;
	uint64_t			a;
	uint64_t			b;
	uint64_t			prime;
}						t_dictionary;

typedef t_dictionary	*t_dict;

typedef struct s_dict_obj
{
	t_generic			key;
	t_generic			value;
	t_deallocator		dealloc_key;
	t_deallocator		dealloc_value;
}						t_dict_obj_;

typedef t_dict_obj_		*t_dict_obj;

t_dict					dict_init(size_t size, t_comparator cmp,
							t_hasher hash_key, t_deallocator dealloc_key);
bool					dict_add(t_dict dict, t_generic key, t_generic value,
							t_deallocator dealloc_value);
void					*dict_get(t_dict dict, t_generic key);
t_linkedlist			*dict_get_buckets(t_dict dict);
bool					dict_remove(t_dict dict, t_generic key);
void					dict_free(t_generic dict);
void					dict_status(t_dict dict);

#endif
