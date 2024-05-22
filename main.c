#include "list.h"
#include "theme.h"
#include <stdio.h>

#define VERSION "Version 2.1"
#define CHANGE_LOG "Added permissions"
#define PRINT_VERSION printf("%s\n%s\n", VERSION, CHANGE_LOG)

static void	_main(Theme theme, t_flags flags)
{
	init(&theme);
	if (!theme)
		return ;
	print_folder(flags.root_path, ROOT_LEVEL, flags, theme->icons);
	if (theme)
		Theme_Free(theme);
}

int	main(int argc, char **argv)
{
	t_flags	flags;
	Theme	theme;

	theme = NULL;
	init_default_flags(&flags);
	parse_flags(&flags, argc, argv);
	if (!flags.show_version)
		_main(theme, flags);
	else
		PRINT_VERSION;
	flags_free(&flags);
	return (0);
}
