/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattali <aattali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:35:35 by aattali           #+#    #+#             */
/*   Updated: 2024/05/26 17:37:50 by aattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str;
	unsigned char	*str1;
	size_t			size_s1;
	size_t			size_s2;

	str = (unsigned char *)s1;
	str1 = (unsigned char *)s2;
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	if (!n)
		return (0);
	while (n--)
	{
		if (str[size_s1] != str1[size_s2])
			return (str[size_s1] - str1[size_s2]);
		size_s1--;
		size_s2--;
	}
	return (0);
}
