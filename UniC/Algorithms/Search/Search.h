//
// Created by andre on 4/18/2023.
//

#ifndef SEARCH_H
# define SEARCH_H

# include "../../Utils/types.h"
# include <stdbool.h>
# include <stddef.h>

size_t	LinearSearch(const Generic *arr, size_t length, Generic target,
			Comparator cmp);

size_t	BinarySearch(const Generic *arr, size_t length, Generic target,
			Comparator cmp);

#endif // STARRY_SEARCH_H
