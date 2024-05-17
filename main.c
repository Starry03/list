#include "UniC/DataStructures/Dictionary/Dictionary.h"
#include "list.h"
#include <stdio.h>

#define VERSION "Version 1.6"
#define PRINT_VERSION printf("%s\n", VERSION)

int	main(int argc, char **argv)
{
	t_flags	flags;
	t_dict	icons;

	init_default_flags(&flags);
	parse_flags(&flags, argc, argv);
	icons = Dict_Init(50);
	init(&icons);
	if (!flags.show_version)
		print_folder(flags.root_path, ROOT_LEVEL, flags, icons);
	else
		PRINT_VERSION;
	flags_free(&flags);
	Dict_Free(icons);
	return (0);
}
