# include "unic/binarytree.h"

typedef struct s_bst
{
	t_comparator		cmp;
	t_binary_treenode	*root;
}						t_bst_;

typedef t_bst_			*t_bst;

t_bst					nst_init(t_generic key, t_generic info,
							t_comparator cmp);
t_generic				bst_insert(t_generic key, t_generic info);
void					bst_remove(t_generic key);
void					bst_free(t_bst node);
