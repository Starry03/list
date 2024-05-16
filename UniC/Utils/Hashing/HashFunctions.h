//
// Created by andre on 8/9/2023.
//

#ifndef STARRY_CLIBRARY_HASHFUNCTIONS_H
#define STARRY_CLIBRARY_HASHFUNCTIONS_H

#include <stddef.h>
#include <stdint.h>
#include "../types.h"

size_t hash_int(void *key, size_t size);

size_t hash_long(void *key, size_t size);

size_t hash_float(void *key, size_t size);

size_t hash_double(void *key, size_t size);

size_t hash_char(void *key, size_t size);

size_t hash_string(void *key, size_t size);

size_t hash_generic(Generic addr, size_t size);

#endif //STARRY_CLIBRARY_HASHFUNCTIONS_H
