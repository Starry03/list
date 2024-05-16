//
// Created by andre on 4/18/2023.
//

#ifndef STARRY_SEARCH_H
# define STARRY_SEARCH_H

# include "../../Utils/types.h"
# include <stdbool.h>
# include <stddef.h>

size_t	LinearSearch(const Generic *arr, size_t length, Generic target,
			bool (*cmp)(Generic, Generic));

size_t	BinarySearch(const Generic *arr, size_t length, Generic target,
			bool (*cmp)(Generic, Generic));

#endif // STARRY_SEARCH_H
