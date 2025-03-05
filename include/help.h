#pragma once

#ifndef LOG_PATH
# define LOG_PATH "./changes.log"
#endif

#include "unic/types.h"

#define VERSION_STRING "Version 2.3"
#define PRINT_VERSION printf("%s\n", VERSION_STRING)

void			print_change_log(void);

extern t_string	LIST_HELP_STRING;
