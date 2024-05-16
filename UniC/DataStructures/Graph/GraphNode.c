#include "../../DataStructures/LinkedList/LinkedList.h"
#include "../../Utils/types.h"
#include "Edge.h"
#include "GraphNode.h"
#include <stdbool.h>
#include <stdlib.h>

#define ID_ERROR 0

typedef struct s_graphnode
{
	bool		visited;
	size_t		id;
	LinkedList	edges;
	Generic		info;
	void		(*dealloc)(Generic);
}				t_graphnode;

GraphNode	GraphNode_Init(size_t id, Generic info, void (*dealloc)(Generic))
{
	GraphNode	node;

	node = (GraphNode)malloc(sizeof(t_graphnode));
	if (!node)
		return (NULL);
	node->id = id;
	node->info = info;
	node->visited = false;
	node->dealloc = dealloc;
	return (node);
}

/**
 * @brief Free the node and its edges
 */
void	GraphNode_Free(Generic node)
{
	GraphNode	g_node;

	if (!node)
		return ;
	g_node = (GraphNode)node;
	if (g_node->dealloc)
		g_node->dealloc(g_node->info);
	LinkedList_Dealloc(g_node->edges, Edge_Free);
	free(node);
}

Generic	GraphNode_GetInfo(GraphNode node)
{
	if (!node)
		return (NULL);
	return (node->info);
}
size_t	GraphNode_GetId(GraphNode node)
{
	if (!node)
		return (ID_ERROR);
	return (node->id);
}

void	GraphNode_AddEdge(GraphNode from, GraphNode to, size_t weight)
{
	Edge	edge;

	if (!from || !to)
		return ;
	edge = Edge_Init(from, to, weight);
	if (!edge)
		return ;
	LinkedList_Push(&from->edges, edge);
}

void	GraphNode_RemoveEdge(GraphNode node, Edge edge)
{
	if (!node || !edge)
		return ;
	
	LinkedList_RemoveByValue(&node->edges, edge, Edge_Free, Edge_Cmp);
}

/**

	* @brief Add an edge from 'from' to 'to' (weigth) and from 'to' to 'from' (weight2)
 */
void	GraphNode_AddDoubleEdge(GraphNode from, GraphNode to, size_t weight,
		size_t weight2)
{
	GraphNode_AddEdge(from, to, weight);
	GraphNode_AddEdge(to, from, weight2);
}
void	GraphNode_RemoveDoubleEdge(GraphNode from, GraphNode to)
{
	GraphNode_RemoveEdge(from, to);
	GraphNode_RemoveEdge(to, from);
}

bool	GraphNode_Cmp(GraphNode a, GraphNode b)
{
	if (!a || !b)
		return (false);
	return (a->id == b->id);
}
