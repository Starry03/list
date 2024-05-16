#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>

char	*build_path(char *path, char *file_name);
size_t	get_size(FILE *file);
void	ft_print_n(char c, size_t n);
int		string_compare(Generic a, Generic b);

#endif // !UTILS_H
