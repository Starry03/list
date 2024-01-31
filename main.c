#include "file_parser.h"
#include <stdbool.h>

int	main(int argc, char *argv[])
{
	char			*root;
	t_print_options options;
	char			*p1 = "^[.]";
	char			*ignore_patterns[] = {p1, 0};
	/* default settings */
	options.log_dim = true;
	options.ignore_patterns = ignore_patterns;
	options.col_width = 4;
	if (argc == 1)
		root = ".";
	else 
		root = argv[1];
	printf("%s\ue5ff ROOT: %s%s \n", GREEN, root, STD_COLOR);
	print_folder(root, ROOT_LEVEL, options);
	return (0);
}
