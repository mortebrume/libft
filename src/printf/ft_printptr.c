/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:18:34 by andy              #+#    #+#             */
/*   Updated: 2023/11/14 19:10:02 by andy             ###   ########.fr       */
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

void	ft_putptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd(ptr + '0', 1);
		else
			ft_putchar_fd(ptr - 10 + 'a', 1);
	}
}

void	ft_printptr(t_arg *arg)
{
	uintptr_t	ptr;

	ptr = (uintptr_t)va_arg(*arg->args, void *);
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		arg->length += 5;
	}
	else
	{
		arg->length += ft_putstr("0x");
		ft_putptr(ptr);
		arg->length += ft_ptrlen(ptr);
	}
}
