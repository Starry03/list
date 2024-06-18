#include "Graph.h"
#include <stdlib.h>
#include <assert.h>

Graph	Graph_Init(void (*dealloc_vertex)(Generic), int (*cmp)(Generic,
			Generic))
{
	Graph	graph;

	graph = (Graph)malloc(sizeof(t_graph));
	if (!graph)
		return (NULL);
	graph->adjacency_list = LINKEDLIST_EMPTY;
	graph->cmp = cmp;
	graph->dealloc_vertex = dealloc_vertex;
	return (graph);
}
void	Graph_Free(Graph graph)
{
	LinkedList	adj_list;
	Vertex		vertex;

	if (!graph)
		return ;
	adj_list = graph->adjacency_list;
	while (adj_list)
	{
		vertex = (Vertex)adj_list->info;
		Vertex_Free(graph, vertex);
		adj_list = adj_list->next;
	}
	LinkedList_Dealloc(graph->adjacency_list, NULL);
	free(graph);
}

void	Graph_AddVertex(Graph graph, Vertex vertex)
{
	LinkedList_Push(&graph->adjacency_list, vertex);
}

void	Graph_AddEdge(Vertex vertex, Edge edge)
{
	LinkedList_Push(&vertex->edges, edge);
}

void	Graph_AddDoubleEdge(Vertex vertex, Edge edge)
{
	Edge	double_edge;

	double_edge = Edge_Init(edge->dest, edge->src, edge->weight);
	Graph_AddEdge(vertex, edge);
	Graph_AddEdge(edge->dest, double_edge);
}

void	Graph_RemoveVertex(Graph graph, Vertex vertex)
{
	LinkedList	adj_list;
	Vertex		v;

	adj_list = graph->adjacency_list;
	while (adj_list)
	{
		v = (Vertex)adj_list->info;
		if (v->id == vertex->id)
		{
			Vertex_Free(graph, v);
			LinkedList_Remove(&graph->adjacency_list, NULL);
			return ;
		}
		adj_list = adj_list->next;
	}
}
void	Graph_RemoveEdge(Vertex vertex, Edge edge)
{
	LinkedList	edges;
	Edge		e;

	edges = vertex->edges;
	while (edges)
	{
		e = (Edge)edges->info;
		if (e->dest->id == edge->dest->id)
		{
			LinkedList_Remove(&vertex->edges, Edge_Free);
			return ;
		}
		edges = edges->next;
	}
}

void	Graph_RemoveDoubleEdge(Vertex vertex, Edge edge)
{
	Graph_RemoveEdge(vertex, edge);
	// check if other edge exists
}
