/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:00:24 by seizquie          #+#    #+#             */
/*   Updated: 2024/12/10 18:32:24 by seizquie         ###   ########.fr       */
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
