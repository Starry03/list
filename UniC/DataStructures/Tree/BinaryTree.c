//
// Created by andre on 5/14/2023.
//

#include "BinaryTree.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool	TreeIsEmpty(BinaryTree tree)
{
	return (tree == NULL);
}

BinaryTree	InitTreeNode(void)
{
	return (BinaryTree)malloc(sizeof(BinaryTreeNode));
}

BinaryTree	BinaryTree_Init(Generic info, BinaryTree left, BinaryTree right)
{
	BinaryTree	tree;

	tree = InitTreeNode();
	if (!tree)
		return (BINARY_TREE_EMPTY);
	tree->info = info;
	tree->key = NULL;
	tree->left = left;
	tree->right = right;
	return (tree);
}

BinaryTree	BinaryTree_Left(BinaryTree tree)
{
	if (tree)
		return (tree->left);
	return (BINARY_TREE_EMPTY);
}

BinaryTree	BinaryTree_Right(BinaryTree tree)
{
	if (tree)
		return (tree->right);
	return (BINARY_TREE_EMPTY);
}

size_t	BinaryTree_Depth(BinaryTree tree)
{
	size_t	left;
	size_t	right;

	if (TreeIsEmpty(tree))
		return (0);
	left = BinaryTree_Depth(BinaryTree_Left(tree));
	right = BinaryTree_Depth(BinaryTree_Right(tree));
	return (1 + ((left > right) ? left : right));
}

inline size_t	BinaryTree_MaxNodesNumber(size_t depth)
{
	return ((size_t)pow(2, depth) - 1);
}

Generic	BinaryTree_Value(BinaryTree tree)
{
	if (tree)
		return (tree->info);
	return (NULL);
}

void	BinaryTree_SetLeft(BinaryTree tree, BinaryTree left)
{
	if (!TreeIsEmpty(tree) && !TreeIsEmpty(left))
		tree->left = left;
}

void	BinaryTree_SetDeepLeft(BinaryTree *tree, BinaryTree left)
{
	if (TreeIsEmpty(*tree))
		*tree = left;
	else
		BinaryTree_SetDeepLeft(&((*tree)->left), left);
}

bool	IsLeaf(BinaryTree tree)
{
	return (TreeIsEmpty(BinaryTree_Left(tree))
		&& TreeIsEmpty(BinaryTree_Right(tree)));
}

bool	HasTwoNodes(BinaryTree tree)
{
	return (!TreeIsEmpty(BinaryTree_Left(tree))
		&& !TreeIsEmpty(BinaryTree_Right(tree)));
}

bool	BinaryTree_DeleteTreeNode(BinaryTree *tree, Generic value)
{
	BinaryTree	right;
	BinaryTree	temp;

	if (TreeIsEmpty(*tree))
		return (false);
	if (BinaryTree_Value(*tree) == value)
	{
		right = BinaryTree_Right(*tree);
		if (!TreeIsEmpty(right))
			BinaryTree_SetDeepLeft(tree, right);
		temp = *tree;
		*tree = BinaryTree_Left(*tree);
		free(temp);
		return (true);
	}
	else
		return (BinaryTree_DeleteTreeNode(&((*tree)->left), value)
			|| BinaryTree_DeleteTreeNode(&((*tree)->right), value));
}

void	BinaryTree_Free(BinaryTree tree)
{
	if (!tree)
		return ;
	
}
