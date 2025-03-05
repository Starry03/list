#include "list.h"
#include "theme.h"
#include <stdio.h>
#include <stdlib.h>

static void	_main(t_theme theme, t_flags flags)
{
	theme = theme_parser(ICON_PATH);
	if (!theme)
		return ;
	print_folder(flags.root_path, ROOT_LEVEL, flags, theme->icons);
	if (theme)
		theme_free(theme);
}

int	main(int argc, char **argv)
{
	t_flags	flags;
	t_theme	theme;

	theme = NULL;
	init_default_flags(&flags);
	get_flags(argc, argv, &flags);
	if (flags.help)
	{
		PRINT_VERSION;
		printf(LIST_HELP_STRING);
	}
	else if (!flags.show_version)
		_main(theme, flags);
	else
	{
		PRINT_VERSION;
		print_change_log();
	}
	flags_free(&flags);
	return (EXIT_SUCCESS);
}
