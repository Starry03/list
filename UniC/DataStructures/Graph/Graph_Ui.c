#include "Graph.h"
#include <stdio.h>

/**
 * @brief Generate a mermaid file from a graph
 * @param graph
 * @param filename (generate or replace)
 * @param direction (MERMAID_VERTICAL or MERMAID_HORIZONAL)
 */
void	Graph_GenerateMermaid(Graph graph, String filename, String direction)
{
	FILE		*file;
	LinkedList	vertices;
	Vertex		vertex;
	LinkedList	edges;
	Edge		edge;

	file = fopen(filename, "w");
	if (!file)
		return ;
	fprintf(file, "```mermaid\nflowchart %s\n",
		(direction) ? direction : MERMAID_HORIZONAL);
	vertices = graph->adjacency_list;
	while (vertices)
	{
		vertex = (Vertex)LinkedList_GetInfo(vertices);
		edges = vertex->edges;
		if (!edges)
			fprintf(file, "%zu((%s))\n", vertex->id, (String)vertex->value);
		else
		{
			while (edges)
			{
				edge = (Edge)LinkedList_GetInfo(edges);
				fprintf(file, "%zu((%s)) -- %zu --> %zu((%s))\n", edge->src->id,
					(String)edge->src->value, edge->weight, edge->dest->id,
					(String)edge->dest->value);
				edges = LinkedList_GetNext(edges);
			}
		}
		vertices = LinkedList_GetNext(vertices);
	}
	fprintf(file, "```\n");
	fclose(file);
}
