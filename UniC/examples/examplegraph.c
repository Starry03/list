#include "unic/examples.h"
# include "unic/comparators.h"

/**
 * @return an example graph
 */
t_graph	get_example_graph(void)
{
	t_graph		graph;
	t_vertex	v1;
	t_vertex	v2;
	t_vertex	v3;
	t_vertex	v4;
	t_vertex	v5;
	t_vertex	v6;

	graph = graph_init(NULL, Compare_String);
	v1 = vertex_init("a");
	v2 = vertex_init("b");
	v3 = vertex_init("c");
	v4 = vertex_init("d");
	v5 = vertex_init("e");
	v6 = vertex_init("f");
	// add vertices to the graph
	graph_add_vertex(graph, v6);
	graph_add_vertex(graph, v5);
	graph_add_vertex(graph, v4);
	graph_add_vertex(graph, v3);
	graph_add_vertex(graph, v2);
	graph_add_vertex(graph, v1);
	// add edges to the graph
	graph_add_edge(v5, edge_init(v5, v6, 2));
	graph_add_edge(v6, edge_init(v6, v1, 1));
	graph_add_edge(v6, edge_init(v6, v3, 3));
	graph_add_edge(v6, edge_init(v6, v5, 6));
	graph_add_edge(v4, edge_init(v4, v5, 3));
	graph_add_edge(v2, edge_init(v2, v5, 1));
	graph_add_edge(v2, edge_init(v2, v3, 4));
	graph_add_edge(v1, edge_init(v1, v4, 1));
	graph_add_edge(v1, edge_init(v1, v2, 2));
	return (graph);
}
