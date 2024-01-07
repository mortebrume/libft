/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:05:02 by aattali           #+#    #+#             */
/*   Updated: 2024/01/07 22:21:29 by aattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include "libft.h"

typedef struct s_arg
{
	char	format;
	int		length;
	int		fd;
	va_list	*args;
}	t_arg;

typedef void	(*t_printer)(t_arg *arg);

void	ft_printstr(t_arg *arg);
void	ft_printptr(t_arg *arg);
void	ft_printnbr(t_arg *arg);
void	ft_printuint(t_arg *arg);
void	ft_printhex(t_arg *arg);
void	ft_printpercent(t_arg *arg);
int		ft_printf(const char *s, ...);
int		ft_dprintf(int fd, const char *s, ...);

#endif
