//
// Created by andre on 8/8/2023.
//

#ifndef NODES_H
#define NODES_H

#include "../../Utils/types.h"

typedef struct Node_ {
	Generic info;
	struct Node_ *next;
} Node_;

typedef Node_ *Node;

Node Node_Init(Generic info);

#endif //NODES_H
