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

void	Log(e_log_type type, const char *message)
{
	switch (type)
	{
		case LOG_INFO:
			printf("%s[INFO]%s %s\n", HGRN, reset, message);
			break;
		case LOG_WARNING:
			printf("%s[WARNING]%s %s\n", HYEL, reset, message);
			break;
		case LOG_ERROR:
			printf("%s[ERROR]%s %s\n", HRED, reset, message);
			break;
		case LOG_FATAL:
			printf("%s[FATAL]%s %s\n", HRED, reset, message);
			break;
	}
}
