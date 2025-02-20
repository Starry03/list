# include "unic/graph.h"
#include <stdlib.h>

t_edge	edge_init(t_vertex src, t_vertex dest, uint64_t weight)
{
	t_edge	edge;

	edge = (t_edge)malloc(sizeof(t_edge_));
	if (!edge)
		return (NULL);
	edge->src = src;
	edge->dest = dest;
	edge->weight = weight;
	return (edge);
}

void	edge_free(t_generic edge)
{
	free(edge);
}
