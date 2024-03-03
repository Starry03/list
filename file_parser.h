#ifndef FILE_PARSER_H
# define FILE_PARSER_H

# include <stdbool.h>
# include <stdio.h>

# ifdef _WIN32
#  include <corecrt.h>
# endif

# ifndef _WIN32
typedef unsigned long	size_t;
# endif

# define STD_COLOR "\x1B[0m"
# define GREEN "\x1B[32m"
# define BLUE "\x1B[34m"
# define ROOT_LEVEL 0

typedef enum e_type
{
	T_FILE = 8,
	T_DIR = 4
}						t_type;

typedef struct s_filedata
{
	char				*name;
	size_t				size;
	t_type				type;
}						t_filedata;

typedef struct s_print_options
{
	bool				log_dim;
	bool				recursive;
	size_t				col_width;
	char				**ignore_patterns;
}						t_print_options;

t_filedata				*filedata_init(char *name, t_type type, FILE *file);
void					print_folder(char *folder_name, size_t folder_level,
							t_print_options options);
void					print_filedata(t_filedata *filedata,
							t_print_options options, size_t name_len);
void					filedata_free(t_filedata *filedata);

#endif // !FILE_PARSER_H
