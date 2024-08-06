#ifndef FLAG_H
# define FLAG_H

# include <stdbool.h>
# include <stddef.h>

# define ROOT_LEVEL 0

enum		e_flag
{
	LOG_DIM,
	RECURSIVE,
	SHOW_HIDDEN,
	VERSION,
	PERMISSIONS,
	HELP,
};

char		*get_flag(enum e_flag flag);

typedef struct s_flags
{
	char	**ignore_patterns;
	char	*root_path;
	int		col_width;
	bool	log_dim;
	bool	recursive;
	bool	show_hidden;
	bool	show_version;
	bool	show_permissions;
	bool	help;
}			t_flags;

void		init_default_flags(t_flags *flags);
void		parse_flags(t_flags *flags, size_t argc, char **argv);
bool		is_valid_folder(char *name, t_flags options);
void		flags_free(t_flags *flags);

#endif // !FLAG_H
