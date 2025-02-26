/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starry <starry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:35:24 by starry            #+#    #+#             */
/*   Updated: 2025/02/26 19:52:05 by starry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unic/dictionary.h"

/**
 * @brief Add value to dict\r
 * @attention Key and value <= 8 bytes, use pointers for larger values
 *
 * @param dict
 * @param key value or address
 * @param value value or address
 * @param dealloc_value function to deallocate value
 * @return true if added, false if key already exists
 */
bool	dict_add(t_dict dict, t_generic key, t_generic value,
		t_deallocator dealloc_value)
{
	size_t			hash;
	t_linkedlist	*buckets;
	t_dict_obj		obj;

	if (!dict || dict_get(dict, key))
		return (false);
	if (dict_has_breached_load_factor(dict))
		dict_realloc(dict);
	hash = dict_hash_function(dict, dict->hash_key(key, dict->size));
	buckets = dict->buckets;
	obj = dict_obj_init(key, value, dict->dealloc_key, dealloc_value);
	if (!obj)
		return (false);
	linkedlist_push(buckets + hash, obj);
	dict->used++;
	return (true);
}

/**
 * @brief Get value from dict
 *
 * @param dict
 * @param key
 * @return void*
 */
void	*dict_get(t_dict dict, t_generic key)
{
	size_t			hash;
	t_linkedlist	bucket;
	t_dict_obj		obj;

	hash = dict_hash_function(dict, dict->hash_key(key, dict->size));
	if (!dict || !dict->used)
		return (NULL);
	bucket = (dict->buckets)[hash];
	while (linkedlist_getinfo(bucket)
		&& dict->cmp(((t_dict_obj)linkedlist_getinfo(bucket))->key, key))
		bucket = linkedlist_getnext(bucket);
	obj = (t_dict_obj)linkedlist_getinfo(bucket);
	if (!obj)
		return (NULL);
	return (obj->value);
}

/**
 * @brief Remove key and value from dict
 *
 * @param dict
 * @param key
 *
 * @return if key was removed
 */
bool	dict_remove(t_dict dict, t_generic key)
{
	size_t			hash;
	t_linkedlist	bucket;

	hash = dict_hash_function(dict, dict->hash_key(key, dict->size));
	if (!dict || !dict->used)
		return (false);
	if (!dict_get(dict, key))
		return (false);
	bucket = (dict->buckets)[hash];
	while (linkedlist_getinfo(bucket)
		&& dict->cmp(((t_dict_obj)linkedlist_getinfo(bucket))->key, key))
		bucket = linkedlist_getnext(bucket);
	linkedlist_remove(dict->buckets + hash, &dict_obj_dealloc);
	dict->used--;
	return (true);
}
