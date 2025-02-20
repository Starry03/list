#include "filedata.h"
#include <sys/stat.h>

size_t	get_size(FILE *file)
{
	size_t	bytes;

	if (!file || fseek(file, 0, SEEK_END) < 0)
		return (0);
	bytes = ftell(file);
	return (bytes);
}

static void	assign_usr_permissions(t_string buf, struct stat filestat)
{
	if (!buf)
		return ;
	buf[0] = (filestat.st_mode & S_IRUSR) ? 'r' : '-';
	buf[1] = (filestat.st_mode & S_IWUSR) ? 'w' : '-';
	buf[2] = (filestat.st_mode & S_IXUSR) ? 'x' : '-';
}

static void	assign_group_permissions(t_string buf, struct stat filestat)
{
	if (!buf)
		return ;
	buf[0] = (filestat.st_mode & S_IRGRP) ? 'r' : '-';
	buf[1] = (filestat.st_mode & S_IWGRP) ? 'w' : '-';
	buf[2] = (filestat.st_mode & S_IXGRP) ? 'x' : '-';
}

static void	assign_oth_permissions(t_string buf, struct stat filestat)
{
	if (!buf)
		return ;
	buf[0] = (filestat.st_mode & S_IROTH) ? 'r' : '-';
	buf[1] = (filestat.st_mode & S_IWOTH) ? 'w' : '-';
	buf[2] = (filestat.st_mode & S_IXOTH) ? 'x' : '-';
}

t_permissions	*get_permissions(t_string path)
{
	t_permissions	*permissions;
	struct stat		fileStat;

	t_string owner, group, others;
	if (!path)
		return (NULL);
	permissions = permissions_init();
	owner = permissions->owner;
	group = permissions->group;
	others = permissions->others;
	stat(path, &fileStat);
	assign_usr_permissions(owner, fileStat);
	assign_group_permissions(group, fileStat);
	assign_oth_permissions(others, fileStat);
	return (permissions);
}
