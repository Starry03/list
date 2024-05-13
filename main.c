#include "printfolder.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_flags	flags;

	init_default_flags(&flags);
	parse_flags(&flags, argc, argv);
	if (!flags.show_version)
		print_folder(flags.root_path, ROOT_LEVEL, flags);
	else
		printf("Version 1.4\n");
	flags_free(&flags);
	return (0);
}
