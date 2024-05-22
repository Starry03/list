#ifndef PERMISSIONS_H
# define PERMISSIONS_H

# include "UniC/Utils/types.h"
# define PERMISSIONS_LENGTH 9

typedef struct s_permissions
{
	String		owner;
	String		group;
	String		others;
}				t_permissions;

t_permissions	*permissions_init(void);
void			permissions_free(t_permissions *permissions);

#endif
