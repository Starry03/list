#ifndef THEME_H
# define THEME_H

# include "UniC/DataStructures/Dictionary/Dictionary.h"

typedef struct s_theme
{
	String		name;
	t_dict		icons;
}				t_theme;

typedef t_theme	*Theme;

Theme			Theme_Init(char *name, t_dict icons);
void			Theme_Free(Theme theme);

#endif
