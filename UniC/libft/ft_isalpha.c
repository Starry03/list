/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astarran <astarran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:32:21 by astarran          #+#    #+#             */
/*   Updated: 2024/02/19 11:32:22 by astarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	int	isupper;
	int	islower;

	isupper = (c >= 'A' && c <= 'Z');
	islower = (c >= 'a' && c <= 'z');
	return (isupper || islower);
}
