//
// Created by andre on 8/9/2023.
//

#include "HashFunctions.h"

#define MAGIC 0xdeadbeef

static size_t	normalize(size_t bytes, size_t size)
{
	return (bytes % size);
}

size_t	hash_int(Generic key, size_t size)
{
	return (hash_generic((size_t)key, size));
}

size_t	hash_string(Generic key, size_t size)
{
	size_t	hash;
	char	*str;

	hash = 0;
	str = (char *)key;
	while (*str)
	{
		hash = hash * 31 + *str;
		str++;
	}
	return (normalize(hash, size));
}

/**
 * @brief
 *
 * @param bytes anything
 * @param size hashmap size
 * @return size_t
 */
size_t	hash_generic(size_t bytes, size_t size)
{
	size_t	bin;

	bin = (size_t)bytes;
	bin = bin ^ (bin >> 4);
	bin = (bin + (bin << 5)) ^ MAGIC;
	bin = bin ^ (bin >> 11);
	return (normalize((size_t)bin, size));
}

size_t	hash_universal(size_t key, uint64_t a, uint64_t b, uint64_t p,
		size_t size)
{
	size_t	hash;

	hash = ((a * key + b) % p);
	return (normalize(hash, size));
}
