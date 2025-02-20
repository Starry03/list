//
// Created by andre on 5/14/2023.
//

#ifndef BINARYTREE_H
# define BINARYTREE_H

# include "unic/types.h"
# include <stdbool.h>
# include <stddef.h>

typedef struct s_binary_treenode
{
	t_generic					info;
	struct s_binary_treenode	*left;
	struct s_binary_treenode	*right;
}								t_binary_treenode;

typedef t_binary_treenode		*t_binarytree;
# define BINARY_TREE_EMPTY (t_binarytree)0

t_binarytree					treenode_init(void);

t_binarytree					binarytree_init(t_generic info,
									t_binarytree left, t_binarytree right);

t_binarytree					binarytree_left(t_binarytree tree);

t_binarytree					binarytree_right(t_binarytree tree);

t_generic						binarytree_value(t_binarytree tree);

size_t							binarytree_depth(t_binarytree tree);

size_t							binarytree_max_nodesnumber(size_t depth);

void							binarytree_setleft(t_binarytree tree,
									t_binarytree left);

void							binarytree_set_deepleft(t_binarytree *tree,
									t_binarytree left);

bool							binarytree_isleaf(t_binarytree tree);

bool							binarytree_has_twonodes(t_binarytree tree);

bool							binarytree_deletenode(t_binarytree *tree,
									t_generic value);

void							binarytree_free(t_binarytree tree,
									t_deallocator dealloc);

#endif // BINARYTREE_H
