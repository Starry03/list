# include "unic/queue.h"
# include "unic/graph.h"
#include <stdio.h>

/**
 * @brief BFS
 * @param graph
 * @param src
 * @param target: value of a vertex to find,
	if null will explore the whole graph
 */
t_vertex	graph_bfs(t_graph graph, t_vertex src, t_generic target)
{
	t_queue			queue;
	t_queue			queue_el;
	t_vertex		vertex;
	t_vertex		dst;
	t_edge			edge;
	t_linkedlist	edges;

	vertex = NULL;
	vertex_init_single_source(graph, src);
	queue = queue_init(src);
	while ((queue_el = queue_poll(&queue)))
	{
		vertex = (t_vertex)(queue_el->info);
		edges = vertex->edges;
		while (edges)
		{
			edge = (t_edge)linkedlist_getinfo(edges);
			dst = edge->dest;
			if (dst->status == VERTEX_UNVISITED)
			{
				dst->status = VERTEX_VISITING;
				dst->distance = vertex->distance + edge->weight;
				dst->predecessor = vertex;
				queue_add(&queue, dst);
			}
			edges = linkedlist_getnext(edges);
		}
		vertex->status = VERTEX_VISITED;
		queue_deallocelement(queue_el, NULL);
		if (graph->cmp && graph->cmp(vertex->value, target) == 0)
			break ;
	}
	queue_dealloc(&queue, NULL);
	return (vertex);
}

static void	DFS_Visit(t_vertex vertex, uint64_t *time)
{
	t_linkedlist	edges;
	t_vertex		neighbor;

	vertex->discovery_time = *time++;
	vertex->status = VERTEX_VISITING;
	edges = vertex->edges;
	while (edges)
	{
		neighbor = ((t_edge)linkedlist_getinfo(edges))->dest;
		if (neighbor->status == VERTEX_UNVISITED)
			DFS_Visit(neighbor, time);
		edges = linkedlist_getnext(edges);
	}
	printf("ended vertex %s\n", (char *)vertex->value);
	vertex->status = VERTEX_VISITED;
	vertex->finish_time = *time++;
}

/**
 * @brief DFS
 * @param graph
 */
t_vertex	graph_dfs(t_graph graph)
{
	t_linkedlist	vertices;
	t_vertex		vertex;
	uint64_t		time;

	time = 0;
	vertices = graph->adjacency_list;
	vertex_init_single_source(graph, NULL);
	while (vertices)
	{
		vertex = linkedlist_getinfo(vertices);
		if (vertex->status == VERTEX_UNVISITED)
			DFS_Visit(vertex, &time);
		vertices = linkedlist_getnext(vertices);
	}
	return (NULL);
}
