/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:59:22 by seizquie          #+#    #+#             */
/*   Updated: 2024/12/12 19:45:47 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_converter(va_list args, char const format)
{
	int	size;

	size = 0;
	if(format == 'c')
		size += ft_putchar(va_arg(args, int));
	else if (format == 's')
		size += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		size += convert_to_hex((size_t)va_arg(args, void*), 'x', 1);
	return(size);
}



int	ft_printf(char const	*string, ...)
{
	int	i;
	int	size;
	va_list	args;

	i = 0;
	size = 0;
	va_start(args, string);

	while(string[i])
	{
		if(string[i] == '%')
		{
			size += ft_converter(args, string[i+1]);
			i++;
		}
		else
			size +=	ft_putchar(string[i]);
		i++;
	}
	va_end(args);
	return(size);
}
