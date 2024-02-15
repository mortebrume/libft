/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:24:46 by aattali           #+#    #+#             */
/*   Updated: 2024/02/15 09:07:23 by aattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;

	dup = ft_calloc(ft_strlen(s) + 1, 1);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, ft_strlen(s) + 1);
	return (dup);
}

char	**ft_stradup(char **arr)
{
	char **dup;
	size_t	i;

	dup = ft_calloc(ft_stralen(arr) + 1, sizeof(dup));
	if (!dup)
		return (NULL);
	i = -1;
	while (arr[++i])
	{
		dup[i] = ft_strdup(arr[i]);
		if (!dup[i])
			return (ft_free_astr(dup), NULL);
	}
	return (dup);
}
