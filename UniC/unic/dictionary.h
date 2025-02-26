/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starry <starry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:46:01 by starry            #+#    #+#             */
/*   Updated: 2025/02/26 23:43:26 by starry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARY_H
# define DICTIONARY_H

# include "unic/linkedlist.h"
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

# define DEFAULT_SIZE 16
# define REALLOC_COEFF 2
# define MAX_LOAD_FACTOR 0.75
# define DICT_EMPTY ((t_dict)NULL)
# define PRIME_DEFAULT ((uint64_t)806526737)

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

t_dict_obj				dict_obj_init(t_generic key, t_generic value,
							t_deallocator dealloc_key,
							t_deallocator dealloc_value);
void					dict_obj_dealloc(t_generic dict_obj);

t_dict					dict_init(size_t size, t_comparator cmp,
							t_hasher hash_key, t_deallocator dealloc_key);
bool					dict_add(t_dict dict, t_generic key, t_generic value,
							t_deallocator dealloc_value);
void					*dict_get(t_dict dict, t_generic key);
t_linkedlist			*dict_get_buckets(t_dict dict);
bool					dict_remove(t_dict dict, t_generic key);
bool					dict_has_breached_load_factor(t_dict dict);
void					dict_realloc(t_dict dict);
size_t					dict_hash_function(t_dict dict, size_t hashed_key);
t_linkedlist			*dict_alloc_buckets(size_t size);
void					dict_free(t_generic dict);

#endif
