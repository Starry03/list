#include "unic/hashfunctions.h"
#include "unic/comparators.h"
#include "libft/libft.h"
#include "colors.h"
#include "list.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 64
#define ICONS_DICT_SIZE 128

#define ADD_COLOR(dict, name, color_code) (dict_add(dict, ft_strdup(name), ft_strdup(color_code), &free))

/**
 * @brief Initialize the colors dictionary
 * @note Colors are defined in colors.h
 * @return t_dict
 */
static t_dict	colors_dict(void)
{
	t_dict	colors;

	colors = dict_init(10, &cmp_string, &hash_string, &free);
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
	ADD_COLOR(colors, "orange", ORANGE);
	return (colors);
}

/**
 * @brief Parse the icons file and return a Theme structure
 * @param config_path Path to the icons file
 * @return Theme
 */
t_theme	theme_parser(const char *config_path)
{
	FILE	*icons_file;
	char	buf[BUFSIZE];
	char	*key_buf;
	char	*icon_buf;
	char	*color_buf;
	t_theme	theme;
	t_dict	colors;

	colors = colors_dict();
	theme = theme_init("default", dict_init(ICONS_DICT_SIZE, &cmp_string, &hash_string, &free));
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
		color_buf = dict_get(colors, color_buf);
		color_buf = ft_strjoin(color_buf, icon_buf);
		color_buf = ft_strfjoin(color_buf, STD_COLOR);
		if (dict_add(theme->icons, key_buf, color_buf, &free))
			continue ;
		free(key_buf);
		free(color_buf);
	}
	fclose(icons_file);
	dict_free(colors);
	return (theme);
}
