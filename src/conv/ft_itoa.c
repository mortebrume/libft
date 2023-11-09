/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:22:52 by aattali           #+#    #+#             */
/*   Updated: 2023/11/06 15:22:53 by aattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(int n)
{
	size_t	length;

	length = 0;
	if (n <= 0)
		length++;
	while (n)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char			*result;
	size_t			length;
	unsigned int	nb;

	length = ft_nbrlen(n);
	result = ft_calloc(length + 1, 1);
	if (!result)
		return (NULL);
	nb = (unsigned int) n;
	if (n < 0)
		nb = (unsigned int) -n;
	while (length--)
	{
		result[length] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
