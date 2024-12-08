/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:41:10 by oriabenk          #+#    #+#             */
/*   Updated: 2024/11/10 17:14:21 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

static ssize_t	print_arguments(int fd, const char c, va_list args)
{
	char	*base10;
	char	*base16l;
	char	*base16u;

	base10 = "0123456789";
	base16l = "0123456789abcdef";
	base16u = "0123456789ABCDEF";
	if (c == 'c')
		return (print_char(fd, (unsigned char)va_arg(args, int)));
	if (c == 's')
		return (print_string(fd, va_arg(args, const char *)));
	if (c == 'p')
		return (print_ptr(fd, va_arg(args, unsigned long)));
	if (c == 'd' || c == 'i')
		return (print_number(fd, va_arg(args, int), base10, 10));
	if (c == 'u')
		return (print_unumber(fd, va_arg(args, unsigned int), base10, 10));
	if (c == 'x')
		return (print_unumber(fd, va_arg(args, unsigned int), base16l, 16));
	if (c == 'X')
		return (print_unumber(fd, va_arg(args, unsigned int), base16u, 16));
	return (print_char(fd, c));
}

int	printlist(const char *format, va_list args)
{
	ssize_t	counter;

	counter = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				return ((int)counter);
			counter += print_arguments(1, *format, args);
			format++;
		}
		else
		{
			counter += print_char(1, *format);
			format++;
		}
	}
	return ((int)counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		quantuty_character;

	va_start(args, format);
	quantuty_character = printlist(format, args);
	va_end(args);
	return (quantuty_character);
}
