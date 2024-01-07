/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:38:12 by aattali           #+#    #+#             */
/*   Updated: 2023/11/21 11:41:45 by aattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clear_list(t_list **list)
{
	t_list	*tmp;

	if (!*list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
}

t_list	*find_last_node(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	newline_found(t_list *list)
{
	int	i;

	list = find_last_node(list);
	if (!list)
		return (0);
	i = -1;
	while (list->content[++i] && i < BUFFER_SIZE)
	{
		if (list->content[i] == '\n')
			return (1);
	}
	return (0);
}

void	ft_strcpy(t_list *list, char *str)
{
	size_t	i;
	size_t	j;

	if (!list)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = list->content[i++];
		}
		list = list->next;
	}
	str[j] = '\0';
}

size_t	newline_len(t_list *list)
{
	size_t	i;
	size_t	len;

	if (!list)
		return (0);
	len = 0;
	while (list)
	{
		i = -1;
		while (list->content[++i])
		{
			if (list->content[i] == '\n')
				return (++len);
			len++;
		}
		list = list->next;
	}
	return (len);
}
