#ifndef HEAP_H
# define HEAP_H
# include <stddef.h>

typedef struct s_heap
{
}						t_heap_;

typedef t_heap_			*t_heap;

typedef struct s_heap_entry
{
	void				*key;
	void				*value;
}						t_heap_entry_;

typedef t_heap_entry_	*t_heap_entry;

#endif