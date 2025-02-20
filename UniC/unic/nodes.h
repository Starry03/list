//
// Created by andre on 8/8/2023.
//

#ifndef NODES_H
# define NODES_H

# include "unic/types.h"

/**
 * @brief Node structure
 * @param info: the information of the node
 * @param next: the next node
 */
typedef struct s_node_
{
	t_generic				info;
	struct s_node_			*next;
}							t_node_;

typedef t_node_				*t_node;

t_node						node_init(t_generic info);

/**
 * @brief Double Node structure
 * @param info: the information of the node
 * @param next: the next node
 * @param prev: the previous node
 */
typedef struct s_doublenode_
{
	t_generic				info;
	struct s_doublenode_	*next;
	struct s_doublenode_	*prev;
}							t_doublenode_;

typedef t_doublenode_		*t_doublenode;

t_doublenode				doublenode_init(t_generic info);

#endif // NODES_H
