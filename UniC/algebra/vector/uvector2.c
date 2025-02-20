# include "unic/uvector2.h"
#include <stdlib.h>

t_uvector2	uvector2_init(uint64_t x, uint64_t y)
{
	t_uvector2	vector;

	vector = malloc(sizeof(t_uvector2_));
	if (!vector)
		return (NULL);
	vector->x = x;
	vector->y = y;
	return (vector);
}
void	uvector2_free(t_uvector2 vector)
{
	if (!vector)
		return ;
	free(vector);
}