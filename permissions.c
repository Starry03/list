#include "permissions.h"
#include <stdlib.h>

t_permissions	*permissions_init(void)
{
	t_permissions	*permissions;

	permissions = (t_permissions *)malloc(sizeof(t_permissions));
	if (!permissions)
		return (NULL);
	permissions->owner = (String)calloc(4, sizeof(char));
	permissions->group = (String)calloc(4, sizeof(char));
	permissions->others = (String)calloc(4, sizeof(char));
	return (permissions);
}
void	permissions_free(t_permissions *permissions)
{
	free(permissions->owner);
	free(permissions->group);
	free(permissions->others);
	free(permissions);
}
