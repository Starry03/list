//
// Created by andre on 5/14/2023.
//

#include "unic/binarytree.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool	tree_is_empty(t_binarytree tree)
{
	return (tree == NULL);
}

t_binarytree	treenode_init(void)
{
	return (t_binarytree)malloc(sizeof(t_binary_treenode));
}

t_binarytree	binarytree_init(t_generic info, t_binarytree left,
		t_binarytree right)
{
	t_binarytree	tree;

	tree = treenode_init();
	if (!tree)
		return (BINARY_TREE_EMPTY);
	tree->info = info;
	tree->left = left;
	tree->right = right;
	return (tree);
}

t_binarytree	binarytree_left(t_binarytree tree)
{
	if (tree)
		return (tree->left);
	return (BINARY_TREE_EMPTY);
}

t_binarytree	binarytree_right(t_binarytree tree)
{
	if (tree)
		return (tree->right);
	return (BINARY_TREE_EMPTY);
}

size_t	binarytree_depth(t_binarytree tree)
{
	size_t	left;
	size_t	right;

	if (tree_is_empty(tree))
		return (0);
	left = binarytree_depth(binarytree_left(tree));
	right = binarytree_depth(binarytree_right(tree));
	return (1 + ((left > right) ? left : right));
}

inline size_t	binarytree_max_nodesnumber(size_t depth)
{
	return ((size_t)pow(2, depth) - 1);
}

t_generic	binarytree_value(t_binarytree tree)
{
	if (tree)
		return (tree->info);
	return (NULL);
}

void	binarytree_setleft(t_binarytree tree, t_binarytree left)
{
	if (!tree_is_empty(tree) && !tree_is_empty(left))
		tree->left = left;
}

void	binarytree_set_deepleft(t_binarytree *tree, t_binarytree left)
{
	if (tree_is_empty(*tree))
		*tree = left;
	else
		binarytree_set_deepleft(&((*tree)->left), left);
}

bool	binarytree_isleaf(t_binarytree tree)
{
	return (tree_is_empty(binarytree_left(tree))
		&& tree_is_empty(binarytree_right(tree)));
}

bool	binarytree_has_twonodes(t_binarytree tree)
{
	return (!tree_is_empty(binarytree_left(tree))
		&& !tree_is_empty(binarytree_right(tree)));
}

bool	binarytree_deletenode(t_binarytree *tree, t_generic value)
{
	t_binarytree	right;
	t_binarytree	temp;

	if (tree_is_empty(*tree))
		return (false);
	if (binarytree_value(*tree) == value)
	{
		right = binarytree_right(*tree);
		if (!tree_is_empty(right))
			binarytree_set_deepleft(tree, right);
		temp = *tree;
		*tree = binarytree_left(*tree);
		free(temp);
		return (true);
	}
	else
		return (binarytree_deletenode(&((*tree)->left), value)
			|| binarytree_deletenode(&((*tree)->right), value));
}

/**
 * @note: check leak if this function fails, you put different types in
 */
void	binarytree_free(t_binarytree tree, t_deallocator dealloc)
{
	if (tree_is_empty(tree))
		return ;
	binarytree_free(binarytree_left(tree), dealloc);
	binarytree_free(binarytree_right(tree), dealloc);
	dealloc(binarytree_value(tree));
	free(tree);
}
