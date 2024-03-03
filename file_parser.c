#include "builders.h"
#include "file_parser.h"
#include <dirent.h>
#include <regex.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static size_t	get_size(FILE *file)
{
	size_t	bytes;

	bytes = 0;
	while (fgetc(file) != EOF)
		bytes++;
	return (bytes);
}

t_filedata	*filedata_init(char *name, t_type type, FILE *file)
{
	t_filedata	*addr;

	addr = (t_filedata *)malloc(sizeof(t_filedata));
	if (!addr)
		return (NULL);
	addr->name = name;
	addr->type = type;
	addr->size = get_size(file);
	return (addr);
}

void	ft_print_n(char c, size_t n)
{
	size_t	i;

	i = 0;
	while (i++ < n)
		printf("%c", c);
}

bool	is_valid_folder(char *name, t_print_options options)
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

void	print_folder(char *folder_name, size_t folder_level,
		t_print_options options)
{
	DIR				*dir;
	FILE			*file;
	t_filedata		*filedata;
	struct dirent	*d;
	char			*buf;
	size_t			is_first;
	size_t			name_len;

	is_first = 1;
	dir = opendir(folder_name);
	if (!dir)
	{
		write(2, "not found\n", 10);
		return ;
	}
	while ((d = readdir(dir)) != NULL)
	{
		buf = build_path(folder_name, d->d_name);
		if (!buf)
		{
			free(d);
			continue ;
		}
		file = fopen(buf, "r");
		free(buf);
		if (!file)
		{
			free(d);
			continue ;
		}
		filedata = filedata_init(d->d_name, d->d_type, file);
		fclose(file);
		if (!is_valid_folder(filedata->name, options))
		{
			filedata_free(filedata);
			continue ;
		}
		if (is_first && folder_level)
		{
			ft_print_n('\t', folder_level - 1);
			printf("  L\t");
		}
		else
			ft_print_n('\t', folder_level);
		name_len = strlen(filedata->name);
		print_filedata(filedata, options, name_len);
		if (filedata->type == T_DIR && options.recursive)
		{
			buf = build_path(folder_name, filedata->name);
			print_folder(buf, folder_level + 1, options);
			free(buf);
		}
		else if (filedata->type != T_DIR) printf("\n");
		is_first = 0;
		filedata_free(filedata);
	}
	free(d);
	closedir(dir);
}

static void	print_dir(t_filedata *filedata)
{
	printf("%s\ue5ff %s%s\n", GREEN, filedata->name, STD_COLOR);
}

static void	print_file(t_filedata *filedata, t_print_options options,
		size_t name_len)
{
	const size_t	tab_dim = 4;
	size_t			n_tabs;
	size_t			gap;

	printf("%s%s%s", STD_COLOR, filedata->name, STD_COLOR);
	if (!options.log_dim)
		return ;
	if (name_len >= options.col_width * tab_dim)
		return ;
	printf("\t");
	printf("%zu b", filedata->size);
}

void	print_filedata(t_filedata *filedata, t_print_options options,
		size_t name_len)
{
	switch (filedata->type)
	{
	case T_FILE:
		print_file(filedata, options, name_len);
		break ;
	case T_DIR:
		print_dir(filedata);
		break ;
	default:
		break ;
	}
}

void	filedata_free(t_filedata *filedata)
{
	free(filedata);
}
