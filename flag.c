#include "flag.h"
#include <regex.h>
#include <stdlib.h>
#include <string.h>

char	*get_flag(enum e_flag flag)
{
	switch (flag)
	{
	case LOG_DIM:
		return ("-d");
	case RECURSIVE:
		return ("-R");
	case SHOW_HIDDEN:
		return ("-a");
	}
	return (NULL);
}

void	init_default_flags(t_flags *flags)
{
	char	**patterns;

	patterns = (char **)malloc(sizeof(char *) * 2);
	patterns[0] = "^[.]";
	patterns[1] = 0;
	flags->log_dim = false;
	flags->recursive = false;
	flags->show_hidden = false;
	flags->col_width = 4;
	flags->root_path = ".";
	flags->ignore_patterns = patterns;
}

void	parse_flags(t_flags *flags, size_t argc, char **argv)
{
	size_t i;
	if (argc < 2)
		return ;
	if (argv[1][0] != '-')
		flags->root_path = argv[1];
	i = 1;
	while (i < argc)
	{
		if (strcmp(argv[i], get_flag(LOG_DIM)) == 0)
			flags->log_dim = true;
		else if (strcmp(argv[i], get_flag(RECURSIVE)) == 0)
			flags->recursive = true;
		else if (strcmp(argv[i], get_flag(SHOW_HIDDEN)) == 0)
		{
			flags->show_hidden = true;
			flags->ignore_patterns[0] = "^$";
		}
		i++;
	}
}

bool	is_valid_folder(char *name, t_flags options)
{
	regex_t	reg;
	size_t	i;
	bool	res;

	res = true;
	i = 0;
	while (options.ignore_patterns[i])
	{
		if (regcomp(&reg, options.ignore_patterns[i], 0) != 0)
		{
			res = false;
			break ;
		}
		if (!regexec(&reg, name, 0, NULL, 0))
		{
			res = false;
			break ;
		}
		i++;
	}
	regfree(&reg);
	return (res);
}