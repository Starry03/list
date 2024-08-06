#include "../../Utils/Dealloc/Dealloc.h"
#include "../Dictionary/Dictionary.h"
#include "../Heap/Heap.h"
#include "Graph.h"
#include <stdlib.h>

static void	Dijkstra_Init_MinHeap_Hashmap(t_heap min_heap, LinkedList vertices,
		t_dict hashmap)
{
	uint64_t		*dist;
	t_heap_entry	entry;
	Vertex			vertex;

	if (!min_heap || !vertices || !hashmap)
		return ;
	while (vertices)
	{
		vertex = LinkedList_GetInfo(vertices);
		dist = (uint64_t *)malloc(sizeof(uint64_t));
		*dist = vertex->distance;
		entry = HeapEntry_Init(dist, vertex);
		Heap_Insert(min_heap, entry);
		Dict_Add(hashmap, vertex, entry, NULL);
		vertices = LinkedList_GetNext(vertices);
	}
}

/**
 * @brief Dijkstra's algorithm to find the shortest path in a graph.
 * @note min_heap_entry: {distance: uint64_t, vertex: Vertex}
 */
LinkedList	Dijkstra(Graph graph, Vertex src, Vertex dest)
{
	LinkedList		path;
	t_heap			min_heap;
	t_dict			hashmap;
	LinkedList		vertices;
	Vertex			vertex;
	LinkedList		vertex_edges;
	Edge			edge;
	uint64_t		*weight_ref;
	t_heap_entry	entry;
	t_heap_entry	entry_from_dict;
	LinkedList		visited_entries;

	path = NULL;
	visited_entries = NULL;
	if (!graph || !src || !dest)
		return (NULL);
	vertices = graph->adjacency_list;
	hashmap = Dict_Init(LinkedList_Size(vertices), Vertex_CmpId, Vertex_Hash, NULL);
	if (!hashmap)
		return (NULL);
	min_heap = Heap_Init(LinkedList_Size(vertices), Vertex_CmpDistance,
			DijkstraHeapEntry_Free, true);
	if (!min_heap)
	{
		Dict_Free(hashmap);
		return (NULL);
	}
	Vertex_InitSingleSource(graph, src);
	Dijkstra_Init_MinHeap_Hashmap(min_heap, vertices, hashmap);
	/* gready approach */
	while ((entry = Heap_PollMin(min_heap)))
	{
		vertex = (Vertex)entry->value;
		vertex_edges = vertex->edges;
		// relax out edges
		while ((edge = (Edge)LinkedList_GetInfo(vertex_edges)))
		{
			entry_from_dict = ((t_heap_entry)Dict_Get(hashmap, edge->dest));
			if (Edge_Relax(vertex, edge->dest, edge->weight))
			{
				weight_ref = (uint64_t *)(entry_from_dict->key);
				*weight_ref = edge->dest->distance;
			}
			vertex_edges = LinkedList_GetNext(vertex_edges);
		}
		LinkedList_Push(&visited_entries, entry);
	}
	path = BuildPath(dest);
	LinkedList_Dealloc(visited_entries, DijkstraHeapEntry_Free);
	Dict_Free(hashmap);
	Heap_Free(min_heap);
	return (path);
}
