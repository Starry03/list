#include "list.h"
#include "theme.h"
#include <stdio.h>

#define VERSION "Version 2.2"
#define CHANGE_LOG "Added -h flag"
#define PRINT_VERSION printf("%s\n%s\n", VERSION, CHANGE_LOG)
#define PRINT_HELP printf("Usage: list <path> -flags\n\nOptions:\n  -d\t\tLog dimensions\n  -R\t\tRecursive\n  -a\t\tShow hidden files\n  -V\t\tShow version\n  -l\t\tShow permissions\n  -h\t\tShow help\n")

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
	if (flags.help)
	{
		PRINT_VERSION;
		PRINT_HELP;
	}
	else if (!flags.show_version)
		_main(theme, flags);
	else
		PRINT_VERSION;
	flags_free(&flags);
	return (0);
}
