#include "utils.h"
#include <stdlib.h>
#include <string.h>

char	*build_path(char *path, char *folder_name)
{
	char	*p;

	p = (char *)malloc(sizeof(char) * (strlen(path) + 1 + strlen(folder_name)
				+ 1));
	if (!p)
		return (NULL);
	strcpy(p, path);
	strcat(p, "/");
	strcat(p, folder_name);
	return (p);
}

size_t	get_size(FILE *file)
{
	size_t	bytes;

	if (!file || fseek(file, 0, SEEK_END) < 0)
		return (0);
	bytes = ftell(file);
	return (bytes);
}

void	ft_print_n(char c, size_t n)
{
	size_t	i;

	i = 0;
	while (i++ < n)
		printf("%c", c);
}
