/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:25:10 by aattali           #+#    #+#             */
/*   Updated: 2023/11/06 15:25:10 by aattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	if (!n)
		return (NULL);
	i = ft_strlen(needle);
	j = 0;
	while (ft_strncmp(&haystack[j], needle, i))
	{
		if (!haystack[j] || j >= (n - i))
			return (NULL);
		j++;
	}
	if (i > n)
		return (NULL);
	return ((char *)&haystack[j]);
}
