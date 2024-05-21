#include "UniC/Utils/Hashing/HashFunctions.h"
#include "colors.h"
#include "filedata.h"
#include "flag.h"
#include "utils.h"
#include "wchar.h"
#include <locale.h>
#include <stdlib.h>
#include <string.h>

t_filedata	*filedata_init(char *name, t_type type, size_t size)
{
	t_filedata	*addr;

	addr = (t_filedata *)malloc(sizeof(t_filedata));
	if (!addr)
		return (NULL);
	addr->name = name;
	addr->type = type;
	addr->size = size;
	return (addr);
}

bool	is_valid_type(t_type type)
{
	return (type == T_FILE || type == T_DIR);
}

char	*file_get_extension(char *name)
{
	char	*index;

	index = strrchr(name, '.');
	if (!index)
		return (NULL);
	return (index + 1);
}

static void	print_dir(t_filedata *filedata)
{
	printf("%s\ue5ff %s%s\n", YELLOW, STD_COLOR, filedata->name);
}

static void	print_file(t_filedata *filedata, t_flags options, t_dict icons)
{
	char	*file_extension;
	char	*icon;
	int		col_width;
	size_t	name_len;

	col_width = options.col_width;
	name_len = strlen(filedata->name);
	while ((size_t)col_width < name_len)
		col_width *= 2;
	icon = NULL;
	file_extension = file_get_extension(filedata->name);
	if (file_extension)
		icon = (char *)Dict_Get(icons, file_extension, hash_string,
				string_compare);
	if (!icon)
		printf("%-*s", col_width, filedata->name);
	else
		printf("%s %-*s", icon, col_width - 2, filedata->name);
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
		print_dir(filedata);
		break ;
	default:
		break ;
	}
}

t_filedata	*filedata_get_from_file(struct dirent *d, char *path,
		bool calc_size)
{
	t_filedata	*filedata;
	FILE		*file;
	size_t		size;

	size = 0;
	if (calc_size)
	{
		file = fopen(path, "r");
		if (!file)
			return (NULL);
		size = get_size(file);
		fclose(file);
	}
	filedata = filedata_init(d->d_name, d->d_type, size);
	return (filedata);
}
