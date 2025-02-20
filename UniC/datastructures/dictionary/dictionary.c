//
// Created by andre on 10/11/2023.
//

#include "unic/dictionary.h"
#include "unic/hashfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/random.h>
#include <time.h>

#define DEFAULT_SIZE 16
#define REALLOC_COEFF 2
#define MAX_LOAD_FACTOR 0.75
#define DICT_EMPTY ((t_dict)NULL)
#define PRIME_DEFAULT ((uint64_t)806526737)

static inline t_dict	Dict_alloc(void)
{
	return (t_dict)malloc(sizeof(t_dictionary));
}

static t_dict_obj	Dict_Obj_Init(t_generic key, t_generic value,
		t_deallocator dealloc_key, t_deallocator dealloc_value)
{
	t_dict_obj	obj;

	obj = (t_dict_obj)malloc(sizeof(t_dict_obj_));
	if (!obj)
		return (NULL);
	obj->key = key;
	obj->value = value;
	obj->dealloc_key = dealloc_key;
	obj->dealloc_value = dealloc_value;
	return (obj);
}

static void	Dict_Obj_Dealloc(t_generic dict_obj)
{
	t_dict_obj	obj;

	obj = (t_dict_obj)dict_obj;
	if (obj->dealloc_key)
		obj->dealloc_key(obj->key);
	if (obj->dealloc_value)
		obj->dealloc_value(obj->value);
	free(dict_obj);
}

static t_linkedlist	*Dict_Alloc_Buckets(size_t size)
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

	dict = Dict_alloc();
	if (!dict)
		return (DICT_EMPTY);
	dict->size = (!size) ? DEFAULT_SIZE : size;
	buckets = Dict_Alloc_Buckets(dict->size);
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

static size_t	hash_function(t_dict dict, size_t hashed_key)
{
	return (hash_universal(hashed_key, dict->a, dict->b, dict->prime,
			dict->size));
}

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

	hash = hash_function(dict, dict->hash_key(obj->key, dict->size));
	bucket = dict->buckets[hash];
	linkedlist_push(&bucket, obj);
	dict->buckets[hash] = bucket;
	dict->used++;
}

/**
 * @brief Reallocates dict with double the size
 * @param dict
 */
static void	Dict_Realloc(t_dict dict)
{
	t_linkedlist	list;
	t_linkedlist	temp;

	list = take_dict_objs(dict);
	temp = list;
	free(dict->buckets);
	dict->buckets = Dict_Alloc_Buckets(dict->size * REALLOC_COEFF);
	dict->size = dict->size * REALLOC_COEFF;
	dict->used = 0;
	while (list)
	{
		soft_add(dict, (t_dict_obj)linkedlist_getinfo(list));
		list = linkedlist_getnext(list);
	}
	linkedlist_dealloc(temp, NULL);
}

static bool	dict_has_breached_load_factor(t_dict dict)
{
	return (((double)(dict->used + 1) / dict->size) >= MAX_LOAD_FACTOR);
}

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
		Dict_Realloc(dict);
	hash = hash_function(dict, dict->hash_key(key, dict->size));
	buckets = dict->buckets;
	obj = Dict_Obj_Init(key, value, dict->dealloc_key, dealloc_value);
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
	const size_t	hash = hash_function(dict, dict->hash_key(key, dict->size));
	t_linkedlist	bucket;
	t_dict_obj		obj;

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
 * @brief Get all buckets from dict
 *
 * @param dict
 * @return linked list
 */
t_linkedlist	*dict_get_buckets(t_dict dict)
{
	if (!dict)
		return (NULL);
	return (dict->buckets);
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
	const size_t	hash = hash_function(dict, dict->hash_key(key, dict->size));
	t_linkedlist	bucket;

	if (!dict || !dict->used)
		return (false);
	if (!dict_get(dict, key))
		return (false);
	bucket = (dict->buckets)[hash];
	while (linkedlist_getinfo(bucket)
		&& dict->cmp(((t_dict_obj)linkedlist_getinfo(bucket))->key, key))
		bucket = linkedlist_getnext(bucket);
	linkedlist_remove(dict->buckets + hash, &Dict_Obj_Dealloc);
	dict->used--;
	return (true);
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
		linkedlist_dealloc(bucket, &Dict_Obj_Dealloc);
		i++;
	}
	free(d->buckets);
	free(dict);
}

/**
 * @brief log the status of the dict
 *
 * @param dict
 */
void	dict_status(t_dict dict)
{
	// t_linkedlist	bucket;
	printf("Number of buckets used: %zu\n", dict->size);
	printf("Number of elements: %zu\n", dict->used);
	printf("Load factor: %f\n", (double)dict->used / dict->size);
	// for (size_t i = 0; i < dict->size; i++)
	// {
	// 	bucket = dict->buckets[i];
	// 	printf("Bucket %zu: %zu elements\n", i, linkedlist_size(bucket));
	// }
}
