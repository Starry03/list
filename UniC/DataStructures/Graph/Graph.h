#ifndef GRAPH_H
# define GRAPH_H

# include "../LinkedList/LinkedList.h"
# include <stdint.h>

/**
 * @brief A graph is a collection of vertices and edges.
 * @note vertices are of 1 type => 1 dealloc function
 */
typedef struct s_graph
{
	LinkedList		adjacency_list;
	int				(*cmp)(Generic, Generic);
	void			(*dealloc_vertex)(Generic);
}					t_graph;

typedef t_graph		*Graph;

typedef enum e_vertex_status
{
	VERTEX_UNVISITED,
	VERTEX_VISITING,
	VERTEX_VISITED,
}					t_vertex_status;

/**
 * @brief A vertex is a node in a graph.
 * @note id is used to identify the vertex internally.
 * @note status is used for graph traversal.
 * @note time is used for graph traversal and edge classification.
 * @note distance is used for shortest path algorithms.
 */
typedef struct s_vertex
{
	LinkedList		edges;
	Generic			value;
	uint32_t		id;
	uint32_t		distance;
	uint32_t		time;
	t_vertex_status	status;
}					t_vertex;

typedef t_vertex	*Vertex;

Vertex				Vertex_Init(Generic value);
void				Vertex_Free(Graph graph, Vertex vertex);

/**
 * @brief An edge is a connection between 2 vertices.
 */
typedef struct s_edge
{
	Vertex			src;
	Vertex			dest;
	uint32_t		weight;
}					t_edge;

typedef t_edge		*Edge;

Graph				Graph_Init(void (*dealloc_vertex)(Generic),
						int (*cmp)(Generic, Generic));
void				Graph_Free(Graph graph);

void				Graph_AddVertex(Graph graph, Vertex vertex);
void				Graph_AddEdge(Vertex vertex, Edge edge);
void				Graph_AddDoubleEdge(Vertex vertex, Edge edge);

void				Graph_RemoveVertex(Graph graph, Vertex vertex);
void				Graph_RemoveEdge(Vertex vertex, Edge edge);
void				Graph_RemoveDoubleEdge(Vertex vertex, Edge edge);

Edge				Edge_Init(Vertex src, Vertex dest, uint32_t weight);
void				Edge_Free(Generic edge);

#endif