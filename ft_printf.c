/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gramiro- <gramiro-@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:51:47 by gramiro-          #+#    #+#             */
/*   Updated: 2022/03/26 02:39:58 by gramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexavoid(uintptr_t nb)
{
	int		count;
	char	*s;

	count = 0;
	if (nb < 16)
	{
		s = "0123456789abcdef";
		count += ft_putchar(s[nb]);
	}		
	else
	{
		count += ft_hexavoid(nb / 16);
		count += ft_hexavoid(nb % 16);
	}
	return (count);
}

int	ft_format(char c, va_list ptr)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(ptr, int));
	if (c == 's')
		count += ft_putstr(va_arg(ptr, char *));
	if (c == 'p')
	{
		count += ft_putstr("0x");
		count += ft_hexavoid(va_arg(ptr, uintptr_t));
	}
	if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(ptr, int));
	if (c == 'u')
		count += ft_putnbr_uns(va_arg(ptr, unsigned int));
	if (c == 'x' || c == 'X')
		count += ft_hexa(va_arg(ptr, unsigned int), c);
	if (c == '%')
		count += write (1, "%", 1);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	int		x;
	va_list	ptr;

	x = 0;
	va_start(ptr, s);
	count = 0;
	while (s[x])
	{
		if (s[x] == '%')
		{
			x++;
			count += ft_format(s[x], ptr);
		}
		else
			count += write (1, &s[x], 1);
		x++;
	}
	va_end(ptr);
	return (count);
}
