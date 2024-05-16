//
// Created by andre on 8/9/2023.
//

#include "HashFunctions.h"

#define MAGIC 0xdeadbeef

static size_t normalize(size_t bytes, size_t size) {
    return bytes % size;
}

/**
 * @brief 
 * 
 * @param bytes anything
 * @param size hashmap size
 * @return size_t 
 */
size_t hash_generic(Generic bytes, size_t size)
{
	size_t bin = (size_t)bytes;
	bin = bin ^ (bin >> 4);
	bin = (bin + (bin << 5)) ^ MAGIC;
	bin = bin ^ (bin >> 11);
	return normalize((size_t)bin, size);
}
