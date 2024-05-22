#include "flag.h"
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_PATTERNS 5
#define IGNORE_HIDDEN_FILES "^[.]"
#define IGNORE_CURRENT_DIR "^\\.$"
#define IGNORE_PREV_DIR "^\\.\\.$"

#define HAS_FLAG(FLAG, i) strstr(argv[i], get_flag(FLAG));

char	*get_flag(enum e_flag flag)
{
	switch (flag)
	{
	case LOG_DIM:
		return ("d");
	case RECURSIVE:
		return ("R");
	case SHOW_HIDDEN:
		return ("a");
	case VERSION:
		return ("V");
	case PERMISSIONS:
		return ("l");
	}
	return (NULL);
}

void	init_default_flags(t_flags *flags)
{
	flags->col_width = 20;
	flags->log_dim = false;
	flags->recursive = false;
	flags->show_hidden = false;
	flags->show_version = false;
	flags->show_permissions = false;
	flags->root_path = ".";
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

void	parse_flags(t_flags *flags, size_t argc, char **argv)
{
	size_t	i;

	i = 1;
	if (argc < 2)
		return ;
	if (argv[1][0] != '-')
	{
		flags->root_path = argv[1];
		i++;
	}
	flags->log_dim = HAS_FLAG(LOG_DIM, i);
	flags->recursive = HAS_FLAG(RECURSIVE, i);
	flags->show_hidden = HAS_FLAG(SHOW_HIDDEN, i);
	flags->show_version = HAS_FLAG(VERSION, i);
	flags->show_permissions = HAS_FLAG(PERMISSIONS, i);
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
