#ifndef TYPES_H
# define TYPES_H
# include <limits.h>

/* types */
# define GENERIC_NULL (Generic)0
# define STRING_NULL (String)0
typedef void	*Generic;
typedef char	*String;

/* functions */
typedef int		(*Comparator)(Generic, Generic);
typedef void	(*Deallocator)(Generic);

/* index position */
# define START 0
# define LAST ULLONG_MAX

#endif
