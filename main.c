#include "list.h"
#include "theme.h"
#include <stdio.h>

#define VERSION "Version 1.8"
#define PRINT_VERSION printf("%s\n", VERSION)

int	main(int argc, char **argv)
{
	t_flags	flags;
	Theme	theme;

	init_default_flags(&flags);
	parse_flags(&flags, argc, argv);
	if (!flags.show_version)
	{
		init(&theme);
		print_folder(flags.root_path, ROOT_LEVEL, flags, theme->icons);
		if (theme)
			Theme_Free(theme);
	}
	else
		PRINT_VERSION;
	flags_free(&flags);
	return (0);
}
