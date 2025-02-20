#ifndef TYPES_H
# define TYPES_H
# include <limits.h>
# include <stddef.h>

/* types */
typedef void	*t_generic;
typedef char	*t_string;
# define GENERIC_NULL (t_generic)0
# define STRING_NULL (t_string)0

/* functions */
typedef int		(*t_comparator)(const t_generic, const t_generic);
typedef void	(*t_deallocator)(t_generic);
typedef size_t	(*t_hasher)(t_generic, size_t);

/* index position */
# define START 0
# define LAST ULLONG_MAX

#endif
