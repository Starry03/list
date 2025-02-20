/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astarran <astarran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:35:07 by astarran          #+#    #+#             */
/*   Updated: 2024/02/19 13:58:43 by astarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_string(char const c, char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	left;
	size_t	right;
	char	*new_string;

	if (!s1 || !set)
		return (NULL);
	left = 0;
	right = ft_strlen(s1) - 1;
	while (is_in_string(s1[left], set))
		left++;
	if (left > right)
		return (ft_strdup(""));
	while (is_in_string(s1[right], set))
		right--;
	new_string = (char *)malloc(sizeof(char) * (right - left + 2));
	if (!new_string)
		return (NULL);
	ft_strlcpy(new_string, s1 + left, right - left + 2);
	return (new_string);
}
