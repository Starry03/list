#include "theme.h"
#include <stdlib.h>

t_theme	theme_init(t_string name, t_dict icons)
{
	t_theme theme;

	theme = (t_theme)malloc(sizeof(t_theme_));
	theme->name = name;
	theme->icons = icons;
	return (theme);
}
void	theme_free(t_theme theme)
{
	dict_free(theme->icons);
	free(theme);
}