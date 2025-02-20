#include "unic/graph.h"
#include "unic/dealloc.h"
#include "unic/heap.h"
#include <limits.h>
#include <stdlib.h>

void	vertex_init_single_source(t_graph graph, t_vertex src)
{
	t_linkedlist	vertices;
	t_vertex		vertex;

	if (!graph)
		return ;
	vertices = graph->adjacency_list;
	while (vertices)
	{
		vertex = (t_vertex)(vertices->info);
		vertex->distance = UINT64_MAX;
		vertex->discovery_time = 0;
		vertex->finish_time = 0;
		vertex->status = VERTEX_UNVISITED;
		vertex->predecessor = NULL;
		vertices = linkedlist_getnext(vertices);
	}
	if (!src)
		return ;
	src->distance = 0;
}

bool	edge_relax(t_vertex src, t_vertex dest, uint64_t weight)
{
	if (dest->distance <= src->distance + weight)
		return (false);
	dest->distance = src->distance + weight;
	dest->predecessor = src;
	return (true);
}

int	vertex_cmp_distance(t_generic a, t_generic b)
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

int	vertex_cmp_id(t_generic a, t_generic b)
{
	return ((int)((t_vertex)a)->id - (int)((t_vertex)b)->id);
}

void	dijkstra_heapentry_free(t_generic entry)
{
	t_heap_entry	e;

	e = (t_heap_entry)entry;
	dealloc_uint64(e->key);
	free(e);
}

size_t	vertex_hash(t_generic vertex, size_t capacity)
{
	return (((size_t)((t_vertex)vertex)->id) % capacity);
}

t_linkedlist	build_path(t_vertex dest)
{
	t_linkedlist	path;

	path = NULL;
	while (dest)
	{
		linkedlist_push(&path, dest);
		dest = dest->predecessor;
	}
	return (path);
}
