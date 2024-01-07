/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ognl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattali <aattali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 23:19:27 by aattali           #+#    #+#             */
/*   Updated: 2024/01/07 23:20:10 by aattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*oget_next_line(int fd, char **line)
{
	if (*line)
		free(*line);
	*line = get_next_line(fd);
	return (*line);
}
