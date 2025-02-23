#ifndef THEME_H
# define THEME_H

# ifndef ICON_PATH
#  define ICON_PATH "./storage/icons.txt"
# endif

# include "unic/dictionary.h"

typedef struct s_theme
{
	t_string		name;
	t_dict			icons;
}					t_theme_;

typedef t_theme_	*t_theme;

t_theme				theme_init(t_string name, t_dict icons);
t_theme				theme_parser(const char *config_path);
void				theme_free(t_theme theme);

#endif
