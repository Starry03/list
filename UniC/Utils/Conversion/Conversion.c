#include "Conversion.h"
#include <stdlib.h>

String uintToString(uint64_t n, size_t bits)
{
	size_t i;
	String str;

	if (bits > 64)
		return NULL;
	i = bits;
	str = (String) malloc(sizeof(char) * (i + 1));
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
