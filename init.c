#include "UniC/Utils/Hashing/HashFunctions.h"
#include "UniC/libft/libft.h"
#include "list.h"
#include <stdio.h>
#include <string.h>

#ifndef ICON_PATH
# define ICON_PATH "./icons.txt"
#endif

#define BUFSIZE 64

void	init(t_dict *icons)
{
	const char *ICONS_PATH = ICON_PATH;
	FILE *icons_file;
	char buf[BUFSIZE];
	char *key, *value;

	icons_file = fopen(ICONS_PATH, "r");
	if (!icons_file)
		return ;
	while (fgets(buf, BUFSIZE, icons_file))
	{
		key = ft_strdup(strtok(buf, " "));
		value = ft_strdup(strtok(NULL, " "));
		if (strrchr(value, '\n'))
			*strrchr(value, '\n') = '\0';
		Dict_Add(icons, key, value, hash_string, &free, &free);
	}
	fclose(icons_file);
}