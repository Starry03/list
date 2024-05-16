#ifndef GRAPH_H
# define GRAPH_H

# include "../../Utils/types.h"
# include "GraphNode.h"
# include <stddef.h>

typedef struct s_graph	t_graph;

typedef t_graph			*Graph;

Graph					Graph_Init(void);

void					Graph_AddVertex(Graph graph, Generic value,
							void (*dealloc)(Generic));
void					Graph_Free(Graph graph);

void					Graph_AddEdge(GraphNode from, GraphNode to,
							size_t weight);

void					Graph_RemoveEdge(GraphNode from, Edge edge);

void					Graph_AddDoubleEdge(GraphNode from, GraphNode to,
							size_t weight, size_t weight2);

void					Graph_RemoveDoubleEdge(GraphNode from,
							GraphNode to);

#endif // !GRAPH_H
