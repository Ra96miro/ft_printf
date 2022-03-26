/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functionprintf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gramiro- <gramiro-@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:41:00 by gramiro-          #+#    #+#             */
/*   Updated: 2022/03/26 02:39:13 by gramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	x;
	int	count;

	count = 0;
	x = -1;
	if (!s)
		s = "(null)";
	while (s[++x])
	{
		count += ft_putchar(s[x]);
	}
	return (count);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		count += ft_putchar('-');
		count += ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = nb * -1;
	}
	if (nb < 10)
		count += ft_putchar(nb + 48);
	else
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	return (count);
}

int	ft_putnbr_uns(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb < 10)
		count += ft_putchar(nb + 48);
	else
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	return (count);
}

int	ft_hexa(unsigned int nb, char c)
{
	int		count;
	char	*s;

	count = 0;
	if (nb < 16)
	{
		if (c == 'x')
		{
			s = "0123456789abcdef";
			count += ft_putchar(s[nb]);
		}
		else if (c == 'X')
		{
			s = "0123456789ABCDEF";
			count += ft_putchar(s[nb]);
		}
	}		
	else
	{
		count += ft_hexa((nb / 16), c);
		count += ft_hexa((nb % 16), c);
	}
	return (count);
}
