# include "unic/dictionary.h"
# include "unic/graph.h"
# include "unic/heap.h"
#include <stdlib.h>

static void	dijkstra_init_minheap_hashmap(t_heap min_heap,
		t_linkedlist vertices, t_dict hashmap)
{
	uint64_t		*dist;
	t_heap_entry	entry;
	t_vertex		vertex;

	if (!min_heap || !vertices || !hashmap)
		return ;
	while (vertices)
	{
		vertex = linkedlist_getinfo(vertices);
		dist = (uint64_t *)malloc(sizeof(uint64_t));
		*dist = vertex->distance;
		entry = heap_entry_Init(dist, vertex);
		heap_insert(min_heap, entry);
		dict_add(hashmap, vertex, entry, NULL);
		vertices = linkedlist_getnext(vertices);
	}
}

/**
 * @brief Dijkstra's algorithm to find the shortest path in a graph.
 * @note min_heap_entry: {distance: uint64_t, vertex: Vertex}
 */
t_linkedlist	dijkstra(t_graph graph, t_vertex src, t_vertex dest)
{
	t_linkedlist	path;
	t_heap			min_heap;
	t_dict			hashmap;
	t_linkedlist	vertices;
	t_vertex		vertex;
	t_linkedlist	vertex_edges;
	t_edge			edge;
	uint64_t		*weight_ref;
	t_heap_entry	entry;
	t_heap_entry	entry_from_dict;
	t_linkedlist	visited_entries;

	path = NULL;
	visited_entries = NULL;
	if (!graph || !src || !dest)
		return (NULL);
	vertices = graph->adjacency_list;
	hashmap = dict_init(linkedlist_size(vertices), vertex_cmp_id, vertex_hash,
			NULL);
	if (!hashmap)
		return (NULL);
	min_heap = heap_init(linkedlist_size(vertices), vertex_cmp_distance,
			dijkstra_heapentry_free, true);
	if (!min_heap)
	{
		dict_free(hashmap);
		return (NULL);
	}
	vertex_init_single_source(graph, src);
	dijkstra_init_minheap_hashmap(min_heap, vertices, hashmap);
	/* gready approach */
	while ((entry = heap_pollmin(min_heap)))
	{
		vertex = (t_vertex)entry->value;
		vertex_edges = vertex->edges;
		// relax out edges
		while ((edge = (t_edge)linkedlist_getinfo(vertex_edges)))
		{
			entry_from_dict = ((t_heap_entry)dict_get(hashmap, edge->dest));
			if (edge_relax(vertex, edge->dest, edge->weight))
			{
				weight_ref = (uint64_t *)(entry_from_dict->key);
				*weight_ref = edge->dest->distance;
			}
			vertex_edges = linkedlist_getnext(vertex_edges);
		}
		linkedlist_push(&visited_entries, entry);
	}
	path = build_path(dest);
	linkedlist_dealloc(visited_entries, dijkstra_heapentry_free);
	dict_free(hashmap);
	heap_free(min_heap);
	return (path);
}
