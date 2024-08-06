//
// Created by andre on 8/8/2023.
//

#ifndef NODES_H
#define NODES_H

#include "../../Utils/types.h"

/**
 * @brief Node structure
 * @param info: the information of the node
 * @param next: the next node
 */
typedef struct Node_ {
	Generic info;
	struct Node_ *next;
} Node_;

typedef Node_ *Node;

Node Node_Init(Generic info);

/**
 * @brief Double Node structure
 * @param info: the information of the node
 * @param next: the next node
 * @param prev: the previous node
 */
typedef struct DoubleNode_ {
	Generic info;
	struct DoubleNode_ *next;
	struct DoubleNode_ *prev;
} DoubleNode_;

typedef DoubleNode_ *DoubleNode;

DoubleNode DoubleNode_Init(Generic info);

#endif //NODES_H
