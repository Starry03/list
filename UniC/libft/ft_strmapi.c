/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astarran <astarran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:34:49 by astarran          #+#    #+#             */
/*   Updated: 2024/02/19 15:31:04 by astarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	s_len;
	char			*new_string;

	if (!s || !f)
		return (NULL);
	s_len = (unsigned int)ft_strlen(s);
	new_string = (char *) malloc(sizeof(char) * (s_len + 1));
	if (!new_string)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		new_string[i] = f(i, s[i]);
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
