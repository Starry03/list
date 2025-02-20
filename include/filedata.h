#ifndef FILEDATA_H
# define FILEDATA_H

# include "flag.h"
# include "permissions.h"
# include "unic/dictionary.h"
# include <dirent.h>
# include <stddef.h>
# include <stdio.h>

typedef enum e_type
{
	T_FILE = 8,
	T_DIR = 4
}					t_type;

typedef struct s_filedata
{
	char			*name;
	size_t			size;
	t_type			type;
	t_permissions	*permissions;
}					t_filedata;

t_filedata			*filedata_init(char *name, t_type type, size_t size,
						t_permissions *permissions);
bool				is_valid_type(t_type type);
void				print_filedata(t_filedata *filedata, t_flags options,
						t_dict icons);
t_filedata			*filedata_get_from_file(struct dirent *d, char *path,
						t_flags flags);

size_t				get_size(FILE *file);
t_permissions		*get_permissions(t_string path);
int					filedata_cmp(const t_generic a, const t_generic b);
int					filedata_cmp_dirfirst(const t_generic a, const t_generic b);

void				filedata_free(t_generic filedata);

#endif