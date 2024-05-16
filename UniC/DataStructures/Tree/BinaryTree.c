//
// Created by andre on 5/14/2023.
//

#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

inline BinaryTree EmptyTree() { return (BinaryTree)NULL; }

bool TreeIsEmpty(BinaryTree tree)
{
	return tree == NULL;
}

BinaryTree InitTreeNode()
{
	return (BinaryTree)malloc(TREE_NODE_SIZE);
}

BinaryTree NewTree(Generic info, BinaryTree left, BinaryTree right)
{
	BinaryTree tree = InitTreeNode();
	if (!tree)
		return EmptyTree();
	tree->info = info;
	tree->left = left;
	tree->right = right;
	return tree;
}

BinaryTree BinaryTree_Left(BinaryTree tree)
{
	if (tree)
		return tree->left;
	return EmptyTree();
}

BinaryTree BinaryTree_Right(BinaryTree tree)
{
	if (tree)
		return tree->right;
	return EmptyTree();
}

size_t BinaryTree_Depth(BinaryTree tree)
{
	if (TreeIsEmpty(tree))
		return 0;
	size_t left = BinaryTree_Depth(BinaryTree_Left(tree));
	size_t right = BinaryTree_Depth(BinaryTree_Right(tree));
	return 1 + ((left > right) ? left : right);
}

size_t BinaryTree_MaxNodesNumber(size_t depth)
{
	return (size_t)pow(2, depth) - 1;
}

Generic BinaryTree_Value(BinaryTree tree)
{
	if (tree)
		return tree->info;
	return (NULL);
}

bool BinaryTree_IsInBinarySearchTree(BinaryTree tree, Generic value)
{
	if (TreeIsEmpty(tree))
		return false;
	if (value > BinaryTree_Value(tree))
	{
		return BinaryTree_IsInBinarySearchTree(BinaryTree_Right(tree), value);
	}
	else if (value < BinaryTree_Value(tree))
	{
		return BinaryTree_IsInBinarySearchTree(BinaryTree_Left(tree), value);
	}
	return true;
}

void BinaryTree_SetLeft(BinaryTree tree, BinaryTree left)
{
	if (!TreeIsEmpty(tree) && !TreeIsEmpty(left))
		tree->left = left;
}

void BinaryTree_SetDeepLeft(BinaryTree *tree, BinaryTree left)
{
	if (TreeIsEmpty(*tree))
		*tree = left;
	else
		BinaryTree_SetDeepLeft(&((*tree)->left), left);
}

bool IsLeaf(BinaryTree tree)
{
	return TreeIsEmpty(BinaryTree_Left(tree)) && TreeIsEmpty(BinaryTree_Right(tree));
}

bool HasTwoNodes(BinaryTree tree)
{
	return !TreeIsEmpty(BinaryTree_Left(tree)) && !TreeIsEmpty(BinaryTree_Right(tree));
}

bool BinaryTree_DeleteTreeNode(BinaryTree *tree, Generic value)
{
	if (TreeIsEmpty(*tree))
		return false;

	if (BinaryTree_Value(*tree) == value)
	{
		BinaryTree right = BinaryTree_Right(*tree);
		if (!TreeIsEmpty(right))
			BinaryTree_SetDeepLeft(tree, right);
		BinaryTree temp = *tree;
		*tree = BinaryTree_Left(*tree);
		free(temp);
		return true;
	}
	else
		return BinaryTree_DeleteTreeNode(&((*tree)->left), value) ||
			   BinaryTree_DeleteTreeNode(&((*tree)->right), value);
}
