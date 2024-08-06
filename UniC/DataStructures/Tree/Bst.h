#include "BinaryTree.h"

typedef struct Bst
{
	Comparator		cmp;
	BinaryTreeNode	*root;
}					Bst;

typedef Bst			*BST;

BST					Bst_Init(Generic key, Generic info, Comparator cmp);
Generic				Bst_Insert(Generic key, Generic info);
void				Bst_Remove(Generic key);
void				Bst_Free(BST node);
