# include "unic/graph.h"
#include <stdio.h>

/**
 * @brief Generate a mermaid file from a graph
 * @param graph
 * @param filename (generate or replace)
 * @param direction (MERMAID_VERTICAL or MERMAID_HORIZONAL)
 */
void	graph_generate_mermaid(t_graph graph, t_string filename, t_string direction)
{
	FILE			*file;
	t_linkedlist	vertices;
	t_vertex		vertex;
	t_linkedlist	edges;
	t_edge			edge;

	file = fopen(filename, "w");
	if (!file)
		return ;
	fprintf(file, "```mermaid\nflowchart %s\n",
		(direction) ? direction : MERMAID_HORIZONAL);
	vertices = graph->adjacency_list;
	while (vertices)
	{
		vertex = (t_vertex)linkedlist_getinfo(vertices);
		edges = vertex->edges;
		if (!edges)
			fprintf(file, "%zu((%s))\n", vertex->id, (t_string)vertex->value);
		else
		{
			while (edges)
			{
				edge = (t_edge)linkedlist_getinfo(edges);
				fprintf(file, "%zu((%s)) -- %zu --> %zu((%s))\n", edge->src->id,
					(t_string)edge->src->value, edge->weight, edge->dest->id,
					(t_string)edge->dest->value);
				edges = linkedlist_getnext(edges);
			}
		}
		vertices = linkedlist_getnext(vertices);
	}
	fprintf(file, "```\n");
	fclose(file);
}
