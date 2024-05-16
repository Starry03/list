#ifndef FILEDATA_H
# define FILEDATA_H

#include <dirent.h>
# include "flag.h"
# include <stddef.h>
# include <stdio.h>

typedef enum e_type
{
	T_FILE = 8,
	T_DIR = 4
}			t_type;

typedef struct s_filedata
{
	char	*name;
	size_t	size;
	t_type	type;
}			t_filedata;

t_filedata	*filedata_init(char *name, t_type type, size_t size);
bool		is_valid_type(t_type type);
void		print_filedata(t_filedata *filedata, t_flags options,
				size_t name_len);
t_filedata	*filedata_get_from_file(struct dirent *d, char *path,
		bool calc_size);

# define filedata_free(filedata) free(filedata);

#endif