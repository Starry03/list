#include "unic/types.h"
#include "utils.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

t_string	build_path(t_string path, t_string folder_name)
{
	char	*p;

	p = (t_string)malloc(sizeof(char) * (strlen(path) + 1 + strlen(folder_name)
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

int	string_compare_ignore_case(t_generic a, t_generic b)
{
	char	*sa;
	char	*sb;
	int		diff;

	if (!a || !b)
		return (0);
	sa = (char *)a;
	sb = (char *)b;
	while (*sa && *sb)
	{
		diff = tolower(*sa) - tolower(*sb);
		if (diff)
			return (diff);
		sa++;
		sb++;
	}
	return (tolower(*sa) - tolower(*sb));
}
