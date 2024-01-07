/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:18:34 by andy              #+#    #+#             */
/*   Updated: 2024/01/07 22:17:22 by aattali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlen(uintptr_t n)
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

void	ft_putptr(uintptr_t ptr, int fd)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16, fd);
		ft_putptr(ptr % 16, fd);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd(ptr + '0', fd);
		else
			ft_putchar_fd(ptr - 10 + 'a', fd);
	}
}

void	ft_printptr(t_arg *arg)
{
	uintptr_t	ptr;

	ptr = (uintptr_t)va_arg(*arg->args, void *);
	if (!ptr)
		arg->length += ft_putstr_fd("(nil)", arg->fd);
	else
	{
		arg->length += ft_putstr_fd("0x", arg->fd);
		ft_putptr(ptr, arg->fd);
		arg->length += ft_ptrlen(ptr);
	}
}
