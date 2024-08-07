#include "colors.h"
#include "filedata.h"
#include "flag.h"
#include "list.h"
#include "utils.h"
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define print_tabs(n) ft_print_n('\t', n)
#define TREE_BRANCH "  L\t"

bool	is_printable(t_filedata *filedata, t_flags flags)
{
	return (filedata && is_valid_type(filedata->type)
		&& is_valid_folder(filedata->name, flags));
}

static void	print_folder_core(char *folder_name, size_t folder_level,
		t_filedata *filedata, t_flags flags, t_dict icons)
{
	char	*buf;

	print_filedata(filedata, flags, icons);
	if (filedata->type == T_DIR && flags.recursive)
	{
		buf = build_path(folder_name, filedata->name);
		print_folder(buf, folder_level + 1, flags, icons);
		free(buf);
	}
	else if (filedata->type != T_DIR)
		printf("\n");
}

void	print_folder(char *folder_name, size_t folder_level, t_flags flags,
		t_dict icons)
{
	DIR				*dir;
	t_filedata		*filedata;
	struct dirent	*dirent_dir;
	char			*buf;
	bool			is_first;

	is_first = true;
	dir = opendir(folder_name);
	if (!dir)
		return ;
	while ((dirent_dir = readdir(dir)) != NULL)
	{
		buf = build_path(folder_name, dirent_dir->d_name);
		if (!buf)
		{
			free(dirent_dir);
			continue ;
		}
		filedata = filedata_get_from_file(dirent_dir, buf, flags);
		free(buf);
		if (!is_printable(filedata, flags))
		{
			filedata_free(filedata);
			continue ;
		}
		if (is_first && folder_level)
		{
			print_tabs(folder_level - 1);
			printf(TREE_BRANCH);
			is_first = false;
		}
		else
			ft_print_n('\t', folder_level);
		print_folder_core(folder_name, folder_level, filedata, flags, icons);
		filedata_free(filedata);
	}
	free(dirent_dir);
	closedir(dir);
}
