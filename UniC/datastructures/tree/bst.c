#include "unic/bst.h"
#include <stdlib.h>

t_bst	nst_init(t_generic key, t_generic info, t_comparator cmp)
{
	t_bst	bst;

	(void)key;
	bst = (t_bst)malloc(sizeof(t_bst_));
	if (!bst)
		return (NULL);
	bst->root = binarytree_init(info, BINARY_TREE_EMPTY, BINARY_TREE_EMPTY);
	bst->cmp = cmp;
	return (bst);
}
t_generic	bst_insert(t_generic key, t_generic info);
void		bst_remove(t_generic key);
void		bst_free(t_bst node);