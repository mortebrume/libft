/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:55:28 by andy              #+#    #+#             */
/*   Updated: 2024/01/07 22:17:52 by aattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

void	ft_puthex(unsigned int n, char format, int fd)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, format, fd);
		ft_puthex(n % 16, format, fd);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + '0', fd);
		else
		{
			if (format == 'x')
				ft_putchar_fd(n - 10 + 'a', fd);
			else if (format == 'X')
				ft_putchar_fd(n - 10 + 'A', fd);
		}
	}
}

void	ft_printhex(t_arg *arg)
{
	unsigned int	n;

	n = va_arg(*arg->args, unsigned int);
	if (!n)
		arg->length += write(1, "0", arg->fd);
	else
	{
		ft_puthex(n, arg->format, arg->fd);
		arg->length += ft_hexlen(n);
	}
}
