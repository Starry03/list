#ifndef GRAPH_H
# define GRAPH_H

# include "../LinkedList/LinkedList.h"
# include <stdbool.h>
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
 * @brief A vertex is a node in a graph
 * @note id is used to identify the vertex internally
 * @note status is used for graph traversal
 * @note distance is used for shortest path algorithms
 * @note discovery_time is used for DFS
 * @note finish_time is used for DFS
 * @note predecessor is used to retrieve a path
 */
typedef struct s_vertex
{
	LinkedList		edges;
	Generic			value;
	uint64_t		id;
	uint64_t		distance;
	uint64_t		discovery_time;
	uint64_t		finish_time;
	struct s_vertex	*predecessor;
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
	uint64_t		weight;
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

Edge				Edge_Init(Vertex src, Vertex dest, uint64_t weight);
void				Edge_Free(Generic edge);

/* EXPLORING */
Vertex				Graph_BFS(Graph graph, Vertex src, Generic target);
Vertex				Graph_DFS(Graph graph);

/* PATH FINDING */
LinkedList			Dijkstra(Graph graph, Vertex src, Vertex dest);

/* UTILS */
void				Vertex_InitSingleSource(Graph graph, Vertex src);
bool				Edge_Relax(Vertex src, Vertex dest, uint64_t weight);
LinkedList			BuildPath(Vertex dest);
int					Vertex_CmpDistance(Generic a, Generic b);
int					Vertex_CmpId(Generic a, Generic b);
void				DijkstraHeapEntry_Free(Generic entry);
size_t				Vertex_Hash(Generic vertex, size_t capacity);

/* UI UTILS */
# define MERMAID_HORIZONAL "LR"
# define MERMAID_VERTICAL "TD"
void				Graph_GenerateMermaid(Graph graph, String filename,
						String direction);

#endif