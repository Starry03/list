/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starry <starry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:54:03 by starry            #+#    #+#             */
/*   Updated: 2025/02/26 23:43:11 by starry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unic/dictionary.h"
#include "unic/hashfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/random.h>
#include <time.h>

static inline t_dict	dict_alloc(void)
{
	return (t_dict)malloc(sizeof(t_dictionary));
}

t_linkedlist	*dict_alloc_buckets(size_t size)
{
	t_linkedlist	*buckets;
	size_t			i;

	buckets = (t_linkedlist *)malloc(sizeof(t_linkedlist) * size);
	if (!buckets)
		return (NULL);
	i = 0;
	while (i < size)
		buckets[i++] = NULL;
	return (buckets);
}

/**
 * @brief Creates Dictionary instance
 *
 * @param size number of buckets, if null size := DEFAULT_SIZE
 * @param cmp function to compare keys
 * @param hash_key function to hash keys
 * @param dealloc_key function to deallocate keys
 * @return Dict
 */
t_dict	dict_init(size_t size, t_comparator cmp, t_hasher hash_key,
		t_deallocator dealloc_key)
{
	t_linkedlist	*buckets;
	t_dict			dict;

	dict = dict_alloc();
	if (!dict)
		return (DICT_EMPTY);
	if (!size)
		dict->size = DEFAULT_SIZE;
	else
		dict->size = size;
	buckets = dict_alloc_buckets(dict->size);
	if (!buckets)
	{
		free(dict);
		return (DICT_EMPTY);
	}
	dict->buckets = buckets;
	dict->cmp = cmp;
	dict->hash_key = hash_key;
	dict->used = 0;
	dict->dealloc_key = dealloc_key;
	dict->prime = PRIME_DEFAULT;
	srandom(time(NULL));
	dict->a = 1 + random() / dict->prime;
	dict->b = random() / dict->prime;
	return (dict);
}

/**
 * @brief Get all buckets from dict
 *
 * @param dict
 * @return linked list array of dict->size
 */
t_linkedlist	*dict_get_buckets(t_dict dict)
{
	if (!dict)
		return (NULL);
	return (dict->buckets);
}

/**
 * @brief Frees all memory used by dict
 *
 * @param dict
 */
void	dict_free(t_generic dict)
{
	const t_dict	d = (t_dict)dict;
	size_t			i;
	t_linkedlist	bucket;

	i = 0;
	while (i < d->size)
	{
		bucket = ((d->buckets)[i]);
		linkedlist_dealloc(bucket, &dict_obj_dealloc);
		i++;
	}
	free(d->buckets);
	free(dict);
}
