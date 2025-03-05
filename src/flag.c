#include "flag.h"
#include "help.h"
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define N_PATTERNS 5
#define IGNORE_HIDDEN_FILES "^[.]"
#define IGNORE_CURRENT_DIR "^\\.$"
#define IGNORE_PREV_DIR "^\\.\\.$"

void	init_default_flags(t_flags *flags)
{
	flags->col_width = 20;
	flags->log_dim = false;
	flags->recursive = false;
	flags->show_hidden = false;
	flags->show_version = false;
	flags->show_permissions = false;
	flags->help = false;
	flags->root_path = ".";
	flags->sort_type = SORT_DIRFIRST;
	flags->ignore_patterns = (char **)calloc(N_PATTERNS + 1, sizeof(char *));
	flags->ignore_patterns[0] = strdup(IGNORE_HIDDEN_FILES);
}

static void	set_ignore_patterns(t_flags *flags)
{
	if (flags->show_hidden)
	{
		free(flags->ignore_patterns[0]);
		flags->ignore_patterns[0] = NULL;
	}
	if (flags->recursive && !flags->ignore_patterns[0])
	{
		flags->ignore_patterns[0] = strdup(IGNORE_CURRENT_DIR);
		flags->ignore_patterns[1] = strdup(IGNORE_PREV_DIR);
	}
}

void	get_flags(int argc, char **argv, t_flags *flags)
{
	int32_t	opt;

	if (argc < 2)
		return ;
	if (argv[1] && argv[1][0] != '-')
		flags->root_path = argv[1];
	while ((opt = getopt(argc, argv, FLAG_LIST)) != -1)
	{
		switch (opt)
		{
		case 'd':
			flags->log_dim = true;
			break ;
		case 'a':
			flags->show_hidden = true;
			break ;
		case 'l':
			flags->show_permissions = true;
			break ;
		case 'R':
			flags->recursive = true;
			break ;
		case 'V':
			flags->show_version = true;
			break ;
		case 'h':
			flags->help = true;
			break ;
		default:
			printf(LIST_HELP_STRING);
			exit(EXIT_FAILURE);
		}
	}
	set_ignore_patterns(flags);
}

bool	is_valid_folder(char *name, t_flags options)
{
	char	**pattern;
	regex_t	reg;
	size_t	i;
	bool	res;

	pattern = options.ignore_patterns;
	i = 0;
	res = true;
	while (pattern[i])
	{
		if (regcomp(&reg, pattern[i], 0) != 0)
			return (false);
		if (!regexec(&reg, name, 0, NULL, 0))
		{
			res = false;
			break ;
		}
		regfree(&reg);
		i++;
	}
	if (!res)
		regfree(&reg);
	return (res);
}

void	flags_free(t_flags *flags)
{
	size_t	i;

	i = 0;
	while (flags->ignore_patterns[i])
	{
		free(flags->ignore_patterns[i]);
		i++;
	}
	free(flags->ignore_patterns);
}
