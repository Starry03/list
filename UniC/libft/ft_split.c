/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astarran <astarran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:30:45 by astarran          #+#    #+#             */
/*   Updated: 2024/02/20 12:08:21 by astarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	cnt_split(char const *s, char c, size_t *i, size_t *j)
{
	size_t	count;
	char	was_sep;

	count = 0;
	was_sep = 1;
	*i = 0;
	*j = 0;
	while (*s)
	{
		if (was_sep && *s != c)
			count++;
		was_sep = *s == c;
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	ind[2];
	size_t	words;
	size_t	count;

	if (!s)
		return (NULL);
	words = cnt_split(s, c, ind, ind + 1);
	arr = (char **) malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	count = 0;
	while (count < words)
	{
		ind[0] = ind[1];
		while (s[ind[0]] && s[ind[0]] == c)
			ind[0]++;
		ind[1] = ind[0] + 1;
		while (s[ind[1]] && s[ind[1]] != c)
			ind[1]++;
		arr[count] = (char *) malloc(sizeof(char) * (ind[1] - ind[0] + 1));
		ft_strlcpy(arr[count++], s + ind[0], ind[1] - ind[0] + 1);
	}
	arr[count] = NULL;
	return (arr);
}
