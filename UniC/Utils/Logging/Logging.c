//
// Created by andre on 3/18/2024.
//

#include "Logging.h"
#include <stdio.h>
#include "colors.h"

void Log_intarray(int *arr, size_t size, size_t new_index) {
	printf("[\t");
	size_t i = 0;
	while (i < size) {
		if (i == new_index)
			printf("%s%d%s\t", GRN, arr[i], reset);
		else printf("%d\t", arr[i]);
		i++;
	}
	printf("]\n");
}
