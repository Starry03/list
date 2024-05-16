//
// Created by andre on 8/9/2023.
//

#ifndef STARRY_CLIBRARY_HASHFUNCTIONS_H
#define STARRY_CLIBRARY_HASHFUNCTIONS_H

#include <stddef.h>
#include <stdint.h>
#include "../types.h"

size_t hash_int(Generic key, size_t size);

size_t hash_long(Generic key, size_t size);

size_t hash_float(Generic key, size_t size);

size_t hash_double(Generic key, size_t size);

size_t hash_char(Generic key, size_t size);

size_t hash_string(Generic key, size_t size);

size_t hash_generic(size_t addr, size_t size);

#endif //STARRY_CLIBRARY_HASHFUNCTIONS_H
