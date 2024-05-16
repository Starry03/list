#include "list.h"
#include <stdio.h>

#define VERSION "Version 1.4"
#define PRINT_VERSION printf("%s\n", VERSION)

int	main(int argc, char **argv)
{
	t_flags	flags;

	init_default_flags(&flags);
	parse_flags(&flags, argc, argv);
	if (!flags.show_version)
		print_folder(flags.root_path, ROOT_LEVEL, flags);
	else
		PRINT_VERSION;
	flags_free(&flags);
	return (0);
}
