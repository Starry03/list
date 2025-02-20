//
// Created by andre on 8/9/2023.
//

#ifndef HASHFUNCTIONS_H
# define HASHFUNCTIONS_H

# include "unic/types.h"
# include <stddef.h>
# include <stdint.h>

size_t	hash_int(t_generic key, size_t size);

size_t	hash_long(t_generic key, size_t size);

size_t	hash_float(t_generic key, size_t size);

size_t	hash_double(t_generic key, size_t size);

size_t	hash_char(t_generic key, size_t size);

size_t	hash_string(t_generic key, size_t size);

size_t	hash_generic(size_t bytes, size_t size);

size_t	hash_universal(size_t key, uint64_t a, uint64_t b, uint64_t p,
			size_t size);

#endif // STARRY_CLIBRARY_HASHFUNCTIONS_H
