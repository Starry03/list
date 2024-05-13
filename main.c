#include "flag.h"
#include "printfolder.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_flags	flags;

	init_default_flags(&flags);
	parse_flags(&flags, argc, argv);
	print_folder(flags.root_path, ROOT_LEVEL, flags);
	flags_free(&flags);
	return (0);
}
