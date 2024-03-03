#include "file_parser.h"
#include <stdbool.h>
#include <string.h>

void parse_flags(int argc, char *argv[], t_print_options *options)
{
	int i = 1;
	while (i < argc)
	{
		if (!strcmp(argv[i], "-r"))
			options->recursive = true;
		else if (!strcmp(argv[i], "-d"))
			options->log_dim = true;
		i++;	
	}
}

int	main(int argc, char *argv[])
{
	char			*root;
	t_print_options options;
	char			*p1 = "^[.]";
	char			*ignore_patterns[] = {p1, 0};
	/* default settings */
	options.log_dim = false;
	options.recursive = false;
	options.ignore_patterns = ignore_patterns;
	options.col_width = 4;
	parse_flags(argc, argv, &options);
	if (argc == 1)
		root = ".";
	else if (argv[1][0] == '-')
		root = ".";
	else
		root = argv[1];
	print_folder(root, ROOT_LEVEL, options);
	return (0);
}
