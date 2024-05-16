//
// Created by andre on 8/8/2023.
//

#include "Nodes.h"

#include <stdlib.h>

static Node EmptyNode()
{
	return (Node)NULL;
}

static Node Node_Allocate()
{
	return (Node)malloc(sizeof(Node_));
}

Node Node_Init(Generic info)
{
	Node node = Node_Allocate();
	if (!node)
		return EmptyNode();
	node->info = info;
	node->next = EmptyNode();
	return node;
}
