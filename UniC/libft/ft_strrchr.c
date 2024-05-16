/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astarran <astarran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:35:02 by astarran          #+#    #+#             */
/*   Updated: 2024/02/20 13:49:55 by astarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*ss;

	i = ft_strlen(s);
	ss = (char *)s;
	while (ss + i >= s)
	{
		if (s[i] == (unsigned char) c)
			return (ss + i);
		i--;
	}
	return (NULL);
}
