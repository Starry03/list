//
// Created by andre on 8/8/2023.
//

#include "unic/nodes.h"
#include <stdlib.h>

static t_node	empty_node(void)
{
	return ((t_node)NULL);
}

static t_node	node_allocate(void)
{
	return (t_node)malloc(sizeof(t_node_));
}

t_node	node_init(t_generic info)
{
	t_node	node;

	node = node_allocate();
	if (!node)
		return (empty_node());
	node->info = info;
	node->next = empty_node();
	return (node);
}

t_doublenode	doublenode_init(t_generic info)
{
	t_doublenode	node;

	node = (t_doublenode)malloc(sizeof(t_doublenode_));
	if (!node)
		return ((t_doublenode)NULL);
	node->info = info;
	node->next = (t_doublenode)NULL;
	node->prev = (t_doublenode)NULL;
	return (node);
}
