//
// Created by andre on 5/14/2023.
//

#ifndef BINARYTREE_H
# define BINARYTREE_H

# include "../../Utils/types.h"
# include <stdbool.h>
# include <stddef.h>

typedef struct BinaryTreeNode
{
	Generic					key;
	Generic					info;
	struct BinaryTreeNode	*left;
	struct BinaryTreeNode	*right;
}							BinaryTreeNode;

typedef BinaryTreeNode		*BinaryTree;
# define BINARY_TREE_EMPTY (BinaryTree) NULL

BinaryTree					InitTreeNode(void);

BinaryTree					BinaryTree_Init(Generic info, BinaryTree left,
								BinaryTree right);

BinaryTree					BinaryTree_Left(BinaryTree tree);

BinaryTree					BinaryTree_Right(BinaryTree tree);

Generic						BinaryTree_Value(BinaryTree tree);

size_t						BinaryTree_Depth(BinaryTree tree);

size_t						BinaryTree_MaxNodesNumber(size_t depth);

void						BinaryTree_SetLeft(BinaryTree tree,
								BinaryTree left);

void						BinaryTree_SetDeepLeft(BinaryTree *tree,
								BinaryTree left);

bool						IsLeaf(BinaryTree tree);

bool						HasTwoNodes(BinaryTree tree);

bool						BinaryTree_DeleteTreeNode(BinaryTree *tree,
								Generic value);

void						BinaryTree_Free(BinaryTree tree);

#endif // BINARYTREE_H
