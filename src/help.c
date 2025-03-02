#include "help.h"
#include <stdio.h>

t_string	LIST_HELP_STRING = "Usage: list <path> -flags	\n"
							"Options:					\n"
							"	-d	Log dimensions		\n"
							"	-R	Recursive			\n"
							"	-a	Show hidden files	\n"
							"	-V	Show version		\n"
							"	-l	Show permissions	\n"
							"	-h	Show help			\n";

void	print_change_log(void)
{
	FILE	*file;
	char	c;

	file = fopen(LOG_PATH, "r");
	if (!file)
	{
		printf("No change log found\n");
		return ;
	}
	while ((c = fgetc(file)) != EOF)
		printf("%c", c);
	fclose(file);
}
