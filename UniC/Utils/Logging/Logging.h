//
// Created by andre on 3/18/2024.
//

#ifndef STARRY_CLIBRARY_LOGGING_H
# define STARRY_CLIBRARY_LOGGING_H

# include <stddef.h>

typedef enum
{
	LOG_INFO,
	LOG_WARNING,
	LOG_ERROR,
	LOG_FATAL
}		e_log_type;

void	Log(e_log_type type, const char *message);
void	Log_intarray(int *arr, size_t size, size_t new_index);

#endif // STARRY_CLIBRARY_LOGGING_H
