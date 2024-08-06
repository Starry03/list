#include "Graph.h"
#include <stdlib.h>

Edge	Edge_Init(Vertex src, Vertex dest, uint64_t weight)
{
	Edge	edge;

	edge = (Edge)malloc(sizeof(t_edge));
	if (!edge)
		return (NULL);
	edge->src = src;
	edge->dest = dest;
	edge->weight = weight;
	return (edge);
}
void	Edge_Free(Generic edge)
{
	free(edge);
}
