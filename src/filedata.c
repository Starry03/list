#include "colors.h"
#include "filedata.h"
#include "flag.h"
#include "unic/hashfunctions.h"
#include "utils.h"
#include "wchar.h"
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

t_filedata	*filedata_init(char *name, t_type type, size_t size,
		t_permissions *permissions)
{
	t_filedata	*filedata;

	filedata = (t_filedata *)malloc(sizeof(t_filedata));
	if (!filedata)
		return (NULL);
	filedata->name = strdup(name);
	filedata->type = type;
	filedata->size = size;
	filedata->permissions = permissions;
	return (filedata);
}

void	filedata_free(t_generic filedata)
{
	t_filedata	*f;

	if (!filedata)
		return ;
	f = (t_filedata *)filedata;
	free(f->name);
	if (f->permissions)
		permissions_free(f->permissions);
	free(f);
}

bool	is_valid_type(t_type type)
{
	return (type == T_FILE || type == T_DIR);
}

char	*file_get_extension(char *name)
{
	char	*index;

	index = strchr(name, '.');
	if (!index)
		return (NULL);
	return (index + 1);
}

static char	*filename_truncated(char *name, t_flags flags)
{
	if (strlen(name) < (size_t)flags.col_width - 2)
		return (name);
	memset(name + flags.col_width - 6, '.', 3);
	name[flags.col_width - 3] = '\0';
	return (name);
}

static void	print_permissions(t_permissions *permissions, t_flags options)
{
	printf("%s%s%s%-*s", permissions->owner, permissions->group,
		permissions->others, options.col_width - PERMISSIONS_LENGTH, "");
}

static void	print_dir(t_filedata *filedata, t_flags options)
{
	printf("%s\ue5ff%s %-*s", ORANGE, STD_COLOR, options.col_width - 2,
		filedata->name);
	if (options.show_permissions)
		print_permissions(filedata->permissions, options);
	putc('\n', stdout);
}

static void	print_file(t_filedata *filedata, t_flags options, t_dict icons)
{
	char	*file_extension;
	char	*icon;
	int		col_width;
	char	*filename;

	col_width = options.col_width;
	filename = filedata->name;
	icon = NULL;
	file_extension = file_get_extension(filedata->name);
	if (file_extension)
	{
		icon = (char *)dict_get(icons, file_extension);
	}
	if (!icon)
		printf("%-*s", col_width, filename_truncated(filename, options));
	else
		printf("%s %-*s", icon, col_width - 2, filename_truncated(filename,
				options));
	if (options.show_permissions)
		print_permissions(filedata->permissions, options);
	if (!options.log_dim)
		return ;
	printf("%zu B", filedata->size);
}

void	print_filedata(t_filedata *filedata, t_flags options, t_dict icons)
{
	switch (filedata->type)
	{
	case T_FILE:
		print_file(filedata, options, icons);
		break ;
	case T_DIR:
		print_dir(filedata, options);
		break ;
	default:
		break ;
	}
}

t_filedata	*filedata_get_from_file(struct dirent *d, char *path, t_flags flags)
{
	t_filedata		*filedata;
	FILE			*file;
	size_t			size;
	t_permissions	*permissions;

	permissions = NULL;
	size = 0;
	if (flags.show_permissions)
		permissions = get_permissions(path);
	if (flags.log_dim)
	{
		file = fopen(path, "r");
		if (!file)
			return (NULL);
		size = get_size(file);
		fclose(file);
	}
	filedata = filedata_init(d->d_name, d->d_type, size, permissions);
	return (filedata);
}

int	filedata_cmp(const t_generic a, const t_generic b)
{
	t_filedata *fa, *fb;
	if (!a || !b)
		return (0);
	fa = (t_filedata *)a;
	fb = (t_filedata *)b;
	return (string_compare_ignore_case(fa->name, fb->name));
}

int	filedata_cmp_dirfirst(const t_generic a, const t_generic b)
{
	t_filedata	*fa;
	t_filedata	*fb;

	if (!a || !b)
		return (0);
	fa = (t_filedata *)a;
	fb = (t_filedata *)b;
	if (fa->type == T_DIR && fb->type == T_DIR)
		return (string_compare_ignore_case(fa->name, fb->name));
	if (fa->type == T_DIR)
		return (-1);
	if (fb->type == T_DIR)
		return (1);
	return (string_compare_ignore_case(fa->name, fb->name));
}
