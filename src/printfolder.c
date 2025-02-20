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

t_linkedlist	get_filedata_list(t_string folder_name, t_flags flags)
{
	t_filedata		*filedata;
	t_linkedlist	filedatas;
	DIR				*dir;
	struct dirent	*dirent_dir;
	t_string		buf;

	filedatas = NULL;
	dir = opendir(folder_name);
	if (!dir)
		return (NULL);
	while ((dirent_dir = readdir(dir)) != NULL)
	{
		buf = build_path(folder_name, dirent_dir->d_name);
		if (!buf)
		{
			free(dirent_dir);
			continue ;
		}
		filedata = filedata_get_from_file(dirent_dir, buf, flags);
		linkedlist_append(&filedatas, filedata);
		free(buf);
	}
	free(dirent_dir);
	closedir(dir);
	return (filedatas);
}

static void	print_folder_core(char *folder_name, size_t folder_level,
		t_filedata *filedata, t_flags flags, t_dict icons)
{
	t_string	buf;

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
	bool		is_first;
	t_filedata	*filedata;

	t_linkedlist filedatas, head;
	is_first = true;
	filedatas = get_filedata_list(folder_name, flags);
	head = filedatas;
	if (flags.sort_type == SORT_DIRFIRST)
		linkedlist_sort(&filedatas, &filedata_cmp_dirfirst);
	else if (flags.sort_type == SORT_NAME)
		linkedlist_sort(&filedatas, &filedata_cmp);
	while (filedatas)
	{
		filedata = (t_filedata *)linkedlist_getinfo(filedatas);
		if (!is_printable(filedata, flags))
		{
			filedatas = linkedlist_getnext(filedatas);
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
		filedatas = linkedlist_getnext(filedatas);
	}
	linkedlist_dealloc(head, &filedata_free);
}
