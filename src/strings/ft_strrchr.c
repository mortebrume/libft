/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:25:12 by aattali           #+#    #+#             */
/*   Updated: 2023/11/06 15:52:12 by aattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*last;

	i = -1;
	c = c % 256;
	last = NULL;
	while (s[++i])
		if (s[i] == c)
			last = (char *)&s[i];
	if (s[i] == c)
		return ((char *)&s[i]);
	return (last);
}
