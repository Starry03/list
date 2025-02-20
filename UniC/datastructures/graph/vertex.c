#include "unic/graph.h"
#include <stdlib.h>

t_vertex	vertex_init(t_generic value)
{
	static uint32_t	id = 0;
	t_vertex		vertex;

	vertex = (t_vertex)malloc(sizeof(t_vertex_));
	if (!vertex)
		return (NULL);
	vertex->edges = LINKEDLIST_EMPTY;
	vertex->value = value;
	vertex->id = id++;
	vertex->status = VERTEX_UNVISITED;
	vertex->distance = 0;
	vertex->discovery_time = 0;
	vertex->finish_time = 0;
	vertex->predecessor = NULL;
	return (vertex);
}
void	vertex_free(t_graph graph, t_vertex vertex)
{
	linkedlist_dealloc(vertex->edges, edge_free);
	if (graph->dealloc_vertex)
		graph->dealloc_vertex(vertex->value);
	free(vertex);
}
