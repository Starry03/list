/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starry <starry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:44:11 by starry            #+#    #+#             */
/*   Updated: 2025/02/26 23:43:55 by starry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unic/dictionary.h"
#include "unic/hashfunctions.h"
#include <stdlib.h>

/**
 * @brief Takes all dict_objs from dict
 * @param dict
 * @return LinkedList of t_dict_obj
 */
static t_linkedlist	take_dict_objs(t_dict dict)
{
	t_linkedlist	list;
	t_linkedlist	bucket;
	size_t			i;
	t_dict_obj		obj;
	t_linkedlist	next;

	list = LINKEDLIST_EMPTY;
	i = 0;
	while (i < dict->size)
	{
		bucket = (dict->buckets)[i];
		while (bucket)
		{
			obj = (t_dict_obj)(linkedlist_getinfo(bucket));
			next = linkedlist_getnext(bucket);
			free(bucket);
			bucket = next;
			linkedlist_push(&list, obj);
		}
		i++;
	}
	return (list);
}

/**
 * @brief Adds object to dict without checking if key already exists
 * @note Used internally to avoid reallocating dict from zero
 */
static void	soft_add(t_dict dict, t_dict_obj obj)
{
	size_t			hash;
	t_linkedlist	bucket;

	hash = dict_hash_function(dict, dict->hash_key(obj->key, dict->size));
	bucket = dict->buckets[hash];
	linkedlist_push(&bucket, obj);
	dict->buckets[hash] = bucket;
	dict->used++;
}

/**
 * @brief Reallocates dict with double the size
 * @param dict
 */
void	dict_realloc(t_dict dict)
{
	t_linkedlist	list;
	t_linkedlist	temp;

	list = take_dict_objs(dict);
	temp = list;
	free(dict->buckets);
	dict->buckets = dict_alloc_buckets(dict->size * REALLOC_COEFF);
	dict->size = dict->size * REALLOC_COEFF;
	dict->used = 0;
	while (list)
	{
		soft_add(dict, (t_dict_obj)linkedlist_getinfo(list));
		list = linkedlist_getnext(list);
	}
	linkedlist_dealloc(temp, NULL);
}

/**
 * @brief used internally for double hashing
 */
size_t	dict_hash_function(t_dict dict, size_t hashed_key)
{
	return (hash_universal(hashed_key, dict->a, dict->b, dict->prime,
			dict->size));
}

bool	dict_has_breached_load_factor(t_dict dict)
{
	return (((double)(dict->used + 1) / dict->size) >= MAX_LOAD_FACTOR);
}
