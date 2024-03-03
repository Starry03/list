#include "colors.h"
#include "filedata.h"
#include "printfolder.h"
#include "utils.h"
#include <dirent.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

void	print_folder(char *folder_name, size_t folder_level, t_flags options)
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
		else if (filedata->type != T_DIR)
			printf("\n");
		is_first = 0;
		filedata_free(filedata);
	}
	free(d);
	closedir(dir);
}
