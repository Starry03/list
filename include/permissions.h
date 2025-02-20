#ifndef PERMISSIONS_H
# define PERMISSIONS_H

# include "unic/types.h"
# define PERMISSIONS_LENGTH 9

typedef struct s_permissions
{
	t_string	owner;
	t_string	group;
	t_string	others;
}				t_permissions;

t_permissions	*permissions_init(void);
void			permissions_free(t_permissions *permissions);

#endif
