#include "builders.h"
#include <stdlib.h>
#include <string.h>

char	*build_path(char *path, char *folder_name)
{
	char	*p;

	p = (char *) malloc(sizeof(char) * (strlen(path) + 1 + strlen(folder_name) + 1));
	if (!p)
		return (NULL);
	strcpy(p, path);
	strcat(p, "/");
	strcat(p, folder_name);
	return (p);
}
