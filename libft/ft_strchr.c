/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:20:06 by oriabenk          #+#    #+#             */
/*   Updated: 2024/10/11 14:39:51 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int symbol)
{
	size_t	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		if (str[counter] == (char)symbol)
			return ((char *) &str[counter]);
		counter++;
	}
	if ((char)symbol == '\0')
	{
		return ((char *) &str[counter]);
	}
	return (NULL);
}
