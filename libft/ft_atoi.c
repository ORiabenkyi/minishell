/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:20:06 by oriabenk          #+#    #+#             */
/*   Updated: 2024/10/11 11:59:20 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhitespace(int symbol)
{
	if (symbol == ' ' || symbol == '\t' || symbol == '\v')
		return (1);
	else if (symbol == '\n' || symbol == '\r' || symbol == '\f')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	long	number;
	int		negative;
	long	counter;

	number = 0;
	negative = 1;
	counter = 0;
	while (ft_iswhitespace(str[counter]))
		counter++;
	if (str[counter] == '-' || str[counter] == '+')
	{
		if (str[counter] == '-')
			negative = -1;
		counter++;
	}
	while (ft_isdigit(str[counter]) && str[counter] != '\0')
	{
		number = (number * 10) + (str[counter] - '0');
		counter++;
	}
	return (number * negative);
}
