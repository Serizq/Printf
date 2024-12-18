/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:59:40 by seizquie          #+#    #+#             */
/*   Updated: 2024/12/18 19:43:49 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(int c);
int		ft_putstr(char *s);
size_t	ft_putnbr_fd(long n, int fd);
int		convert_to_hex(size_t n, char const format, int pointer);
int		ft_converter(va_list args, char const format);
int		ft_printf(char const *string, ...);
size_t	ft_strlen(const char *s);
#endif
