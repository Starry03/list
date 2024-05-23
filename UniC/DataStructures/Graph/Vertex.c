#include "Graph.h"
#include <stdlib.h>

Vertex	Vertex_Init(Generic value)
{
	static uint32_t	id = 0;
	Vertex			vertex;

	vertex = (Vertex)malloc(sizeof(t_vertex));
	if (!vertex)
		return (NULL);
	vertex->edges = LINKEDLIST_EMPTY;
	vertex->value = value;
	vertex->id = id++;
	vertex->status = VERTEX_UNVISITED;
	vertex->distance = 0;
	vertex->time = 0;
	return (vertex);
}
void	Vertex_Free(Graph graph, Vertex vertex)
{
	LinkedList_Dealloc(vertex->edges, Edge_Free);
	if (graph->dealloc_vertex)
		graph->dealloc_vertex(vertex->value);
	free(vertex);
}
