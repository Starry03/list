#include "unic/comparators.h"
#include <stdint.h>
#include <string.h>

int	cmp_string(t_generic a, t_generic b)
{
	if (!b && !a)
		return (0);
	if (!a)
		return (-1);
	if (!b)
		return (1);
	return (strcmp((char *)a, (char *)b));
}

int	cmp_int(t_generic a, t_generic b)
{
	int	x;
	int	y;

	if (!b && !a)
		return (0);
	if (!a)
		return (-1);
	if (!b)
		return (1);
	x = *(int *)a;
	y = *(int *)b;
	if (x == y)
		return (0);
	if (x < y)
		return (-1);
	return (1);
}

int	cmp_uint16(t_generic a, t_generic b)
{
	if (!b && !a)
		return (0);
	if (!a)
		return (-1);
	if (!b)
		return (1);
	if (*(uint16_t *)a < *(uint16_t *)b)
		return (-1);
	if (*(uint16_t *)a > *(uint16_t *)b)
		return (1);
	return (0);
}

int	cmp_uint64(t_generic a, t_generic b)
{
	if (!b && !a)
		return (0);
	if (!a)
		return (-1);
	if (!b)
		return (1);
	if (*(uint64_t *)a < *(uint64_t *)b)
		return (-1);
	if (*(uint64_t *)a > *(uint64_t *)b)
		return (1);
	return (0);
}
