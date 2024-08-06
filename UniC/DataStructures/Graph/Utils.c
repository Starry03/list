#include "../../Utils/Dealloc/Dealloc.h"
#include "../Heap/Heap.h"
#include "Graph.h"
#include <limits.h>
#include <stdlib.h>

void	Vertex_InitSingleSource(Graph graph, Vertex src)
{
	LinkedList	vertices;
	Vertex		vertex;

	if (!graph)
		return ;
	vertices = graph->adjacency_list;
	while (vertices)
	{
		vertex = (Vertex)(vertices->info);
		vertex->distance = UINT64_MAX;
		vertex->discovery_time = 0;
		vertex->finish_time = 0;
		vertex->status = VERTEX_UNVISITED;
		vertex->predecessor = NULL;
		vertices = LinkedList_GetNext(vertices);
	}
	if (!src)
		return ;
	src->distance = 0;
}

bool	Edge_Relax(Vertex src, Vertex dest, uint64_t weight)
{
	if (dest->distance <= src->distance + weight)
		return (false);
	dest->distance = src->distance + weight;
	dest->predecessor = src;
	return (true);
}

int	Vertex_CmpDistance(Generic a, Generic b)
{
	uint64_t	*dist_a;
	uint64_t	*dist_b;

	dist_a = (uint64_t *)((t_heap_entry)a)->key;
	dist_b = (uint64_t *)((t_heap_entry)b)->key;
	if (*dist_a < *dist_b)
		return (-1);
	if (*dist_a > *dist_b)
		return (1);
	return (0);
}

int	Vertex_CmpId(Generic a, Generic b)
{
	return ((int)((Vertex)a)->id - (int)((Vertex)b)->id);
}

void	DijkstraHeapEntry_Free(Generic entry)
{
	t_heap_entry	e;

	e = (t_heap_entry)entry;
	dealloc_uint64(e->key);
	free(e);
}

size_t	Vertex_Hash(Generic vertex, size_t capacity)
{
	return (((size_t)((Vertex)vertex)->id) % capacity);
}

LinkedList	BuildPath(Vertex dest)
{
	LinkedList	path;

	path = NULL;
	while (dest)
	{
		LinkedList_Push(&path, dest);
		dest = dest->predecessor;
	}
	return (path);
}
