#include "UniC/Utils/Hashing/HashFunctions.h"
#include "UniC/libft/libft.h"
#include "colors.h"
#include "list.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ICON_PATH
# define ICON_PATH "./icons.txt"
#endif

#define BUFSIZE 64
#define ICONS_DICT_SIZE 128

#define ADD_COLOR(dict, name, color_code) (Dict_Add(&dict, ft_strdup(name), ft_strdup(color_code), &hash_string, &free, &free, &string_compare))

/**
 * @brief Initialize the colors dictionary
 * @note Colors are defined in colors.h
 * @return t_dict
 */
static t_dict	colors_dict(void)
{
	t_dict	colors;

	colors = Dict_Init(10);
	ADD_COLOR(colors, "black", BLACK);
	ADD_COLOR(colors, "red", RED);
	ADD_COLOR(colors, "green", GREEN);
	ADD_COLOR(colors, "yellow", YELLOW);
	ADD_COLOR(colors, "blue", BLUE);
	ADD_COLOR(colors, "magenta", MAGENTA);
	ADD_COLOR(colors, "cyan", CYAN);
	ADD_COLOR(colors, "white", WHITE);
	ADD_COLOR(colors, "gray", GRAY);
	ADD_COLOR(colors, "purple", PURPLE);
	return (colors);
}

/**
 * @brief Parse the icons file and return a Theme structure
 * @param config_path Path to the icons file
 * @return Theme
 */
static Theme	theme_parser(const char *config_path)
{
	FILE	*icons_file;
	char	buf[BUFSIZE];
	char	*key_buf;
	char	*icon_buf;
	char	*color_buf;
	Theme	theme;
	t_dict	colors;

	colors = colors_dict();
	theme = Theme_Init("default", Dict_Init(ICONS_DICT_SIZE));
	icons_file = fopen(config_path, "r");
	if (!icons_file)
		return (NULL);
	while (fgets(buf, BUFSIZE, icons_file))
	{
		if (*buf == '#' || *buf == '\n')
			continue ;
		key_buf = ft_strdup(strtok(buf, " "));
		icon_buf = strtok(NULL, " ");
		if (!icon_buf)
		{
			free(key_buf);
			continue ;
		}
		color_buf = strtok(NULL, " ");
		if (!color_buf)
		{
			free(key_buf);
			free(icon_buf);
			continue ;
		}
		if (strrchr(color_buf, '\n'))
			*strrchr(color_buf, '\n') = '\0';
		color_buf = Dict_Get(colors, color_buf, hash_string, string_compare);
		color_buf = ft_strjoin(color_buf, icon_buf);
		color_buf = ft_strfjoin(color_buf, STD_COLOR);
		if (Dict_Add(&theme->icons, key_buf, color_buf, &hash_string, &free,
				&free, &string_compare))
			continue ;
		free(key_buf);
		free(color_buf);
	}
	fclose(icons_file);
	Dict_Free(colors);
	return (theme);
}

void	init(Theme *theme)
{
	*theme = theme_parser(ICON_PATH);
}
