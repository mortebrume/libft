/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:24:21 by aattali           #+#    #+#             */
/*   Updated: 2023/11/06 15:24:22 by aattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*ptr;

	if (!dest && !src)
		return (NULL);
	ptr = dest;
	while (n--)
		*((unsigned char *)ptr++) = *((unsigned char *)src++);
	return (dest);
}
