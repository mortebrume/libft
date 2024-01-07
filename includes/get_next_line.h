/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:03:00 by aattali           #+#    #+#             */
/*   Updated: 2024/01/07 23:22:18 by aattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 77
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*oget_next_line(int fd, char **line);
t_list	*find_last_node(t_list *list);
int		newline_found(t_list *list);
void	ft_strcpy(t_list *list, char *str);
void	clear_list(t_list **list);
size_t	newline_len(t_list *list);

#endif
