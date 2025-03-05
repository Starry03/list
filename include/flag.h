#ifndef FLAG_H
# define FLAG_H

# include <stdbool.h>
# include <stddef.h>

# define ROOT_LEVEL 0

enum			e_sort
{
	SORT_NONE,
	SORT_NAME,
	SORT_DIRFIRST, // default
};

typedef struct s_flags
{
	char		**ignore_patterns;
	char		*root_path;
	int			col_width;
	enum e_sort	sort_type;
	bool		log_dim;
	bool		recursive;
	bool		show_hidden;
	bool		show_version;
	bool		show_permissions;
	bool		help;
}				t_flags;

# define FLAG_LIST "dalhVR"

void			init_default_flags(t_flags *flags);
void			get_flags(int argc, char **argv, t_flags *flags);
bool			is_valid_folder(char *name, t_flags options);
void			flags_free(t_flags *flags);

#endif // !FLAG_H
