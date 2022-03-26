/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gramiro- <gramiro-@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:42:51 by gramiro-          #+#    #+#             */
/*   Updated: 2022/03/26 19:05:29 by gramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_format(char c, va_list ptr);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int nb);
int	ft_putnbr_uns(unsigned int nb);
int	ft_hexa(unsigned int nb, char c);
int	ft_hexavoid(uintptr_t nb);

#endif