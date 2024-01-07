/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:04:18 by andy              #+#    #+#             */
/*   Updated: 2024/01/07 22:14:08 by aattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printstr(t_arg *arg)
{
	char	*s;

	s = va_arg(*arg->args, char *);
	if (!s)
	{
		ft_putstr_fd("(null)", arg->fd);
		arg->length += 6;
	}
	else
		arg->length += ft_putstr_fd(s, arg->fd);
}

void	ft_printnbr(t_arg *arg)
{
	char	*nb;
	int		number;

	number = va_arg(*arg->args, int);
	nb = ft_itoa(number);
	arg->length += ft_putstr_fd(nb, arg->fd);
	free(nb);
}

void	ft_printpercent(t_arg *arg)
{
	ft_putchar_fd('%', arg->fd);
	arg->length++;
}
