/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:25:41 by aattali           #+#    #+#             */
/*   Updated: 2023/11/15 10:28:58 by aattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printchar(t_arg *arg)
{
	int	c;

	c = va_arg(*arg->args, int);
	ft_putchar_fd(c, 1);
	arg->length++;
}

int	ft_parse_args(t_arg *arg)
{
	t_printer	printer;

	if (arg->format == 'c')
		printer = &ft_printchar;
	else if (arg->format == 's')
		printer = &ft_printstr;
	else if (arg->format == 'p')
		printer = &ft_printptr;
	else if (arg->format == 'd' || arg->format == 'i')
		printer = &ft_printnbr;
	else if (arg->format == 'u')
		printer = &ft_printuint;
	else if (arg->format == 'x' || arg->format == 'X')
		printer = &ft_printhex;
	else if (arg->format == '%')
		printer = &ft_printpercent;
	else
	{
		arg->length = -1;
		return (0);
	}
	printer(arg);
	return (1);
}

int	ft_parse(t_arg *arg, const char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			arg->format = s[i + 1];
			if (!ft_parse_args(arg))
				return (0);
			i++;
		}
		else
			arg->length += write(1, &s[i], 1);
	}
	return (1);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	t_arg	*arg;
	int		length;

	arg = ft_calloc(1, sizeof(*arg));
	if (!arg)
		return (-1);
	va_start(args, s);
	arg->args = &args;
	ft_parse(arg, s);
	length = arg->length;
	free(arg);
	va_end(args);
	return (length);
}
