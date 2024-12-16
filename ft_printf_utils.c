/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:00:24 by seizquie          #+#    #+#             */
/*   Updated: 2024/12/16 19:27:26 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	if (s)
	{
		write(1, s, ft_strlen(s));
		return (ft_strlen(s));
	}
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
}

size_t	ft_putnbr_fd(long n, int fd)
{
	size_t	i;

	i = 0;
	if (n == (-__LONG_MAX__) - 1)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('9', fd);
		i += 2;
		n = 223372036854775808;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		i++;
		n = -n;
	}
	if (n >= 10)
	{
		i += ft_putnbr_fd(n / 10, fd);
	}
	ft_putchar_fd((n % 10) + '0', fd);
	return (i + 1);
}

int	convert_to_hex(size_t n, char const format, int pointer)
{
	int	chars_to_print;

	chars_to_print = 0;
	if (pointer && n == 0)
		return (ft_putstr("(nil)"));
	else if (pointer)
		chars_to_print += ft_putstr("0x");
	if (n == 0)
		return (chars_to_print + ft_putchar('0'));
	if (n >= 16)
		chars_to_print += convert_to_hex(n / 16, format, 0);
	if (n % 16 <= 9)
		chars_to_print += ft_putchar((n % 16 + '0'));
	else if (format == 'x' || pointer)
		chars_to_print += ft_putchar((n % 16 - 10 + 'a'));
	else if (format == 'X')
		chars_to_print += ft_putchar((n % 16 - 10 + 'A'));
	return (chars_to_print);
}

