#ifndef GRAPHNODE_H
# define GRAPHNODE_H

# include <stdbool.h>
# include <stddef.h>
# include "Utils/types.h"

typedef struct s_graphnode	t_graphnode;
typedef t_graphnode			*GraphNode;

typedef struct s_edge
{
	GraphNode				from;
	GraphNode				to;
	size_t					weight;
}							t_edge;

typedef t_edge				*Edge;

GraphNode					GraphNode_Init(size_t id, Generic info,
								void (*dealloc)(Generic));
void						GraphNode_Free(Generic node);

Generic						GraphNode_GetInfo(GraphNode node);
size_t						GraphNode_GetId(GraphNode node);

void						GraphNode_AddEdge(GraphNode from, GraphNode to,
								size_t weight);
void						GraphNode_RemoveEdge(GraphNode node, Edge edge);

void						GraphNode_AddDoubleEdge(GraphNode from,
								GraphNode to, size_t weight, size_t weight2);
void						GraphNode_RemoveDoubleEdge(GraphNode from,
								GraphNode to);

bool						GraphNode_Cmp(GraphNode a, GraphNode b);

#endif