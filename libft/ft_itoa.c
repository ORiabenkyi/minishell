/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:20:06 by oriabenk          #+#    #+#             */
/*   Updated: 2024/10/10 14:46:00 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(int n)
{
	size_t	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ft_fillnum(char *num, int n, size_t size)
{
	size_t	counter;

	counter = 0;
	if (n < 0)
	{
		num[0] = '-';
		n = -n;
	}
	num[size] = '\0';
	counter++;
	while (counter <= size && n != 0)
	{
		num[size - counter] = ((n % 10) + '0');
		n = n / 10;
		counter++;
	}
	return (num);
}

char	*ft_itoa(int number)
{
	char	*str;
	size_t	size;

	if (number == -2147483648)
		return (ft_strdup("-2147483648"));
	if (number == 0)
		return (ft_strdup("0"));
	size = ft_size(number);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (0);
	str = ft_fillnum(str, number, size);
	return (str);
}
