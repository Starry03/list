/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astarran <astarran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:34:57 by astarran          #+#    #+#             */
/*   Updated: 2024/02/19 15:20:06 by astarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_starts_with(const char *s, const char *sub)
{
	return (ft_strncmp(s, sub, ft_strlen(sub)) == 0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	if (!*little || (!big && !len))
		return ((char *)big);
	i = 0;
	little_len = ft_strlen(little);
	while (big[i] && i + little_len - 1 < len)
	{
		if (ft_starts_with(big + i, little))
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
