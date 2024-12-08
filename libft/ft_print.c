/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 12:36:40 by oriabenk          #+#    #+#             */
/*   Updated: 2024/11/10 17:13:04 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

ssize_t	print_char(int fd, int c)
{
	return (write(fd, &c, 1));
}

ssize_t	print_string(int fd, const char *str)
{
	if (!str)
		return (write(fd, "(null)", 6));
	return (write(fd, str, ft_strlen(str)));
}

ssize_t	print_unumber(int fd, unsigned long num, const char *symbols,
		unsigned int base)
{
	ssize_t	written;

	written = 0;
	if (num >= base)
		written += print_unumber(fd, num / base, symbols, base);
	written += print_char(fd, symbols[num % base]);
	return (written);
}

ssize_t	print_number(int fd, long num, const char *symbols, unsigned int base)
{
	ssize_t	written;

	written = 0;
	if (num < 0)
	{
		written += print_char(fd, '-');
		num *= -1;
	}
	return (print_unumber(fd, (unsigned long)num, symbols, base) + written);
}

ssize_t	print_ptr(int fd, unsigned long p)
{
	if (!p)
		return (write(fd, "(nil)", 5));
	write(fd, "0x", 2);
	return (print_unumber(fd, p, "0123456789abcdef", 16) + 2);
}
