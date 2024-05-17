#include "theme.h"
#include <stdlib.h>

Theme	Theme_Init(char *name, t_dict icons)
{
	Theme theme;

	theme = (Theme)malloc(sizeof(t_theme));
	theme->name = name;
	theme->icons = icons;
	return (theme);
}
void	Theme_Free(Theme theme)
{
	Dict_Free(theme->icons);
	free(theme);
}