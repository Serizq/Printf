/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:00:24 by seizquie          #+#    #+#             */
/*   Updated: 2024/12/12 19:27:22 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int	c)
{
	write(1, &c, 1);
	return (1);
}
int	ft_putstr(char *s)
{
	if (s)
	{
		write(1, s, ft_strlen(s));
		return(ft_strlen(s));
	}
	if(!s)
	{
		write(1, "(null)", 6);
		return(6);
	}

		
}

int	convert_to_hex(size_t	n, char const	format, int pointer)
{
	int	chars_to_print;

	chars_to_print = 0;
	if(pointer && n == 0)
		return(ft_putstr("(nil)"));
	else if(pointer)
		chars_to_print += ft_putstr("0x");
	if(n == 0)
		return(chars_to_print + ft_putchar('0'));
	
}
