/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:25:14 by aattali           #+#    #+#             */
/*   Updated: 2023/11/13 12:06:55 by aattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (ft_inset(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	if (start == end + 1)
		return (ft_calloc(1, 1));
	while (ft_inset(s1[end], set))
		end--;
	trimmed = ft_substr(s1, start, (end - start + 1));
	return (trimmed);
}
