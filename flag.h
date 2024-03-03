#ifndef FLAG_H
# define FLAG_H

# include <stdbool.h>
# include <stddef.h>

# define ROOT_LEVEL 0

enum		e_flag
{
	LOG_DIM,
	RECURSIVE,
	SHOW_HIDDEN
};

char		*get_flag(enum e_flag flag);

typedef struct s_flags
{
	bool	log_dim;
	bool	recursive;
	bool	show_hidden;
	size_t	col_width;
	char	*root_path;
	char	**ignore_patterns;
}			t_flags;

void		init_default_flags(t_flags *flags);
void		parse_flags(t_flags *flags, size_t argc, char **argv);

#endif // !FLAG_H
