# include "unic/graph.h"
#include <assert.h>
#include <stdlib.h>

t_graph	graph_init(void (*dealloc_vertex)(t_generic), int (*cmp)(t_generic,
			t_generic))
{
	t_graph	graph;

	graph = (t_graph)malloc(sizeof(t_graph_));
	if (!graph)
		return (NULL);
	graph->adjacency_list = LINKEDLIST_EMPTY;
	graph->cmp = cmp;
	graph->dealloc_vertex = dealloc_vertex;
	return (graph);
}

void	graph_free(t_graph graph)
{
	t_linkedlist	adj_list;
	t_vertex		vertex;

	if (!graph)
		return ;
	adj_list = graph->adjacency_list;
	while (adj_list)
	{
		vertex = (t_vertex)adj_list->info;
		vertex_free(graph, vertex);
		adj_list = adj_list->next;
	}
	linkedlist_dealloc(graph->adjacency_list, NULL);
	free(graph);
}

void	graph_add_vertex(t_graph graph, t_vertex vertex)
{
	linkedlist_push(&graph->adjacency_list, vertex);
}

void	graph_add_edge(t_vertex vertex, t_edge edge)
{
	linkedlist_push(&vertex->edges, edge);
}

void	graph_add_double_edge(t_vertex vertex, t_edge edge)
{
	t_edge	double_edge;

	double_edge = edge_init(edge->dest, edge->src, edge->weight);
	graph_add_edge(vertex, edge);
	graph_add_edge(edge->dest, double_edge);
}

void	graph_remove_vertex(t_graph graph, t_vertex vertex)
{
	t_linkedlist	adj_list;
	t_vertex		v;

	adj_list = graph->adjacency_list;
	while (adj_list)
	{
		v = (t_vertex)adj_list->info;
		if (v->id == vertex->id)
		{
			vertex_free(graph, v);
			linkedlist_remove(&graph->adjacency_list, NULL);
			return ;
		}
		adj_list = adj_list->next;
	}
}

void	graph_remove_edge(t_vertex vertex, t_edge edge)
{
	t_linkedlist	edges;
	t_edge			e;

	edges = vertex->edges;
	while (edges)
	{
		e = (t_edge)edges->info;
		if (e->dest->id == edge->dest->id)
		{
			linkedlist_remove(&vertex->edges, edge_free);
			return ;
		}
		edges = edges->next;
	}
}

void	graph_remove_double_edge(t_vertex vertex, t_edge edge)
{
	graph_remove_edge(vertex, edge);
	// check if other edge exists
}
