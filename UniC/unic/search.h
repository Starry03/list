//
// Created by andre on 4/18/2023.
//

#ifndef SEARCH_H
# define SEARCH_H

# include "types.h"
# include <stdbool.h>
# include <stddef.h>

size_t	linear_search(const t_generic *arr, size_t length, t_generic target,
			t_comparator cmp);

size_t	binary_search(const t_generic *arr, size_t length, t_generic target,
			t_comparator cmp);

#endif // STARRY_SEARCH_H
