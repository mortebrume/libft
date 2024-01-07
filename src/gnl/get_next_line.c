/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:12:32 by aattali           #+#    #+#             */
/*   Updated: 2023/11/21 12:56:08 by aattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	prepare_next(t_list **list, char remaining[BUFFER_SIZE])
{
	t_list	*last_node;
	size_t	i;
	size_t	j;

	i = -1;
	while (remaining[++i])
		remaining[i] = '\0';
	last_node = find_last_node(*list);
	i = 0;
	j = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		i++;
	while (last_node->content[i] && last_node->content[++i])
		remaining[j++] = last_node->content[i];
	remaining[j] = '\0';
	clear_list(list);
}

char	*get_line(t_list *list)
{
	size_t	len;
	char	*s;

	if (!list)
		return (NULL);
	len = newline_len(list);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	ft_strcpy(list, s);
	return (s);
}

void	append(t_list **list, char *buffer)
{
	t_list	*node;
	t_list	*last_node;

	last_node = find_last_node(*list);
	node = malloc(sizeof(t_list));
	if (!node)
		return ;
	if (!last_node)
		*list = node;
	else
		last_node->next = node;
	node->content = buffer;
	node->next = NULL;
}

void	create_list(t_list **list, int fd, char remaining[BUFFER_SIZE])
{
	int		char_read;
	int		checked;
	char	*buffer;

	checked = 0;
	while (!newline_found(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		if (remaining[0] && !checked)
		{
			char_read = -1;
			while (remaining[++char_read])
				buffer[char_read] = remaining[char_read];
			checked++;
		}
		else
			char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read <= 0)
			return (free(buffer));
		buffer[char_read] = '\0';
		append(list, buffer);
	}
}

char	*get_next_line(int fd)
{
	t_list		*list;
	char		*next_line;
	static char	remaining[BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	list = NULL;
	create_list(&list, fd, remaining);
	if (!list)
		return (NULL);
	next_line = get_line(list);
	prepare_next(&list, remaining);
	return (next_line);
}
