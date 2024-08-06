#include "examples.h"
#include "Utils/Compare/comparators.h"

/**
 * @return an example graph
 */
Graph	get_example_graph(void)
{
	Graph graph;
	Vertex v1;
	Vertex v2;
	Vertex v3;
	Vertex v4;
	Vertex v5;
	Vertex v6;

	graph = Graph_Init(NULL, Compare_String);
	v1 = Vertex_Init("a");
	v2 = Vertex_Init("b");
	v3 = Vertex_Init("c");
	v4 = Vertex_Init("d");
	v5 = Vertex_Init("e");
	v6 = Vertex_Init("f");
	// add vertices to the graph
	Graph_AddVertex(graph, v6);
	Graph_AddVertex(graph, v5);
	Graph_AddVertex(graph, v4);
	Graph_AddVertex(graph, v3);
	Graph_AddVertex(graph, v2);
	Graph_AddVertex(graph, v1);
	// add edges to the graph
	Graph_AddEdge(v5, Edge_Init(v5, v6, 2));
	Graph_AddEdge(v6, Edge_Init(v6, v1, 1));
	Graph_AddEdge(v6, Edge_Init(v6, v3, 3));
	Graph_AddEdge(v6, Edge_Init(v6, v5, 6));
	Graph_AddEdge(v4, Edge_Init(v4, v5, 3));
	Graph_AddEdge(v2, Edge_Init(v2, v5, 1));
	Graph_AddEdge(v2, Edge_Init(v2, v3, 4));
	Graph_AddEdge(v1, Edge_Init(v1, v4, 1));
	Graph_AddEdge(v1, Edge_Init(v1, v2, 2));
	return (graph);
}
