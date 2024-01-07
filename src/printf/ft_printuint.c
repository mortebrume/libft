/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:46:42 by andy              #+#    #+#             */
/*   Updated: 2024/01/07 22:20:05 by aattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uintlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void	ft_putuint(unsigned int n, int fd)
{
	unsigned long	nb;

	nb = (unsigned long) n;
	if (nb > 9)
		ft_putuint(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}

void	ft_printuint(t_arg *arg)
{
	unsigned int	n;

	n = va_arg(*arg->args, unsigned int);
	ft_putuint(n, arg->fd);
	arg->length += ft_uintlen(n);
}
