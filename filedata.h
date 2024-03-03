#ifndef FILEDATA_H
# define FILEDATA_H

#include "flag.h"
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

t_filedata	*filedata_init(char *name, t_type type, FILE *file);
void		filedata_free(t_filedata *filedata);

void		print_filedata(t_filedata *filedata, t_flags options,
				size_t name_len);

#endif