#ifndef PRINTFOLDER_H
# define PRINTFOLDER_H

# include "flag.h"
# include "UniC/DataStructures/Dictionary/Dictionary.h"

void	init(t_dict *icons);
void	print_folder(char *folder_name, size_t folder_level, t_flags options, t_dict icons);

#endif