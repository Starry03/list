#ifndef GRAPH_H
# define GRAPH_H

# include "unic/linkedlist.h"
# include <stdbool.h>
# include <stdint.h>

/**
 * @brief A graph is a collection of vertices and edges.
 * @note vertices are of 1 type => 1 dealloc function
 */
typedef struct s_graph
{
	t_linkedlist	adjacency_list;
	int				(*cmp)(t_generic, t_generic);
	void			(*dealloc_vertex)(t_generic);
}					t_graph_;

typedef t_graph_	*t_graph;

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
	t_linkedlist	edges;
	t_generic		value;
	uint64_t		id;
	uint64_t		distance;
	uint64_t		discovery_time;
	uint64_t		finish_time;
	struct s_vertex	*predecessor;
	t_vertex_status	status;
}					t_vertex_;

typedef t_vertex_	*t_vertex;

t_vertex			vertex_init(t_generic value);
void				vertex_free(t_graph graph, t_vertex vertex);

/**
 * @brief An edge is a connection between 2 vertices.
 */
typedef struct s_edge
{
	t_vertex		src;
	t_vertex		dest;
	uint64_t		weight;
}					t_edge_;

typedef t_edge_		*t_edge;

t_graph				graph_init(void (*dealloc_vertex)(t_generic),
						int (*cmp)(t_generic, t_generic));
void				graph_free(t_graph graph);

void				graph_add_vertex(t_graph graph, t_vertex vertex);
void				graph_add_edge(t_vertex vertex, t_edge edge);
void				graph_add_double_edge(t_vertex vertex, t_edge edge);

void				graph_remove_vertex(t_graph graph, t_vertex vertex);
void				graph_remove_edge(t_vertex vertex, t_edge edge);
void				graph_remove_double_edge(t_vertex vertex, t_edge edge);

t_edge				edge_init(t_vertex src, t_vertex dest, uint64_t weight);
void				edge_free(t_generic edge);

/* EXPLORING */
t_vertex			graph_bfs(t_graph graph, t_vertex src, t_generic target);
t_vertex			graph_dfs(t_graph graph);

/* PATH FINDING */
t_linkedlist		dijkstra(t_graph graph, t_vertex src, t_vertex dest);

/* UTILS */
void				vertex_init_single_source(t_graph graph, t_vertex src);
bool				edge_relax(t_vertex src, t_vertex dest, uint64_t weight);
t_linkedlist		build_path(t_vertex dest);
int					vertex_cmp_distance(t_generic a, t_generic b);
int					vertex_cmp_id(t_generic a, t_generic b);
void				dijkstra_heapentry_free(t_generic entry);
size_t				vertex_hash(t_generic vertex, size_t capacity);

/* UI UTILS */
# define MERMAID_HORIZONAL "LR"
# define MERMAID_VERTICAL "TD"
void				graph_generate_mermaid(t_graph graph, t_string filename,
						t_string direction);

#endif