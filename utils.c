#include "UniC/Utils/types.h"
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

void	ft_print_n(char c, size_t n)
{
	size_t	i;

	i = 0;
	while (i++ < n)
		printf("%c", c);
}

int	string_compare(Generic a, Generic b)
{
	return (strcmp((char *)a, (char *)b));
}
