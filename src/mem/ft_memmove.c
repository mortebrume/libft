/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:24:24 by aattali           #+#    #+#             */
/*   Updated: 2023/11/08 14:42:59 by aattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void		*pdest;
	const void	*psrc;

	if (!dest && !src)
		return (NULL);
	if (dest < src)
	{
		pdest = dest;
		while (n--)
			*((unsigned char *)pdest++) = *((unsigned char *)src++);
	}
	else
	{
		pdest = dest + (n - 1);
		psrc = src + (n - 1);
		while (n--)
			*((unsigned char *)pdest--) = *((unsigned char *)psrc--);
	}
	return (dest);
}
