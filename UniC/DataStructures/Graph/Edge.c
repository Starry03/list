#include "Edge.h"

Edge	Edge_Init(GraphNode from, GraphNode to, size_t weight)
{
	Edge	edge;

	edge = (Edge)malloc(sizeof(t_edge));
	if (!edge)
		return (NULL);
	edge->from = from;
	edge->to = to;
	edge->weight = weight;
	return (edge);
}
void	Edge_Free(Generic edge)
{
	Edge	e;

	if (!edge)
		return ;
	e = (Edge)edge;
	free(e);
}

int	Edge_Cmp(Generic a, Generic b)
{
	if (!a || !b)
		return (false);

	Edge edge_a = (Edge)a;
	Edge edge_b = (Edge)b;

	return (GraphNode_Cmp(edge_a->from, edge_b->from)
		&& GraphNode_Cmp(edge_a->to, edge_b->to)
		&& edge_a->weight == edge_b->weight);
}