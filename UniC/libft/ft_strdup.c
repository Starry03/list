/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starry <starry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:34:26 by astarran          #+#    #+#             */
/*   Updated: 2024/05/13 20:02:47 by starry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*addr;

	len = ft_strlen(s);
	addr = malloc(sizeof(char) * (len + 1));
	if (!addr)
		return (NULL);
	ft_strlcpy(addr, s, len + 1);
	return (addr);
}
