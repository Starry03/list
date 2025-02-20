#include "libft.h"

char	*ft_strfjoin(char *s1, char *s2)
{
	char *new_str;

	new_str = ft_strjoin(s1, s2);
	free(s1);
	return (new_str);
}