/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:59:22 by seizquie          #+#    #+#             */
/*   Updated: 2024/12/18 19:43:29 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_converter(va_list args, char const format)
{
	int	size;

	size = 0;
	if (format == 'c')
		size += ft_putchar(va_arg(args, int));
	else if (format == 's')
		size += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		size += convert_to_hex((size_t)va_arg(args, void *), 'x', 1);
	else if (format == 'd' || format == 'i')
		size += ft_putnbr_fd(va_arg(args, int), 1);
	else if (format == 'u')
		size += ft_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (format == 'x')
		size += convert_to_hex(va_arg(args, unsigned int), 'x', 0);
	else if (format == 'X')
		size += convert_to_hex(va_arg(args, unsigned int), 'X', 0);
	else if (format == '%')
		size += ft_putchar('%');
	return (size);
}

int	ft_printf(char const *string, ...)
{
	int		i;
	int		size;
	va_list	args;

	i = 0;
	size = 0;
	va_start(args, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			size += ft_converter(args, string[i + 1]);
			i++;
		}
		else
			size += ft_putchar(string[i]);
		i++;
	}
	va_end(args);
	return (size);
}
/*#include <stdio.h>

int	main(void)
{
	int	results;

	results = ft_printf("Hola %s\n", "Sergio");
	printf("Caracteres impresos: %i\n", results);

	results = ft_printf("El carácter printeado es:%c\n", 'A');
	printf("Caráteres impresos:%d\n", results);

	results = ft_printf("Varios identificadores: %u, %d, %c, %s\n", 27, -88,
			'r', "Sergio");
	printf("Caracteres impresos:%i\n", results);

	int	x = 25;
	int	*pointer;

	pointer = &x;
	results = ft_printf("La dirección de memoria es: %p\n", &x);
	printf("El valor de x es:%d\n", x);
	return(0);
}*/