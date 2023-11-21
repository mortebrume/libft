/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:04:18 by andy              #+#    #+#             */
/*   Updated: 2023/11/14 19:10:28 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
	return (i);
}

void	ft_printstr(t_arg *arg)
{
	char	*s;

	s = va_arg(*arg->args, char *);
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		arg->length += 6;
	}
	else
		arg->length += ft_putstr(s);
}

void	ft_printnbr(t_arg *arg)
{
	char	*nb;
	int		number;

	number = va_arg(*arg->args, int);
	nb = ft_itoa(number);
	arg->length += ft_putstr(nb);
	free(nb);
}

void	ft_printpercent(t_arg *arg)
{
	ft_putchar_fd('%', 1);
	arg->length++;
}
