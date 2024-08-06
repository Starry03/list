#include "../Queue/Queue.h"
#include "Graph.h"
#include <stdio.h>

/**
 * @brief BFS
 * @param graph
 * @param src
 * @param target: value of a vertex to find,
	if null will explore the whole graph
 */
Vertex	Graph_BFS(Graph graph, Vertex src, Generic target)
{
	Queue		queue;
	Queue		queue_el;
	Vertex		vertex;
	Vertex		dst;
	Edge		edge;
	LinkedList	edges;

	vertex = NULL;
	Vertex_InitSingleSource(graph, src);
	queue = Queue_Init(src);
	while ((queue_el = Queue_poll(&queue)))
	{
		vertex = (Vertex)(queue_el->info);
		edges = vertex->edges;
		while (edges)
		{
			edge = (Edge)LinkedList_GetInfo(edges);
			dst = edge->dest;
			if (dst->status == VERTEX_UNVISITED)
			{
				dst->status = VERTEX_VISITING;
				dst->distance = vertex->distance + edge->weight;
				dst->predecessor = vertex;
				Queue_Add(&queue, dst);
			}
			edges = LinkedList_GetNext(edges);
		}
		vertex->status = VERTEX_VISITED;
		Queue_DeallocElement(queue_el, NULL);
		if (graph->cmp && graph->cmp(vertex->value, target) == 0)
			break ;
	}
	Queue_Dealloc(&queue, NULL);
	return (vertex);
}

static void	DFS_Visit(Vertex vertex, uint64_t *time)
{
	LinkedList	edges;
	Vertex		neighbor;

	vertex->discovery_time = *time++;
	vertex->status = VERTEX_VISITING;
	edges = vertex->edges;
	while (edges)
	{
		neighbor = ((Edge)LinkedList_GetInfo(edges))->dest;
		if (neighbor->status == VERTEX_UNVISITED)
			DFS_Visit(neighbor, time);
		edges = LinkedList_GetNext(edges);
	}
	printf("ended vertex %s\n", (char *)vertex->value);
	vertex->status = VERTEX_VISITED;
	vertex->finish_time = *time++;
}

/**
 * @brief DFS
 * @param graph
 */
Vertex	Graph_DFS(Graph graph)
{
	LinkedList	vertices;
	Vertex		vertex;
	uint64_t	time;

	time = 0;
	vertices = graph->adjacency_list;
	Vertex_InitSingleSource(graph, NULL);
	while (vertices)
	{
		vertex = LinkedList_GetInfo(vertices);
		if (vertex->status == VERTEX_UNVISITED)
			DFS_Visit(vertex, &time);
		vertices = LinkedList_GetNext(vertices);
	}
	return (NULL);
}
