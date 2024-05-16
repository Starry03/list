//
// Created by andre on 5/14/2023.
//

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdbool.h>
#include "../../Utils/types.h"
#include <stddef.h>

typedef struct BinaryTreeNode
{
	Generic info;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
} BinaryTreeNode;

typedef BinaryTreeNode *BinaryTree;

#define TREE_NODE_SIZE 24

BinaryTree EmptyTree();

BinaryTree InitTreeNode();

BinaryTree NewTree(Generic info, BinaryTree left, BinaryTree right);

BinaryTree BinaryTree_Left(BinaryTree tree);

BinaryTree BinaryTree_Right(BinaryTree tree);

Generic BinaryTree_Value(BinaryTree tree);

size_t BinaryTree_Depth(BinaryTree tree);

size_t BinaryTree_MaxNodesNumber(size_t depth);

bool BinaryTree_IsInBinarySearchTree(BinaryTree tree, Generic value);

void BinaryTree_SetLeft(BinaryTree tree, BinaryTree left);

void BinaryTree_SetDeepLeft(BinaryTree *tree, BinaryTree left);

bool IsLeaf(BinaryTree tree);

bool HasTwoNodes(BinaryTree tree);

bool BinaryTree_DeleteTreeNode(BinaryTree *tree, Generic value);

#endif // BINARYTREE_H
