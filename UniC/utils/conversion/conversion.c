# include "unic/conversion.h"
#include <stdlib.h>

t_string	uintToString(uint64_t n, size_t bits)
{
	size_t		i;
	t_string	str;

	if (bits > 64)
		return (NULL);
	i = bits;
	str = (t_string)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = 0;
	while (i--)
	{
		str[i] = '0' + (n & 1);
		n >>= 1;
	}
	return (str);
}
