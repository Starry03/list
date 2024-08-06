#include "Bst.h"
#include <stdlib.h>

BST	Bst_Init(Generic key, Generic info, Comparator cmp)
{
	BST	bst;

	(void)key;
	bst = (BST)malloc(sizeof(Bst));
	if (!bst)
		return (NULL);
	bst->root = BinaryTree_Init(info, BINARY_TREE_EMPTY, BINARY_TREE_EMPTY);
	bst->cmp = cmp;
	return (bst);
}
Generic	Bst_Insert(Generic key, Generic info);
void	Bst_Remove(Generic key);
void	Bst_Free(BST node);