//
// Created by andre on 10/11/2023.
//

#include "../../Utils/Hashing/HashFunctions.h"
#include "Dictionary.h"
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

static Dict_obj	Dict_Obj_Init(Generic key, Generic value,
		Deallocator dealloc_key, Deallocator dealloc_value)
{
	Dict_obj	obj;

	obj = (Dict_obj)malloc(sizeof(t_dict_obj));
	if (!obj)
		return (NULL);
	obj->key = key;
	obj->value = value;
	obj->dealloc_key = dealloc_key;
	obj->dealloc_value = dealloc_value;
	return (obj);
}

static void	Dict_Obj_Dealloc(Generic dict_obj)
{
	Dict_obj	obj;

	obj = (Dict_obj)dict_obj;
	if (obj->dealloc_key)
		obj->dealloc_key(obj->key);
	if (obj->dealloc_value)
		obj->dealloc_value(obj->value);
	free(dict_obj);
}

static LinkedList	*Dict_Alloc_Buckets(size_t size)
{
	LinkedList	*buckets;
	size_t		i;

	buckets = (LinkedList *)malloc(sizeof(LinkedList) * size);
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
t_dict	Dict_Init(size_t size, Comparator cmp, Hasher hash_key,
		Deallocator dealloc_key)
{
	LinkedList	*buckets;
	t_dict		dict;

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
 * @return LinkedList of Dict_obj
 */
static LinkedList	take_dict_objs(t_dict dict)
{
	LinkedList	list;
	LinkedList	bucket;
	size_t		i;
	Dict_obj	obj;
	LinkedList	next;

	list = LINKEDLIST_EMPTY;
	i = 0;
	while (i < dict->size)
	{
		bucket = (dict->buckets)[i];
		while (bucket)
		{
			obj = (Dict_obj)(LinkedList_GetInfo(bucket));
			next = LinkedList_GetNext(bucket);
			free(bucket);
			bucket = next;
			LinkedList_Push(&list, obj);
		}
		i++;
	}
	return (list);
}

/**
 * @brief Adds object to dict without checking if key already exists
 * @note Used internally to avoid reallocating dict from zero
 */
static void	soft_add(t_dict dict, Dict_obj obj)
{
	size_t		hash;
	LinkedList	bucket;

	hash = hash_function(dict, dict->hash_key(obj->key, dict->size));
	bucket = dict->buckets[hash];
	LinkedList_Push(&bucket, obj);
	dict->buckets[hash] = bucket;
	dict->used++;
}

/**
 * @brief Reallocates dict with double the size
 * @param dict
 */
static void	Dict_Realloc(t_dict dict)
{
	LinkedList	list;
	LinkedList  temp;

	list = take_dict_objs(dict);
	temp = list;
	free(dict->buckets);
	dict->buckets = Dict_Alloc_Buckets(dict->size * REALLOC_COEFF);
	dict->size = dict->size * REALLOC_COEFF;
	dict->used = 0;
	while (list)
	{
		soft_add(dict, (Dict_obj)LinkedList_GetInfo(list));
		list = LinkedList_GetNext(list);
	}
	LinkedList_Dealloc(temp, NULL);
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
bool	Dict_Add(t_dict dict, Generic key, Generic value,
		Deallocator dealloc_value)
{
	size_t		hash;
	LinkedList	*buckets;
	Dict_obj	obj;

	if (!dict || Dict_Get(dict, key))
		return (false);
	if (dict_has_breached_load_factor(dict))
		Dict_Realloc(dict);
	hash = hash_function(dict, dict->hash_key(key, dict->size));
	buckets = dict->buckets;
	obj = Dict_Obj_Init(key, value, dict->dealloc_key, dealloc_value);
	if (!obj)
		return (false);
	LinkedList_Push(buckets + hash, obj);
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
void	*Dict_Get(t_dict dict, Generic key)
{
	const size_t	hash = hash_function(dict, dict->hash_key(key, dict->size));
	LinkedList		bucket;
	Dict_obj		obj;

	if (!dict || !dict->used)
		return (NULL);
	bucket = (dict->buckets)[hash];
	while (LinkedList_GetInfo(bucket)
		&& dict->cmp(((Dict_obj)LinkedList_GetInfo(bucket))->key, key))
		bucket = LinkedList_GetNext(bucket);
	obj = (Dict_obj)LinkedList_GetInfo(bucket);
	if (!obj)
		return (NULL);
	return (obj->value);
}

/**
 * @brief Remove key and value from dict
 *
 * @param dict
 * @param key
 */
void	Dict_Remove(t_dict dict, Generic key)
{
	const size_t	hash = hash_function(dict, dict->hash_key(key, dict->size));
	LinkedList		bucket;

	bucket = (dict->buckets)[hash];
	while (((Dict_obj)LinkedList_GetInfo(bucket))->key != key)
		bucket = LinkedList_GetNext(bucket);
	LinkedList_Remove(dict->buckets + hash, &Dict_Obj_Dealloc);
}

/**
 * @brief Frees all memory used by dict
 *
 * @param dict
 */
void	Dict_Free(t_dict dict)
{
	size_t		i;
	LinkedList	bucket;

	i = 0;
	while (i < dict->size)
	{
		bucket = ((dict->buckets)[i]);
		LinkedList_Dealloc(bucket, &Dict_Obj_Dealloc);
		i++;
	}
	free(dict->buckets);
	free(dict);
}

/**
 * @brief Log the status of the dict
 *
 * @param dict
 */
void	Dict_Status(t_dict dict)
{
	LinkedList	bucket;

	printf("Number of buckets used: %zu\n", dict->size);
	printf("Number of elements: %zu\n", dict->used);
	printf("Load factor: %f\n", (double)dict->used / dict->size);
	for (size_t i = 0; i < dict->size; i++)
	{
		bucket = dict->buckets[i];
		printf("Bucket %zu: %zu elements\n", i, LinkedList_Size(bucket));
	}
}
