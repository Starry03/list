#ifndef EDGE_H
# define EDGE_H

# include "GraphNode.h"
# include "Utils/types.h"

typedef struct s_edge
{
	GraphNode	from;
	GraphNode	to;
	size_t		weight;
}				t_edge;

typedef t_edge	*Edge;

Edge			Edge_Init(GraphNode from, GraphNode to, size_t weight);
void			Edge_Free(Generic edge);

int				Edge_Cmp(Generic a, Generic b);

#endif