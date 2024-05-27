/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:24:52 by aattali           #+#    #+#             */
/*   Updated: 2024/01/11 15:22:53 by aattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin3(const char *s1, const char *s2, const char *s3)
{
	char	*join;
	size_t	length;

	if (!s1 || !s2 || !s3)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1;
	join = ft_calloc(length, 1);
	if (!join)
		return (NULL);
	ft_strlcat(join, s1, length);
	ft_strlcat(join, s2, length);
	ft_strlcat(join, s3, length);
	return (join);
}

char	*ft_strjoin2(char *s1, const char *s2)
{
	char	*join;
	size_t	length;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = ft_calloc(length, 1);
	if (!join)
		return (NULL);
	ft_strlcat(join, s1, length);
	ft_strlcat(join, s2, length);
	free(s1);
	return (join);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	size_t	length;

	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = ft_calloc(length, 1);
	if (!join)
		return (NULL);
	ft_strlcat(join, s1, length);
	ft_strlcat(join, s2, length);
	return (join);
}
