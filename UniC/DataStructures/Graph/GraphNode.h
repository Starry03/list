#ifndef GRAPHNODE_H
# define GRAPHNODE_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_graphnode	t_graphnode;
typedef t_graphnode			*GraphNode;

GraphNode					GraphNode_Init(size_t id, Generic info,
								void (*dealloc)(Generic));
void						GraphNode_Free(Generic node);

Generic						GraphNode_GetInfo(GraphNode node);
size_t						GraphNode_GetId(GraphNode node);

void						GraphNode_AddEdge(GraphNode from, GraphNode to,
								size_t weight);
void						GraphNode_RemoveEdge(GraphNode from, GraphNode to);

void						GraphNode_AddDoubleEdge(GraphNode from, GraphNode to,
								size_t weight, size_t weight2);
void						GraphNode_RemoveDoubleEdge(GraphNode from,
								GraphNode to);

bool						GraphNode_Cmp(GraphNode a, GraphNode b);

#endif