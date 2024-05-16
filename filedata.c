#include "colors.h"
#include "filedata.h"
#include "flag.h"
#include "utils.h"
#include <stdlib.h>

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

static void	print_dir(t_filedata *filedata)
{
	printf("%s\ue5ff %s%s\n", YELLOW, STD_COLOR, filedata->name);
}

static void	print_file(t_filedata *filedata, t_flags options, size_t name_len)
{
	const size_t	tab_dim = 4;

	printf("%s", filedata->name);
	if (!options.log_dim)
		return ;
	if (name_len >= options.col_width * tab_dim)
		return ;
	printf("\t");
	printf("%zu B", filedata->size);
}

void	print_filedata(t_filedata *filedata, t_flags options, size_t name_len)
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
